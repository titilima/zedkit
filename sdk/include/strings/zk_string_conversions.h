// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_string_conversions.h
// Description: String Conversions
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_STRING_CONVERSIONS_H
#define ZEDKIT_STRING_CONVERSIONS_H

#pragma once

#include <string>
#ifdef _WIN32
#   include <Windows.h>
#endif

namespace ZedKit {

#ifdef _WIN32
std::string ZkWideStringToMultiByte(const std::wstring &ws, UINT codePage = CP_ACP);
std::wstring ZkMultiByteToWideString(const std::string &s, UINT codePage = CP_ACP);
#endif

} // namespace ZedKit

#endif // ZEDKIT_STRING_CONVERSIONS_H
