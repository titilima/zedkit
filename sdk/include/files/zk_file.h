// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_file.h
// Description: File Wrapper Class
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_FILE_H
#define ZEDKIT_FILE_H

#pragma once

#include <zk_config.h>

#ifdef _ZK_STRING_VIEW_SUPPORTED
#   include <string_view>
#endif
#include <vector>

#ifdef _WIN32
#   include <Windows.h>
#endif

namespace ZedKit {

class ZkFile
{
public:
    ~ZkFile(void);

#ifdef _WIN32
    typedef PCWSTR PathCStr;
#else
    typedef const char *PathCStr;
#endif

    operator bool() const;

    bool CreateNewForWriting(PathCStr filePath);
    bool OpenExistingForReading(PathCStr filePath);

    size_t GetSize(void) const;
    uint64_t GetSize64(void) const;
    size_t Read(void *dst, size_t size) const;
    size_t Write(const void *data, size_t size);

    static std::vector<unsigned char> ReadBlobContent(PathCStr filePath, bool *succeeded = nullptr);
    static std::string ReadStringContent(PathCStr filePath, bool *succeeded = nullptr);

    static bool WriteContent(PathCStr filePath, const void *data, size_t size);
    template <class DataType>
    inline static bool WriteContent(PathCStr filePath, const DataType &data) {
        return WriteContent(filePath, data.data(), data.size());
    }
private:
#ifdef _WIN32
    HANDLE m_file = INVALID_HANDLE_VALUE;
#else
    FILE *m_file = nullptr;
#endif
};

} // namespace ZedKit

#endif // ZEDKIT_FILE_H
