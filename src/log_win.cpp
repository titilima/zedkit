// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: log_win.cpp
// Description: Logging Support
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "zk_log.h"

#include "strings/zk_string_conversions.h"
#include "strings/zk_string_format.h"

namespace ZedKit {

void ZkLog(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    std::string s = ZkStringPrintfV(format, args);
    va_end(args);

    std::wstring log = ZkMultiByteToWideString(s, CP_UTF8);
    log.append(L"\r\n");
    OutputDebugStringW(log.c_str());
}

} // namespace ZedKit
