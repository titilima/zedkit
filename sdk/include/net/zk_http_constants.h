// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_http_constants.h
// Description: HTTP Constants
//      Author: Ziming Li
//     Created: 2019-03-25
// -------------------------------------------------
// Copyright (C) 2019 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_HTTP_CONSTANTS_H
#define ZEDKIT_HTTP_CONSTANTS_H

#pragma once

namespace ZedKit {

struct ZkHTTPStatusCode {
    enum {
        OK = 200,
        NotModified = 304,
        NotFound = 404
    };
};

namespace HTTPHeaders {
extern const char AcceptEncoding[];
extern const char AcceptLanguage[];
extern const char Cookie[];
extern const char ETag[];
extern const char IfNoneMatch[];
extern const char Referer[];
extern const char UserAgent[];
} // HTTPHeaders

} // namespace ZedKit

#endif // ZEDKIT_HTTP_CONSTANTS_H
