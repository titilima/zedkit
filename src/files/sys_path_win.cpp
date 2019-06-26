// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: sys_path_win.cpp
// Description: ZkSysPath Class
//      Author: Ziming Li
//     Created: 2019-06-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "files/zk_sys_path.h"
#include <Windows.h>

namespace ZedKit {

static const DWORD BufSize = MAX_PATH;

static std::wstring GetModuleFilePath(HMODULE hModule)
{
    std::wstring ret(BufSize, L'\0');
    for (;;)
    {
        DWORD dw = GetModuleFileNameW(hModule, const_cast<PWSTR>(ret.data()), ret.length());
        DWORD err = GetLastError();

        if (NOERROR == err)
        {
            size_t p = ret.rfind(L'\\', dw);
            ret.resize(p + 1);
            break;
        }

        if (ERROR_INSUFFICIENT_BUFFER != err)
        {
            assert(ERROR_INSUFFICIENT_BUFFER == err);
            ret.clear();
            break;
        }

        DWORD size = ret.length() * 2;
        ret.resize(size);
    }
    return ret;
}

ZkSysPath::StringType ZkSysPath::Get(int id)
{
    std::wstring ret;
    switch (id)
    {
        case ExecutableFilePath:
            ret = GetModuleFilePath(nullptr);
            break;

        default:
            assert(false); // Not reached!
    }
    return ret;
}

} // namespace ZedKit
