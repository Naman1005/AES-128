#ifndef AES_H
#define AES_H
#include <vector>
#include <cstdint>
#include <string>

class AES128
{
public:
    AES128(const std::vector<uint8_t> &key);
    std::vector<uint8_t> encrypt(const std::vector<uint8_t> &data);
    std::vector<uint8_t> decrypt(const std::vector<uint8_t> &data);

private:
    void keyExpansion(const std::vector<uint8_t> &key);
    void addRoundKey(uint8_t *state, int round);
    void subBytes(uint8_t *state);
    void invSubBytes(uint8_t *state);
    void shiftRows(uint8_t *state);
    void invShiftRows(uint8_t *state);
    void mixColumns(uint8_t *state);
    void invMixColumns(uint8_t *state);
    void encryptBlock(uint8_t *state);
    void decryptBlock(uint8_t *state);
    static uint8_t mul(uint8_t x, uint8_t y);
    std::vector<uint8_t> roundKeys;
};

#endif // AES_H
