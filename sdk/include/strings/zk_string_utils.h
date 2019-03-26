// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_string_utils.h
// Description: String Utilities
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_STRING_UTILS_H
#define ZEDKIT_STRING_UTILS_H

#pragma once

#include <zk_config.h>
#include <strings/zk_string_piece.hpp>

namespace ZedKit {

template <class CharT>
inline bool ZkStringIsNullOrEmpty(const CharT *s) {
    return nullptr == s || '\0' == *s;
}

std::string ZkStringToASCIILower(const char *s);
std::string ZkStringToASCIILower(const char *s, size_t length);
#ifndef _ZK_WIDE_IS_UTF16
std::u16string ZkStringToASCIILower(const char16_t *s);
std::u16string ZkStringToASCIILower(const char16_t *s, size_t length);
#endif
std::wstring ZkStringToASCIILower(const wchar_t *s);
std::wstring ZkStringToASCIILower(const wchar_t *s, size_t length);

template <class CharT>
inline std::basic_string<CharT> ZkStringToASCIILower(const ZkStringPiece<CharT> &s) {
    return ZkStringToASCIILower(s.Data(), s.length());
}

std::string ZkStringToASCIIUpper(const char *s);
std::string ZkStringToASCIIUpper(const char *s, size_t length);
#ifndef _ZK_WIDE_IS_UTF16
std::u16string ZkStringToASCIIUpper(const char16_t *s);
std::u16string ZkStringToASCIIUpper(const char16_t *s, size_t length);
#endif
std::wstring ZkStringToASCIIUpper(const wchar_t *s);
std::wstring ZkStringToASCIIUpper(const wchar_t *s, size_t length);

template <class CharT>
inline std::basic_string<CharT> ZkStringToASCIIUpper(const ZkStringPiece<CharT> &s) {
    return ZkStringToASCIIUpper(s.Data(), s.length());
}

} // namespace ZedKit

#endif // ZEDKIT_STRING_UTILS_H
