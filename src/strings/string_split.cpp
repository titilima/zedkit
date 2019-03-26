// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: string_split.cpp
// Description: String Splitting
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "strings/zk_string_split.h"

#include "strings/split_impl.hpp"

namespace ZedKit {

std::vector<ZkStringPiece<char>> ZkSplitString(const char *s, const char *separator)
{
    return SplitString(std::string_view(s), separator);
}

std::vector<ZkStringPiece<char>> ZkSplitString(const char *s, size_t length, const char *separator)
{
    return SplitString(std::string_view(s, length), separator);
}

#ifndef _ZK_WIDE_IS_UTF16

std::vector<ZkStringPiece<char16_t>> ZkSplitString(const char16_t *s, const char16_t *separator)
{
    return SplitString(std::u16string_view(s), separator);
}

std::vector<ZkStringPiece<char16_t>> ZkSplitString(const char16_t *s, size_t length, const char16_t *separator)
{
    return SplitString(std::u16string_view(s, length), separator);
}

#endif

std::vector<ZkStringPiece<wchar_t>> ZkSplitString(const wchar_t *s, const wchar_t *separator)
{
    return SplitString(std::wstring_view(s), separator);
}

std::vector<ZkStringPiece<wchar_t>> ZkSplitString(const wchar_t *s, size_t length, const wchar_t *separator)
{
    return SplitString(std::wstring_view(s), separator);
}

} // namespace ZedKit
