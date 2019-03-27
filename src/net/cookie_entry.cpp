// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: cookie_entry.cpp
// Description: ZkCookieEntry Class
//      Author: Ziming Li
//     Created: 2019-03-27
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "net/zk_cookie_entry.h"

#include "strings/zk_string_split.h"
#include "strings/zk_string_utils.h"

namespace ZedKit {

ZkCookieEntry ZkCookieEntry::Parse(const char *cookieLine)
{
    ZkCookieEntry ret;

    std::vector<ZkStringPiece<char>> parts = ZkSplitString(cookieLine, ";");
    for (size_t i = 0; i < parts.size(); ++i)
    {
        std::string s = parts.at(i).ToString();

        size_t p = s.find('=');
        if (std::string_view::npos != p)
        {
            std::string k = s.substr(0, p);
            std::string v = s.substr(p + 1);
            if (0 == ZkStringCompareIgnoreCase(k, "expires"))
                ret.m_expires = v;
            else if (0 == ZkStringCompareIgnoreCase(k, "max-age"))
                ret.m_maxAge = v;
            else if (0 == ZkStringCompareIgnoreCase(k, "domain"))
                ret.m_domain = v;
            else if (0 == ZkStringCompareIgnoreCase(k, "path"))
                ret.m_path = v;
            else
                ret.m_pairs.push_back(std::make_pair(k, v));
        }
        else
        {
            if (0 == ZkStringCompareIgnoreCase(s, "secure"))
                ret.m_secure = true;
            else if (0 == ZkStringCompareIgnoreCase(s, "httponly"))
                ret.m_httpOnly = true;
        }
    }

    return ret;
}

} // namespace ZedKit
