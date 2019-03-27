// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_string_split.h
// Description: String Splitting
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_STRING_SPLIT_H
#define ZEDKIT_STRING_SPLIT_H

#pragma once

#include <zk_config.h>
#include <vector>
#include <strings/zk_string_piece.hpp>

namespace ZedKit {

std::vector<ZkStringPiece<char>> ZkSplitString(const char *s, const char *separator);
std::vector<ZkStringPiece<char>> ZkSplitString(const char *s, size_t length, const char *separator);
#ifndef _ZK_WIDE_IS_UTF16
std::vector<ZkStringPiece<char16_t>> ZkSplitString(const char16_t *s, const char16_t *separator);
std::vector<ZkStringPiece<char16_t>> ZkSplitString(const char16_t *s, size_t length, const char16_t *separator);
#endif
std::vector<ZkStringPiece<wchar_t>> ZkSplitString(const wchar_t *s, const wchar_t *separator);
std::vector<ZkStringPiece<wchar_t>> ZkSplitString(const wchar_t *s, size_t length, const wchar_t *separator);

template <typename CharT>
inline std::vector<ZkStringPiece<CharT>> ZkSplitString(const std::basic_string<CharT> &s, const CharT *separator) {
    return ZkSplitString(s.data(), s.length(), separator);
}

#ifdef _ZK_STRING_VIEW_SUPPORTED
template <typename CharT>
inline std::vector<ZkStringPiece<CharT>> ZkSplitString(const std::basic_string_view<CharT> &s, const CharT *separator) {
    return ZkSplitString(s.data(), s.length(), separator);
}
#endif

} // namespace ZedKit

#endif // ZEDKIT_STRING_SPLIT_H
