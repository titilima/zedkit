// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: split_impl.hpp
// Description: Splitting Implementations
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef _SPLIT_IMPL_HPP
#define _SPLIT_IMPL_HPP

#pragma once

#include <vector>
#include "strings/zk_string_piece.hpp"
#include "strings/trim_impl.hpp"

namespace ZedKit {

template <typename CharT>
std::vector<ZkStringPiece<CharT>> SplitString(const std::basic_string_view<CharT> &s, const CharT *separator)
{
    std::vector<ZkStringPiece<CharT>> ret;

    size_t begin = 0;
    size_t end = s.find(separator, begin);
    while (std::basic_string_view<CharT>::npos != end)
    {
        ZkStringPiece<CharT> tmp = TrimString(std::basic_string_view<CharT>(s.data() + begin, end - begin));
        if (!tmp.IsEmpty())
            ret.push_back(tmp);

        begin = end + 1;
        end = s.find(separator, begin);
    }

    if (begin < s.length())
    {
        ZkStringPiece<CharT> tmp = TrimString(std::basic_string_view<CharT>(s.data() + begin, s.length() - begin));
        if (!tmp.IsEmpty())
            ret.push_back(tmp);
    }
    return ret;
}

} // namespace ZedKit

#endif // _SPLIT_IMPL_HPP
