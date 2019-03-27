// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: string_utils.cpp
// Description: String Utilities
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "strings/zk_string_utils.h"

#include "strings/compare_impl.hpp"
#include "strings/toggle_case_impl.hpp"
#include "strings/trim_impl.hpp"

namespace ZedKit {

int ZkStringCompareIgnoreCase(const ZkStringPiece<char> &s1, const char *s2)
{
    return CompareIgnoreCase(s1, s2);
}

#ifndef _ZK_WIDE_IS_UTF16

int ZkStringCompareIgnoreCase(const ZkStringPiece<char16_t> &s1, const char16_t *s2)
{
    return CompareIgnoreCase(s1, s2);
}

#endif

int ZkStringCompareIgnoreCase(const ZkStringPiece<wchar_t> &s1, const wchar_t *s2)
{
    return CompareIgnoreCase(s1, s2);
}

std::string ZkStringToASCIILower(const char *s)
{
    return StringToASCIILower(s);
}

std::string ZkStringToASCIILower(const char *s, size_t length)
{
    return StringToASCIILower(s, length);
}

#ifndef _ZK_WIDE_IS_UTF16

std::u16string ZkStringToASCIILower(const char16_t *s)
{
    return StringToASCIILower(s);
}

std::u16string ZkStringToASCIILower(const char16_t *s, size_t length)
{
    return StringToASCIILower(s, length);
}

#endif // _ZK_WIDE_IS_UTF16

std::wstring ZkStringToASCIILower(const wchar_t *s)
{
    return StringToASCIILower(s);
}

std::wstring ZkStringToASCIILower(const wchar_t *s, size_t length)
{
    return StringToASCIILower(s, length);
}

std::string ZkStringToASCIIUpper(const char *s)
{
    return StringToASCIIUpper(s);
}

std::string ZkStringToASCIIUpper(const char *s, size_t length)
{
    return StringToASCIIUpper(s, length);
}

#ifndef _ZK_WIDE_IS_UTF16

std::u16string ZkStringToASCIIUpper(const char16_t *s)
{
    return ZkStringToASCIIUpper(s);
}

std::u16string ZkStringToASCIILower(const char16_t *s, size_t length)
{
    return ZkStringToASCIIUpper(s, length);
}

#endif // _ZK_WIDE_IS_UTF16

std::wstring ZkStringToASCIIUpper(const wchar_t *s)
{
    return StringToASCIIUpper(s);
}

std::wstring ZkStringToASCIIUpper(const wchar_t *s, size_t length)
{
    return StringToASCIIUpper(s, length);
}

ZkStringPiece<char> ZkTrimString(const char *s)
{
    return TrimString(std::string_view(s));
}

ZkStringPiece<char> ZkTrimString(const char *s, size_t length)
{
    return TrimString(std::string_view(s, length));
}

#ifndef _ZK_WIDE_IS_UTF16

ZkStringPiece<char16_t> ZkTrimString(const char16_t *s)
{
    return TrimString(std::u16string_view(s));
}

ZkStringPiece<char16_t> ZkTrimString(const char16_t *s, size_t length)
{
    return TrimString(std::u16string_view(s, length));
}

#endif

ZkStringPiece<wchar_t> ZkTrimString(const wchar_t *s)
{
    return TrimString(std::wstring_view(s));
}

ZkStringPiece<wchar_t> ZkTrimString(const wchar_t *s, size_t length)
{
    return TrimString(std::wstring_view(s, length));
}

} // namespace ZedKit
