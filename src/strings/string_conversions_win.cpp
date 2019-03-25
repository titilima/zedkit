// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: string_conversions_win.cpp
// Description: String Conversions
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "strings/zk_string_conversions.h"

namespace ZedKit {

std::wstring ZkMultiByteToWideString(const std::string_view &s, UINT codePage)
{
    std::wstring ws;

    int n = MultiByteToWideChar(codePage, 0, s.data(), s.length(), nullptr, 0);
    ws.resize(n, L'\0');
    MultiByteToWideChar(codePage, 0, s.data(), s.length(), const_cast<PWSTR>(ws.data()), n);

    return ws;
}

std::wstring ZkMultiByteToWideString(const std::string &s, UINT codePage)
{
    return ZkMultiByteToWideString(std::string_view(s.data(), s.length()), codePage);
}

std::string ZkWideStringToMultiByte(const std::wstring_view &ws, UINT codePage)
{
    std::string s;

    int n = WideCharToMultiByte(codePage, 0, ws.data(), ws.length(), nullptr, 0, nullptr, nullptr);
    s.resize(n, '\0');
    WideCharToMultiByte(codePage, 0, ws.data(), ws.length(), const_cast<PSTR>(s.data()), n, nullptr, nullptr);

    return s;
}

std::string ZkWideStringToMultiByte(const std::wstring &ws, UINT codePage)
{
    return ZkWideStringToMultiByte(std::wstring_view(ws.data(), ws.length()), codePage);
}

} // namespace ZedKit
