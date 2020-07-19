// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_uri.h
// Description: ZkURI Class
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_URI_H
#define ZEDKIT_URI_H

#pragma once

#include <memory>

namespace ZedKit {

class ZkURI
{
public:
    ZkURI(ZkURI &&) = default;
    ~ZkURI(void);

    static ZkURI Parse(const char *URI);

    bool HasScheme(void) const;
    std::string GetScheme(void) const;
    bool SchemeIsHTTPOrHTTPS(void) const;

    std::string GetUsername(void) const;
    std::string GetPassword(void) const;
    std::string GetHost(void) const;
    int GetPort(void) const;
    std::string GetPath(void) const;
    std::string GetQuery(void) const;
    std::string GetPathForRequest(void) const;
    std::string GetRef(void) const;
private:
    ZkURI(const char *URI);

    const std::string m_spec;

    struct Parsed;
    std::unique_ptr<Parsed> m_parsed;
};

} // namespace ZedKit

#endif // ZEDKIT_URI_H
