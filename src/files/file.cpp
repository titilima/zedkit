// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: file.cpp
// Description: File Wrapper Class
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "files/zk_file.h"

namespace ZedKit {

template <class DataType>
static DataType ReadContentImpl(ZkFile::PathCStr filePath, bool *succeeded)
{
    DataType ret;

    ZkFile file;
    if (file.OpenExistingForReading(filePath))
    {
        size_t cb = file.GetSize();

        ret.resize(cb);
        const void *dst = ret.data();

        size_t read = file.Read(const_cast<void *>(dst), cb);
        assert(read == cb);

        *succeeded = true;
    }
    else if (nullptr != succeeded)
    {
        *succeeded = false;
    }

    return ret;
}

std::vector<unsigned char> ZkFile::ReadBlobContent(PathCStr filePath, bool *succeeded)
{
    return ReadContentImpl<std::vector<unsigned char>>(filePath, succeeded);
}

std::string ZkFile::ReadStringContent(PathCStr filePath, bool *succeeded)
{
    return ReadContentImpl<std::string>(filePath, succeeded);
}

bool ZkFile::WriteContent(PathCStr filePath, const void *data, size_t size)
{
    ZkFile file;
    if (!file.CreateNewForWriting(filePath))
        return false;

    size_t cb = file.Write(data, size);
    assert(cb == size);
    return true;
}

} // namespace ZedKit
