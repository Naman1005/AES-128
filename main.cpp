
#include "include/aes.h"
#include "include/file_utils.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printUsage() {
    cout << "Usage: ./aes_cli <encrypt|decrypt> <input_file> <output_file> "
            "<key (16 chars)>\n";
}

vector<uint8_t> parseKey(const string &keyStr) {
    if (keyStr.size() != 16)
        throw invalid_argument("Key must be exactly 16 characters");
    vector<uint8_t> key(16);
    for (size_t i = 0; i < 16; ++i) key[i] = static_cast<uint8_t>(keyStr[i]);
    return key;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage();
        return 1;
    }
    string mode = argv[1];
    string inputFile = argv[2];
    string outputFile = argv[3];

    string keyStr = argv[4];

    vector<uint8_t> key;
    try {
        key = parseKey(keyStr);
    } catch (const exception &e) {
        cerr << "Invalid key: " << e.what() << endl;
        return 1;
    }

    AES128 aes(key);
    vector<uint8_t> input = readFile(inputFile);
    vector<uint8_t> output;

    if (mode == "encrypt") {
        output = aes.encrypt(input);
    } else if (mode == "decrypt") {
        output = aes.decrypt(input);
    } else {
        printUsage();
        return 1;
    }
    writeFile(outputFile, output);
    cout << "Done. Output written to " << outputFile << endl;
    return 0;
}
