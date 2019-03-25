// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: string_format.cpp
// Description: String Format Helpers
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "strings/zk_string_format.h"

#include "strings/string_printf_impl.hpp"

namespace ZedKit {

std::string ZkStringPrintf(const char *format, ...)
{
    std::string ret;

    va_list args;
    va_start(args, format);
    ret = ZkStringPrintfV(format, args);
    va_end(args);

    return ret;
}

std::string ZkStringPrintfV(const char *format, va_list args)
{
    return StringPrintfImpl(format, args);
}

} // namespace ZedKit
