// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_http_codecs.h
// Description: Encoders & Decoders for HTTP
//      Author: Ziming Li
//     Created: 2019-03-27
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_HTTP_CODECS_H
#define ZEDKIT_HTTP_CODECS_H

#pragma once

#include <string>

namespace ZedKit {

std::string ZkURLEncode(const char *s);
std::string ZkURLEncode(const char *s, size_t length);

template <class StringType>
inline std::string ZkURLEncode(const StringType &s) {
    return ZkURLEncode(s.data(), s.length());
}

std::string ZkURLDecode(const char *s);
std::string ZkURLDecode(const char *s, size_t length);

template <class StringType>
inline std::string ZkURLDecode(const StringType &s) {
    return ZkURLDecode(s.data(), s.length());
}

class ZkQueryCodec
{
public:
    template <class ContainerType>
    static std::string Encode(const ContainerType &queryData) {
        std::string ret;
        for (const auto &pair : queryData)
        {
            ret.append(pair.first);
            ret.push_back('=');
            ret.append(ZkURLEncode(pair.second));
            ret.push_back('&');
        }
        if (!ret.empty())
            ret.pop_back();
        return ret;
    }
};

} // namespace ZedKit

#endif // ZEDKIT_HTTP_CODECS_H
