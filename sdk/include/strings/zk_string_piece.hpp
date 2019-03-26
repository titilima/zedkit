// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_string_piece.hpp
// Description: String Piece Adaptor
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_STRING_PIECE_HPP
#define ZEDKIT_STRING_PIECE_HPP

#pragma once

#include <zk_config.h>

#include <string>
#ifdef _ZK_STRING_VIEW_SUPPORTED
#   include <string_view>
#endif

namespace ZedKit {

template <typename CharT>
class ZkStringPiece
{
public:
    explicit ZkStringPiece(const CharT *s) : m_data(s), m_length(Length(s)) {}
    ZkStringPiece(const std::basic_string<CharT> &s) : m_data(s.data()), m_length(s.length()) {}
#ifdef _ZK_STRING_VIEW_SUPPORTED
    ZkStringPiece(const std::basic_string_view<CharT> &s) : m_data(s.data()), m_length(s.length()) {}
#endif

    const CharT* Data(void) const { return m_data; }
    size_t Length(void) const { return m_length; }
private:
    static size_t Length(const CharT *s) {
        const CharT *p = s;
        while ('\0' != *p)
            ++p;
        return p - s;
    }

    const CharT *m_data;
    const size_t m_length;
};

} // namespace ZedKit

#endif // ZEDKIT_STRING_PIECE_HPP
