#include "fileUtils.h"
#include <fstream>

void readfile_into_string(std::string file_to_read, std::string& string_to_read_into) {
    auto file = std::ifstream(file_to_read);
    std::getline(file, string_to_read_into, '\0');
    file.close();
}
