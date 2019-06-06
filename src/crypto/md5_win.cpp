// -------------------------------------------------
// ZedKit for Windows
// -------------------------------------------------
//   File Name: md5_win.cpp
// Description: ZedKit MD5 Digest Algorithm
//      Author: Ziming Li
//     Created: 2017-04-24
// -------------------------------------------------
// Copyright (C) 2017 MingYang Software Technology.
// -------------------------------------------------

#include "crypto/zk_common_digest.h"

namespace ZedKit {

ZkMD5::ZkMD5(void)
{
    CryptAcquireContext(&m_prov, nullptr, nullptr, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
    assert(0 != m_prov);

    CryptCreateHash(m_prov, CALG_MD5, 0, 0, &m_hash);
    assert(0 != m_hash);
}

ZkMD5::~ZkMD5(void)
{
    CryptDestroyHash(m_hash);
    CryptReleaseContext(m_prov, 0);
}

void ZkMD5::Final(unsigned char dst[])
{
    DWORD cbHash = LEN;
    CryptGetHashParam(m_hash, HP_HASHVAL, dst, &cbHash, 0);
}

void ZkMD5::Update(const void *data, size_t size)
{
    CryptHashData(m_hash, reinterpret_cast<const BYTE *>(data), size, 0);
}

} // namespace ZedKit
