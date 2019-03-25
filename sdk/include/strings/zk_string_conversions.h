// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_string_conversions.h
// Description: String Conversions
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_STRING_CONVERSIONS_H
#define ZEDKIT_STRING_CONVERSIONS_H

#pragma once

#include <zk_config.h>

#include <string>
#ifdef _ZK_STRING_VIEW_SUPPORTED
#   include <string_view>
#endif

#ifdef _WIN32
#   include <Windows.h>
#endif

namespace ZedKit {

#ifdef _WIN32

std::wstring ZkMultiByteToWideString(PCSTR ps, size_t length, UINT codePage = CP_ACP);

template <class StringType>
inline std::wstring ZkMultiByteToWideString(const StringType &s, UINT codePage = CP_ACP) {
    return ZkMultiByteToWideString(s.data(), s.length(), codePage);
}

std::string ZkWideStringToMultiByte(PCWSTR pws, size_t length, UINT codePage = CP_ACP);

template <class StringType>
inline std::string ZkWideStringToMultiByte(const StringType &s, UINT codePage = CP_ACP) {
    return ZkWideStringToMultiByte(s.data(), s.length(), codePage);
}

#endif // _WIN32

} // namespace ZedKit

#endif // ZEDKIT_STRING_CONVERSIONS_H
