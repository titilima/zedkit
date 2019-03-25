// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_string_format.h
// Description: String Format Helpers
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_STRING_FORMAT_H
#define ZEDKIT_STRING_FORMAT_H

#pragma once

#include <cstdarg>

namespace ZedKit {

std::string ZkStringPrintf(const char *format, ...);
std::string ZkStringPrintfV(const char *format, va_list args);

} // namespace ZedKit

#endif // ZEDKIT_STRING_FORMAT_H
