// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_arg_parser.h
// Description: Argument Parser for Command Line Strings
//      Author: Ziming Li
//     Created: 2019-06-23
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_ARG_PARSER_H
#define ZEDKIT_ARG_PARSER_H

#pragma once

#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

namespace ZedKit {

template <typename CharT>
class ZkArgParserImpl
{
public:
    typedef std::basic_string<CharT> StringType;
    typedef std::vector<StringType> ArgumentList;
    typedef std::unordered_map<StringType, StringType> SwitchMap;

    void ParseFromMain(int argc, CharT *argv[])
    {
        Context ctx;
        m_selfName = argv[0];
        for (int i = 1; i < argc; ++i)
            ParseArgument<ZkArgParserImpl>(ctx, argv[i]);
    }

    const StringType& SelfName(void) const { return m_selfName; }
    const ArgumentList& Arguments(void) const { return m_arguments; }

    bool HasSwitch(const CharT *name) const
    {
        auto it = m_switches.find(name);
        return std::end(m_switches) != it;
    }
    StringType GetSwitchValue(const CharT *name, const StringType &defaultValue = StringType()) const
    {
        auto it = m_switches.find(name);
        return std::end(m_switches) != it ? it->second : defaultValue;
    }
protected:
    ZkArgParserImpl(void) = default;

    void Setup(const CharT *optionPrefix, const CharT *optionKeySplitter)
    {
        assert(m_optionPrefix.empty() && m_optionKeySplitter.empty());
        m_optionPrefix = optionPrefix;
        m_optionKeySplitter = optionKeySplitter;
    }

    template <class T, typename Context>
    void ParseArgument(Context &ctx, const CharT *arg)
    {
        assert(!m_optionPrefix.empty() && !m_optionKeySplitter.empty());

        T *pT = static_cast<T *>(this);
        if (pT->PreProcessArgument(ctx, arg))
            return;

        StringType s(arg);
        const size_t l = m_optionPrefix.length();
        if (0 != s.compare(0, l, m_optionPrefix))
        {
            m_arguments.push_back(arg);
            return;
        }

        size_t p = s.find(m_optionKeySplitter, l);
        if (StringType::npos == p)
        {
            s = s.substr(l);
            m_switches[s] = std::string();
        }
        else
        {
            StringType k = s.substr(l, p - l);
            m_switches[k] = s.substr(p + 1);
        }
    }

    template <typename Context>
    bool PreProcessArgument(Context &ctx, const CharT *arg)
    {
        return false;
    }

    StringType m_selfName;
    ArgumentList m_arguments;
    SwitchMap m_switches;
private:
    struct Context {};
    StringType m_optionPrefix, m_optionKeySplitter;
};

template <typename CharT>
class ZkDOSArgParserImpl : public ZkArgParserImpl<CharT>
{
public:
    ZkDOSArgParserImpl(void)
    {
        static const CharT OptionPrefix[] = { '/', '\0' };
        static const CharT OptionKeySplitter = { ':', '\0' };
        Setup(OptionPrefix, OptionKeySplitter);
    }
};

class ZkPOSIXArgParser : public ZkArgParserImpl<char>
{
public:
    ZkPOSIXArgParser(void);
};

} // namespace ZedKit

#endif // ZEDKIT_ARG_PARSER_H
