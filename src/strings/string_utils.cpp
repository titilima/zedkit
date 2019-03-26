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

#include "strings/string_utils_impl.hpp"

namespace ZedKit {

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

} // namespace ZedKit
