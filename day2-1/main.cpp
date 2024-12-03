#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

bool get_bad_index(std::vector<int>& report) {
    bool is_descending = true;
    bool is_acending = true;
    for (int i = 1; i < report.size(); i++) {
        int abs_diff = std::abs(report[i] - report[i-1]);
        if (abs_diff == 0 || abs_diff > 3) {
            return false;
        }

        if (report[i] > report[i - 1]) {
            is_descending = false;
        } else if (report[i] < report[i -1]) {
            is_acending = false;
        } else {
            return false;
        }
    }

    return is_acending || is_descending;
}

int main() {
    auto file = std::ifstream("input.txt");

    std::vector<std::vector<int>> reports{};

    while (!file.eof()) {
        
        std::string line;
        std::getline(file, line, '\n');
        
        std::stringstream line_stream(line);

        reports.emplace_back();
        std::vector<int>& values = reports.back();
        while (!line_stream.eof()) {
            std::string chars;
            std::getline(line_stream, chars, ' ');
            std::stringstream chars_stream(chars);

            int value;
            chars_stream >> value;
            values.push_back(value);
        }
    }

    int counter = 0;
    for (auto& report : reports) {
        if (get_bad_index(report)) {
            counter++;
        }
    }

    std::cout << "Number of safe reports: " << counter << std::endl;
    
    file.close();

    return 0;
}
