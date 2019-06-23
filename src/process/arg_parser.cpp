// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: arg_parser.cpp
// Description: Argument Parser for Command Line Strings
//      Author: Ziming Li
//     Created: 2019-06-23
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#include "process/zk_arg_parser.h"

namespace ZedKit {

ZkPOSIXArgParser::ZkPOSIXArgParser(void)
{
    Setup("--", "=");
}

} // namespace ZedKit
