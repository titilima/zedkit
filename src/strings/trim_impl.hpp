// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: trim_impl.hpp
// Description: Trimming Implementations
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef _TRIM_IMPL_HPP
#define _TRIM_IMPL_HPP

#pragma once

#include "strings/zk_string_piece.hpp"

namespace ZedKit {

template <typename CharT>
ZkStringPiece<CharT> TrimString(const std::basic_string_view<CharT> &s)
{
    static const CharT whitespaces[] = { ' ', '\t', '\n', '\r', '\f', '\b', '\0' };

    size_t p = s.find_first_not_of(whitespaces);
    if (std::basic_string_view<CharT>::npos == p)
        return ZkStringPiece<CharT>(s.data() + s.length(), 0);

    size_t q = s.find_last_not_of(whitespaces);
    return ZkStringPiece<CharT>(s.data() + p, q - p + 1);
}

} // namespace ZedKit

#endif // _TRIM_IMPL_HPP
