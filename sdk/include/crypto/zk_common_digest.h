// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_common_digest.h
// Description: ZedKit Common Digest Algorithms
//      Author: Ziming Li
//     Created: 2017-04-24
// -------------------------------------------------
// Copyright (C) 2017 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_COMMON_DIGEST_H
#define ZEDKIT_COMMON_DIGEST_H

#pragma once

#include <zk_config.h>
#include <string>
#if defined(_WIN32)
#   include <Windows.h>
#   include <WinCrypt.h>
#else
#   error Not implemented!
#endif

namespace ZedKit {

class ZkMD5
{
public:
    ZkMD5(void);
    ~ZkMD5(void);
    static const size_t LEN = 16;

    void Update(const void *data, size_t size);
    void Final(unsigned char dst[LEN]);

    static void Hash(unsigned char dst[LEN], const void *data, size_t size);

    static std::string HashToString(const void *data, size_t size, bool upperCase);
#ifndef _ZK_WIDE_IS_UTF16
    static std::u16string HashToString16(const void *data, size_t size, bool upperCase);
#endif
    static std::wstring HashToWideString(const void *data, size_t size, bool upperCase);
private:
#if defined(_WIN32)
    HCRYPTPROV m_prov = 0;
    HCRYPTHASH m_hash = 0;
#else
#   error Not implemented!
#endif
};

} // namespace ZedKit

#endif // #define ZEDKIT_COMMON_DIGEST_H
