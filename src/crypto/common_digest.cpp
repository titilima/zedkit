// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: common_digest.cpp
// Description: ZedKit Common Digest Algorithms
//      Author: Ziming Li
//     Created: 2017-04-24
// -------------------------------------------------
// Copyright (C) 2017 MingYang Software Technology.
// -------------------------------------------------

#include "crypto/zk_common_digest.h"

namespace ZedKit {

/**
 * Common Util(s) for All Algorithms
 */

template <typename CharT>
static std::basic_string<CharT> HashToStringImpl(const unsigned char *hash, size_t len, bool upperCase)
{
    std::basic_string<CharT> ret;

    char a = upperCase ? 'A' : 'a';

    ret.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        unsigned char b = hash[i];

        unsigned char b1 = (b & 0xf0) >> 4;
        if (b1 < 10)
            ret.push_back(b1 + '0');
        else
            ret.push_back(b1 - 10 + a);

        unsigned char b2 = (b & 0x0f);
        if (b2 < 10)
            ret.push_back(b2 + '0');
        else
            ret.push_back(b2 - 10 + a);
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MD5

void ZkMD5::Hash(unsigned char dst[], const void *data, size_t size)
{
    ZkMD5 md5;
    md5.Update(data, size);
    md5.Final(dst);
}

std::string ZkMD5::HashToString(const void *data, size_t size, bool upperCase)
{
    unsigned char hash[ZkMD5::LEN];
    Hash(hash, data, size);
    return HashToStringImpl<char>(hash, ZkMD5::LEN, upperCase);
}

#ifndef _ZK_WIDE_IS_UTF16
std::u16string ZkMD5::HashToString16(const void *data, size_t size, bool upperCase)
{
    unsigned char hash[ZkMD5::LEN];
    Hash(hash, data, size);
    return HashToStringImpl<char16_t>(hash, ZkMD5::LEN, upperCase);
}
#endif

std::wstring ZkMD5::HashToWideString(const void *data, size_t size, bool upperCase)
{
    unsigned char hash[ZkMD5::LEN];
    Hash(hash, data, size);
    return HashToStringImpl<wchar_t>(hash, ZkMD5::LEN, upperCase);
}

} // namespace ZedKit
