// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: string_printf_impl.hpp
// Description: StringPrintF Implementation
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef _STRING_PRINTF_IMPL_HPP
#define _STRING_PRINTF_IMPL_HPP

#pragma once

#include <cstdarg>

namespace ZedKit {

template <typename CharT>
struct StringPrintfTrait {
    static int Impl(CharT *dst, size_t size, const CharT *format, va_list args);
};

template <>
struct StringPrintfTrait<char> {
    static int Impl(char *dst, size_t size, const char *format, va_list args) {
        return vsprintf_s(dst, size, format, args);
    }
};

template <typename CharT>
std::basic_string<CharT> StringPrintfImpl(const CharT *format, va_list args)
{
    static const size_t InitialBufSize = 1024;
    static const size_t MaximumBufSize = 1024 * 1024;

    CharT buf[InitialBufSize];

    va_list args2;
    va_copy(args2, args);
    int n = StringPrintfTrait<CharT>::Impl(buf, InitialBufSize, format, args2);
    va_end(args2);
    if (0 <= n && n < InitialBufSize)
        return std::basic_string<CharT>(buf, n);

    size_t size = InitialBufSize * 2;

    std::basic_string<CharT> ret('\0', size);
    while (size < MaximumBufSize)
    {
        va_copy(args2, args);
        n = StringPrintfTrait<CharT>::Impl(const_cast<CharT *>(ret.data()), ret.length(), format, args2);
        va_end(args2);
        if (0 <= n && n < static_cast<int>(size))
        {
            ret.resize(n);
            return ret;
        }

        size *= 2;
    }

    assert(false); // String is too long!
    ret.clear();
    return ret;
}

} // namespace ZedKit

#endif // _STRING_PRINTF_IMPL_HPP
