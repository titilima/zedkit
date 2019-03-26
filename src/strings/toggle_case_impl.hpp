// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: toggle_case_impl.hpp
// Description: Case Toggling Implementations
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef _TOGGLE_CASE_IMPL_HPP
#define _TOGGLE_CASE_IMPL_HPP

#pragma once

namespace ZedKit {

template <typename CharT>
std::basic_string<CharT> StringToASCIILower(const CharT *s)
{
    std::basic_string<CharT> ret;
    while ('\0' != *s)
    {
        CharT ch = *s;
        if ('A' <= ch && ch <= 'Z')
            ch += 'a' - 'A';
        ret.push_back(ch);
        ++s;
    }
    return ret;
}

template <typename CharT>
std::basic_string<CharT> StringToASCIILower(const CharT *s, size_t length)
{
    std::basic_string<CharT> ret;
    for (size_t i = 0; i < length; ++i)
    {
        CharT ch = *s;
        if ('A' <= ch && ch <= 'Z')
            ch += 'a' - 'A';
        ret.push_back(ch);
        ++s;
    }
    return ret;
}

template <typename CharT>
std::basic_string<CharT> StringToASCIIUpper(const CharT *s)
{
    std::basic_string<CharT> ret;
    while ('\0' != *s)
    {
        CharT ch = *s;
        if ('a' <= ch && ch <= 'z')
            ch -= 'a' - 'A';
        ret.push_back(ch);
        ++s;
    }
    return ret;
}

template <typename CharT>
std::basic_string<CharT> StringToASCIIUpper(const CharT *s, size_t length)
{
    std::basic_string<CharT> ret;
    for (size_t i = 0; i < length; ++i)
    {
        CharT ch = *s;
        if ('a' <= ch && ch <= 'z')
            ch -= 'a' - 'A';
        ret.push_back(ch);
        ++s;
    }
    return ret;
}

} // namespace ZedKit

#endif // _TOGGLE_CASE_IMPL_HPP
