// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_log.h
// Description: Logging Support
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_LOG_H
#define ZEDKIT_LOG_H

#pragma once

namespace ZedKit {

void ZkLog(const char *format, ...);

} // namespace ZedKit

#ifdef _DEBUG
#   define ZKLOG            ZedKit::ZkLog
#else
#   define ZKLOG(...)       ((void)0)
#endif

#endif // ZEDKIT_LOG_H
