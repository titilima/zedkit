// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: compare_impl.hpp
// Description: String Comparation Implementations
//      Author: Ziming Li
//     Created: 2019-03-27
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef _COMPARE_IMPL_HPP
#define _COMPARE_IMPL_HPP

#pragma once

#include "strings/zk_string_piece.hpp"

namespace ZedKit {

template <typename CharT>
int CompareIgnoreCase(const ZkStringPiece<CharT> &s1, const CharT *s2)
{
    const CharT *p = s1.Data();
    for (size_t i = 0; i < s1.Length(); ++i)
    {
        CharT c1 = *p;
        CharT c2 = *s2;
        if (c1 != c2)
        {
            if (isalpha(c1) && isalpha(c2))
            {
                if ('A' <= c1 && c1 <= 'Z')
                    c1 += 'a' - 'A';
                if ('A' <= c2 && c2 <= 'Z')
                    c2 += 'a' - 'A';
            }

            if (c1 > c2)
                return 1;
            if (c1 < c2)
                return -1;
        }

        ++p; ++s2;
    }
    return 0;
}

} // namespace ZedKit

#endif // _COMPARE_IMPL_HPP
