// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: zk_stream_cryptor.h
// Description: ZedKit Stream Cryptor
//      Author: Ziming Li
//     Created: 2017-05-07
// -------------------------------------------------
// Copyright (C) 2017 MingYang Software Technology.
// -------------------------------------------------

#ifndef ZEDKIT_STREAM_CRYPTOR_H
#define ZEDKIT_STREAM_CRYPTOR_H

#pragma once

/**
 * License Info:
 * The original source code is written by Warren Ward, "Applying Stream Encryption", 1998.
 *
 * Reference:
 * http://collaboration.cmc.ec.gc.ca/science/rpn/biblio/ddj/Website/articles/CUJ/1998/9809/ward/ward.htm
 */

#include <string>
#include <vector>

namespace ZedKit {

class ZkStreamCryptor
{
public:
    ZkStreamCryptor(void);
public:
    void SetKey(const std::string &key);
    std::string TransformString(const std::string &s);

    static std::string Transform(const std::string &s, const std::string &key = std::string());
    static void Transform(std::vector<unsigned char> *data, const std::string &key = std::string());
private:
    void TransformChar(unsigned char &target);
private:
    std::string     m_Key;
    uint32_t        m_LFSR_A;
    uint32_t        m_LFSR_B;
    uint32_t        m_LFSR_C;
    const uint32_t  m_Mask_A;
    const uint32_t  m_Mask_B;
    const uint32_t  m_Mask_C;
    const uint32_t  m_Rot0_A;
    const uint32_t  m_Rot0_B;
    const uint32_t  m_Rot0_C;
    const uint32_t  m_Rot1_A;
    const uint32_t  m_Rot1_B;
    const uint32_t  m_Rot1_C;
};

} // namespace ZedKit

#endif // ZEDKIT_STREAM_CRYPTOR_H
