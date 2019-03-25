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

std::wstring ZkMultiByteToWideString(PCSTR ps, size_t length, UINT codePage)
{
    std::wstring ws;

    int n = MultiByteToWideChar(codePage, 0, ps, length, nullptr, 0);
    ws.resize(n, L'\0');
    MultiByteToWideChar(codePage, 0, ps, length, const_cast<PWSTR>(ws.data()), n);

    return ws;
}

std::string ZkWideStringToMultiByte(PCWSTR pws, size_t length, UINT codePage)
{
    std::string s;

    int n = WideCharToMultiByte(codePage, 0, pws, length, nullptr, 0, nullptr, nullptr);
    s.resize(n, '\0');
    WideCharToMultiByte(codePage, 0, pws, length, const_cast<PSTR>(s.data()), n, nullptr, nullptr);

    return s;
}

} // namespace ZedKit
