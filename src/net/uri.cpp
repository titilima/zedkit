// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: uri.cpp
// Description: ZkURI Class
//      Author: Ziming Li
//     Created: 2019-03-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "net/zk_uri.h"

#include <string_view>

namespace ZedKit {

struct Part {
    size_t start = 0;
    size_t length = 0;
};

struct ZkURI::Parsed {
    Part scheme;
    Part username;
    Part password;
    Part host;
    int port = 0;
    Part path;
    Part query;
    Part ref;
};

static const char* ExtractScheme(const char *URI, Part &scheme)
{
    const char *p = strchr(URI, ':');
    if (nullptr == p)
        return nullptr;

    scheme.start = 0;
    scheme.length = p - URI;
    return p + 1;
}

static const char* ExtractAuthorityPart(const char *p, std::string_view &authority)
{
    const char *q = p;
    if ('/' != *q)
        return p;

    ++q;
    if ('/' != *q)
        return p;

    p += 2;
    q = strchr(p, '/');
    if (nullptr == q)
        authority = std::string_view(p);
    else
        authority = std::string_view(p, q - p);
    return p + authority.length();
}

static void ExtractUserParts(size_t offset, const std::string_view &userInformation, Part &username, Part &password)
{
    username.start = offset;

    size_t p = userInformation.find(':');
    if (std::string_view::npos != p)
    {
        username.length = p;

        password.start = offset + p + 1;
        password.length = userInformation.length() - p - 1;
    }
    else
    {
        username.length = userInformation.length();
    }
}

static void ExtractHostAndPort(size_t offset, const std::string_view &hostAndPort, Part &host, int &port)
{
    host.start = offset;

    size_t p = hostAndPort.find(':');
    if (std::string_view::npos != p)
    {
        host.length = p;
        try
        {
            std::string_view portPart = hostAndPort.substr(p + 1);
            port = std::stoi(std::string(portPart.data(), portPart.length()));
        }
        catch (...)
        {
            assert(false); // Invalid port format!
        }
    }
    else
    {
        host.length = hostAndPort.length();
    }
}

static void ExtractPathStuff(size_t offset, const std::string_view &pathStuff, Part &path, Part &query, Part &ref)
{
    path.start = offset;

    size_t p = pathStuff.find('?');
    if (std::string_view::npos != p)
    {
        path.length = p;

        query.start = offset + p + 1;

        size_t q = pathStuff.find('#', p + 1);
        if (std::string_view::npos != q)
        {
            query.length = q - p - 1;
            ref.start = offset + q + 1;
            ref.length = pathStuff.length() - q - 1;
        }
        else
        {
            query.length = pathStuff.length() - p - 1;
        }
    }
    else
    {
        size_t q = pathStuff.find('#');
        if (std::string_view::npos != q)
        {
            path.length = q - p - 1;
            ref.start = offset + q + 1;
            ref.length = pathStuff.length() - q - 1;
        }
        else
        {
            path.length = pathStuff.length();
        }
    }
}

static int GetDefaultPort(const std::string &scheme)
{
    if (scheme == "http")
        return 80;
    if (scheme == "https")
        return 443;
    return 0;
}

ZkURI::ZkURI(const char *URI) : m_spec(URI), m_parsed(std::make_unique<Parsed>())
{
    // Nothing
}

ZkURI::~ZkURI(void)
{
    // Nothing
}

std::string ZkURI::GetHost(void) const
{
    std::string ret;
    const Part &part = m_parsed->host;
    if (0 != part.length)
        ret = m_spec.substr(part.start, part.length);
    return ret;
}

std::string ZkURI::GetPassword(void) const
{
    std::string ret;
    const Part &part = m_parsed->password;
    if (0 != part.length)
        ret = m_spec.substr(part.start, part.length);
    return ret;
}

std::string ZkURI::GetPath(void) const
{
    std::string ret;
    const Part &part = m_parsed->path;
    if (0 != part.length)
        ret = m_spec.substr(part.start, part.length);
    return ret;
}

std::string ZkURI::GetPathForRequest(void) const
{
    if (0 == m_parsed->path.length)
        return std::string(1, '/');

    std::string ret = GetPath();
    if (0 != m_parsed->query.length)
    {
        ret.push_back('?');
        ret.append(GetQuery());
    }
    return ret;
}

int ZkURI::GetPort(void) const
{
    return m_parsed->port;
}

std::string ZkURI::GetQuery(void) const
{
    std::string ret;
    const Part &part = m_parsed->query;
    if (0 != part.length)
        ret = m_spec.substr(part.start, part.length);
    return ret;
}

std::string ZkURI::GetRef(void) const
{
    std::string ret;
    const Part &part = m_parsed->ref;
    if (0 != part.length)
        ret = m_spec.substr(part.start, part.length);
    return ret;
}

std::string ZkURI::GetScheme(void) const
{
    std::string ret;
    const Part &part = m_parsed->scheme;
    if (0 != part.length)
        ret = m_spec.substr(part.start, part.length);
    return ret;
}

std::string ZkURI::GetUsername(void) const
{
    std::string ret;
    const Part &part = m_parsed->username;
    if (0 != part.length)
        ret = m_spec.substr(part.start, part.length);
    return ret;
}

ZkURI ZkURI::Parse(const char *URI)
{
    ZkURI ret(URI);
    do {
        Parsed &parsed = *ret.m_parsed;

        const char *p = ExtractScheme(URI, parsed.scheme);
        if (nullptr == p)
            break;

        std::string_view authority;
        p = ExtractAuthorityPart(p, authority);
        if (!authority.empty())
        {
            std::string_view hostAndPort;

            size_t n = authority.find('@');
            if (std::string_view::npos != n)
            {
                size_t offset = authority.data() - URI;
                std::string_view userInformation = authority.substr(0, n);
                ExtractUserParts(offset, userInformation, parsed.username, parsed.password);

                hostAndPort = authority.substr(n + 1);
            }
            else
            {
                hostAndPort = authority;
            }

            size_t offset = hostAndPort.data() - URI;
            ExtractHostAndPort(offset, hostAndPort, parsed.host, parsed.port);
            if (0 == parsed.port)
                parsed.port = GetDefaultPort(ret.GetScheme());
        }

        if ('\0' != *p)
            ExtractPathStuff(p - URI, std::string_view(p), parsed.path, parsed.query, parsed.ref);

    } while (false);
    return ret;
}

} // namespace ZedKit
