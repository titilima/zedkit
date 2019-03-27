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

#include <strings/zk_string_piece.hpp>
#ifdef _WIN32
#   include <Windows.h>
#endif

namespace ZedKit {

#ifdef _WIN32

std::wstring ZkMultiByteToWideString(PCSTR ps, size_t length, UINT codePage);

inline std::wstring ZkMultiByteToWideString(const ZkStringPiece<char> &s, UINT codePage) {
    return ZkMultiByteToWideString(s.Data(), s.Length(), codePage);
}

std::string ZkWideStringToMultiByte(PCWSTR pws, size_t length, UINT codePage);

inline std::string ZkWideStringToMultiByte(const ZkStringPiece<wchar_t> &s, UINT codePage) {
    return ZkWideStringToMultiByte(s.Data(), s.Length(), codePage);
}

#endif // _WIN32

} // namespace ZedKit

#endif // ZEDKIT_STRING_CONVERSIONS_H
