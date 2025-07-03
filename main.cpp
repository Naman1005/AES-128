#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "include/aes.h"
#include "include/file_utils.h"


void printUsage()
{
    std::cout << "Usage: ./aes_cli <encrypt|decrypt> <input_file> <output_file> <key (16 chars)>\n";
}


std::vector<uint8_t> parseKey(const std::string &keyStr)
{
    if (keyStr.size() != 16)
        throw std::invalid_argument("Key must be exactly 16 characters");
    std::vector<uint8_t> key(16);
    for (size_t i = 0; i < 16; ++i)
        key[i] = static_cast<uint8_t>(keyStr[i]);
    return key;
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printUsage();
        return 1;
    }
    std::string mode = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    std::string keyStr = argv[4];

    std::vector<uint8_t> key;
    try
    {
        key = parseKey(keyStr);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Invalid key: " << e.what() << std::endl;
        return 1;
    }

    AES128 aes(key);
    std::vector<uint8_t> input = readFile(inputFile);
    std::vector<uint8_t> output;

    if (mode == "encrypt")
    {
        output = aes.encrypt(input);
    }
    else if (mode == "decrypt")
    {
        output = aes.decrypt(input);
    }
    else
    {
        printUsage();
        return 1;
    }
    writeFile(outputFile, output);
    std::cout << "Done. Output written to " << outputFile << std::endl;
    return 0;
}
