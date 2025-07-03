
#include "file_utils.h"
#include <cstdint>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

vector<uint8_t> readFile(const string &filename) {
    ifstream file(filename, ios::binary);
    return vector<uint8_t>(istreambuf_iterator<char>(file), {});
}

void writeFile(const string &filename, const vector<uint8_t> &data) {
    ofstream file(filename, ios::binary);
    file.write(reinterpret_cast<const char *>(data.data()), data.size());
}
