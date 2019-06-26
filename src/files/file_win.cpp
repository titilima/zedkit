// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: file_win.cpp
// Description: File Wrapper Class
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "files/zk_file.h"

namespace ZedKit {

static HANDLE CreateFile(PCWSTR fileName, DWORD desiredAccess, DWORD creationDisposition, DWORD flagsAndAttributes)
{
    return ::CreateFileW(fileName, desiredAccess, FILE_SHARE_READ, nullptr, creationDisposition,
        flagsAndAttributes, nullptr);
}

ZkFile::~ZkFile(void)
{
    if (INVALID_HANDLE_VALUE != m_file)
    {
        ::CloseHandle(m_file);
        m_file = INVALID_HANDLE_VALUE;
    }
}

ZkFile::operator bool() const
{
    return INVALID_HANDLE_VALUE != m_file;
}

bool ZkFile::CreateNewForWriting(PathCStr filePath)
{
    assert(INVALID_HANDLE_VALUE == m_file);
    m_file = CreateFile(filePath, GENERIC_WRITE, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE);
    return INVALID_HANDLE_VALUE != m_file;
}

size_t ZkFile::GetSize(void) const
{
    assert(INVALID_HANDLE_VALUE != m_file);

    DWORD highPart = 0;
    DWORD lowPart = ::GetFileSize(m_file, &highPart);
#ifdef _WIN64
    return lowPart | (highPart << 32);
#else
    assert(0 == highPart);
    return lowPart;
#endif
}

uint64_t ZkFile::GetSize64(void) const
{
    assert(INVALID_HANDLE_VALUE != m_file);

    DWORD highPart = 0;
    DWORD lowPart = ::GetFileSize(m_file, &highPart);

    uint64_t ret = highPart;
    ret <<= 32;
    ret |= lowPart;
    return ret;
}

bool ZkFile::OpenExistingForReading(PathCStr filePath)
{
    assert(INVALID_HANDLE_VALUE == m_file);
    m_file = CreateFile(filePath, GENERIC_READ, OPEN_EXISTING, 0);
    return INVALID_HANDLE_VALUE != m_file;
}

size_t ZkFile::Read(void *dst, size_t cb) const
{
    assert(INVALID_HANDLE_VALUE != m_file);
    DWORD dwRead = 0;
    ::ReadFile(m_file, dst, cb, &dwRead, nullptr);
    return dwRead;
}

size_t ZkFile::Write(const void *data, size_t cb)
{
    assert(INVALID_HANDLE_VALUE != m_file);
    DWORD dwWritten = 0;
    ::WriteFile(m_file, data, cb, &dwWritten, nullptr);
    return dwWritten;
}

} // namespace ZedKit
