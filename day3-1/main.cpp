#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
#include <ostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

int main() {
    auto file = std::ifstream("input.txt");

    std::string input;
    std::getline(file, input, '\0');
    file.close();

    const std::regex rex(R"(mul\((\d+),(\d+)\))");

    auto words_begin = std::sregex_iterator(input.begin(), input.end(), rex);
    auto words_end = std::sregex_iterator();

    int sum_of_muls = 0;

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        int first_number = std::stoi(match[1].str());
        int second_number = std::stoi(match[2].str());
        sum_of_muls += first_number * second_number;
    }

    std::print(std::cout, "The sum of all muls is {}\n", sum_of_muls);
    return 0;
}
