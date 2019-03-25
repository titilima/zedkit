// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_config.h
// Description: Configurations for Building
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_CONFIG_H
#define ZEDKIT_CONFIG_H

#pragma once

#ifdef _MSC_VER
#   include <yvals_core.h>
#   if defined(_HAS_CXX17) && _HAS_CXX17
#       define _ZK_STRING_VIEW_SUPPORTED
#   endif
#endif

#endif // ZEDKIT_CONFIG_H
