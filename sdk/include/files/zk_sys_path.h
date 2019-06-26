// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_sys_path.h
// Description: ZkSysPath Class
//      Author: Ziming Li
//     Created: 2019-06-26
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_SYS_PATH_H
#define ZEDKIT_SYS_PATH_H

#pragma once

#include <string>

namespace ZedKit {

class ZkSysPath
{
public:
#ifdef _WIN32
    typedef std::wstring    StringType;
#else
    typedef std::string     StringType;
#endif

    static StringType Get(int id);

    enum SystemPathIDs {
        ExecutableFilePath = 0
    };
};

} // namespace ZedKit

#endif // ZEDKIT_SYS_PATH_H
