// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: http_codecs.cpp
// Description: Encoders & Decoders for HTTP
//      Author: Ziming Li
//     Created: 2019-03-27
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "net/zk_http_codecs.h"

#include <cctype>

namespace ZedKit {

static char DecodeHexChar(const char *s)
{
    char ch;
    try
    {
        char hex[3] = { 0 };
        hex[0] = s[1];
        hex[1] = s[2];
        ch = std::stoi(hex, nullptr, 16);
    }
    catch (...)
    {
        ch = '?';
    }
    return ch;
}

std::string ZkURLDecode(const char *s)
{
    std::string ret;
    while ('\0' != *s)
    {
        char ch = *s;

        if ('%' == ch)
        {
            if ('\0' == s[1] || '\0' == s[2])
            {
                ret.push_back('?');
                break;
            }
            ch = DecodeHexChar(s);

            s += 2;
        }
        else if ('+' == ch)
        {
            ch = ' ';
        }

        ret.push_back(ch);
        ++s;
    }

    return ret;
}

std::string ZkURLDecode(const char *s, size_t length)
{
    std::string ret;

    for (size_t i = 0; i < length; ++i)
    {
        char ch = *s;

        if ('%' == ch)
        {
            if (i + 3 >= length)
            {
                ret.push_back('?');
                break;
            }
            try
            {
                char hex[3] = { 0 };
                hex[0] = s[1];
                hex[1] = s[2];
                ch = atoi(hex);
            }
            catch (...)
            {
                ch = '?';
            }

            i += 2;
            s += 2;
        }
        else if ('+' == ch)
        {
            ch = ' ';
        }

        ret.push_back(ch);
        ++s;
    }

    return ret;
}

static void AppendEncoded(std::string &s, char ch)
{
    static const char SpecialChars[] = "-_.!~*'()";

    static const char HexDigits[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    if (isalnum(ch) || nullptr != strchr(SpecialChars, ch))
    {
        s.push_back(ch);
    }
    else if (' ' == ch)
    {
        s.push_back('+');
    }
    else
    {
        unsigned char b = static_cast<unsigned char>(ch);
        s.push_back('%');
        s.push_back(HexDigits[(b >> 4)]);
        s.push_back(HexDigits[(b & 0xf)]);
    }
}

std::string ZkURLEncode(const char *s)
{
    std::string ret;
    while ('\0' != *s)
    {
        AppendEncoded(ret, *s);
        ++s;
    }
    return ret;
}

std::string ZkURLEncode(const char *s, size_t length)
{
    std::string ret;
    for (size_t i = 0; i < length; ++i)
    {
        AppendEncoded(ret, *s);
        ++s;
    }
    return ret;
}

} // namespace ZedKit
