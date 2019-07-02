// -------------------------------------------------
// ZedKit
// -------------------------------------------------
//   File Name: stream_cryptor.cpp
// Description: ZedKit Stream Cryptor
//      Author: Ziming Li
//     Created: 2017-05-07
// -------------------------------------------------
// Copyright (C) 2017 MingYang Software Technology.
// -------------------------------------------------

#include "crypto/zk_stream_cryptor.h"

namespace ZedKit {

ZkStreamCryptor::ZkStreamCryptor(void)
    // Initialize LFSRs to non-zero values.
    : m_LFSR_A(0x13579BDF)
    , m_LFSR_B(0x2468ACE0)
    , m_LFSR_C(0xFDB97531)
    // Initialize feedback masks to magic numbers. 
    , m_Mask_A(0x80000062)
    , m_Mask_B(0x40000020)
    , m_Mask_C(0x10000002)
    // Set up LFSR "rotate" masks.
    , m_Rot0_A(0x7FFFFFFF)
    , m_Rot0_B(0x3FFFFFFF)
    , m_Rot0_C(0x0FFFFFFF)
    , m_Rot1_A(0x80000000)
    , m_Rot1_B(0xC0000000)
    , m_Rot1_C(0xF0000000)
{
    SetKey(std::string());
}

void ZkStreamCryptor::PrepareTransforming(void)
{
    // LFSR A, B, and C get the first, second, and
    // third four bytes of the seed, respectively.
    for (int i = 0; i < 4; ++i)
    {
        m_LFSR_A = ((m_LFSR_A <<= 8) | static_cast<uint32_t>(m_seed[i + 0]));
        m_LFSR_B = ((m_LFSR_B <<= 8) | static_cast<uint32_t>(m_seed[i + 4]));
        m_LFSR_C = ((m_LFSR_C <<= 8) | static_cast<uint32_t>(m_seed[i + 8]));
    }

    // If any LFSR contains 0x00000000, load a 
    // non-zero default value instead. 
    if (0x00000000 == m_LFSR_A)
        m_LFSR_A = 0x13579BDF;
    if (0x00000000 == m_LFSR_B)
        m_LFSR_B = 0x2468ACE0;
    if (0x00000000 == m_LFSR_C)
        m_LFSR_C = 0xFDB97531;
}

void ZkStreamCryptor::SetKey(const std::string &key)
{
    std::string seed(key);

    // Set default key if none provided.
    if (seed.empty())
        seed = "Default Seed";

    // Make sure seed is at least 12 bytes long . 
    size_t l = seed.length();
    if (l < 12)
        seed.append(seed.substr(0, 12 - l));

    m_seed.clear();
    for (char ch : seed)
        m_seed.push_back(ch);
}

void ZkStreamCryptor::TransformChar(unsigned char &target)
{
    int             Counter = 0;
    unsigned char   Crypto = '\0';
    uint32_t        Out_B = (m_LFSR_B & 0x00000001);
    uint32_t        Out_C = (m_LFSR_C & 0x00000001);

    // Cycle the LFSRs eight times to get eight pseudo-
    // random bits. Assemble these into a single random 
    // character (Crypto).
    for (Counter = 0; Counter < 8; ++Counter)
    {
        if (0 != (m_LFSR_A & 0x00000001))
        {
            // The least-significant bit of LFSR A is 
            // "1". XOR LFSR A with its feedback mask.
            m_LFSR_A = ((m_LFSR_A ^ (m_Mask_A >> 1)) | m_Rot1_A);

            // Clock shift register B once.
            if (0 != (m_LFSR_B & 0x00000001))
            {
                // The LSB of LFSR B is "1". 
                // XOR LFSR B with its feedback mask.
                m_LFSR_B = ((m_LFSR_B ^ (m_Mask_B >> 1)) | m_Rot1_B);
                Out_B = 0x00000001;
            }
            else
            {
                // The LSB of LFSR B is "0". Rotate 
                // the LFSR contents once.
                m_LFSR_B = ((m_LFSR_B >> 1) & m_Rot0_B);
                Out_B = 0x00000000;
            }
        }
        else
        {
            // The LSB of LFSR A is "0". 
            // Rotate the LFSR contents once.
            m_LFSR_A = ((m_LFSR_A >> 1) & m_Rot0_A);

            // Clock shift register C once.
            if (m_LFSR_C & 0x00000001)
            {
                // The LSB of LFSR C is "1". 
                // XOR LFSR C with its feedback mask.
                m_LFSR_C = ((m_LFSR_C ^ (m_Mask_C >> 1)) | m_Rot1_C);
                Out_C = 0x00000001;
            }
            else
            {
                // The LSB of LFSR C is "0". Rotate 
                // the LFSR contents once.
                m_LFSR_C = ((m_LFSR_C >> 1) & m_Rot0_C);
                Out_C = 0x00000000;
            }

        }

        // XOR the output from LFSRs B and C and rotate it 
        // into the right bit of Crypto.
        Crypto = ((Crypto << 1) | (Out_B ^ Out_C));
    }

    // XOR the resulting character with the 
    // input character to encrypt/decrypt it.
    target = (target ^ Crypto);
}

std::string ZkStreamCryptor::TransformString(const std::string &s)
{
    PrepareTransforming();

    std::string ret;
    for (char ch : s)
    {
        TransformChar(reinterpret_cast<unsigned char &>(ch));
        ret.push_back(ch);
    }
    return ret;
}

std::string ZkStreamCryptor::Transform(const std::string &s, const std::string &key)
{
    ZkStreamCryptor cryptor;
    cryptor.SetKey(key);
    return cryptor.TransformString(s);
}

void ZkStreamCryptor::Transform(std::vector<unsigned char> *data, const std::string &key)
{
    ZkStreamCryptor cryptor;
    cryptor.SetKey(key);
    cryptor.PrepareTransforming();
    for (unsigned char &ch : *data)
        cryptor.TransformChar(ch);
}

} // namespace ZedKit
