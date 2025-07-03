#include "file_utils.h"
#include <fstream>
#include <iterator>
#include <vector>
#include <cstdint>

std::vector<uint8_t> readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    return std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
}

void writeFile(const std::string &filename, const std::vector<uint8_t> &data)
{
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<const char *>(data.data()), data.size());
}
