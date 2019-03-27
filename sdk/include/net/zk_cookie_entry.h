// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_cookie_entry.h
// Description: ZkCookieEntry Class
//      Author: Ziming Li
//     Created: 2019-03-27
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_COOKIE_ENTRY_H
#define ZEDKIT_COOKIE_ENTRY_H

#pragma once

#include <string>
#include <vector>
#include <utility>

namespace ZedKit {

class ZkCookieEntry
{
public:
    ZkCookieEntry(ZkCookieEntry &&) = default;

    static ZkCookieEntry Parse(const char *cookieLine);

    typedef std::vector<std::pair<std::string, std::string>> PairList;
    const PairList& Pairs(void) const { return m_pairs; }

    const std::string& Expires(void) const { return m_expires; }
    const std::string& MaxAge(void) const { return m_maxAge; }
    const std::string& Domain(void) const { return m_domain; }
    const std::string& Path(void) const { return m_path; }
    bool IsSecure(void) const { return m_secure; }
    bool IsHTTPOnly(void) const { return m_httpOnly; }
private:
    ZkCookieEntry(void) = default;

    PairList m_pairs;
    std::string m_expires, m_maxAge, m_domain, m_path;
    bool m_secure = false, m_httpOnly = false;
};

} // namespace ZedKit

#endif // ZEDKIT_COOKIE_ENTRY_H
