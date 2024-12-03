#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int get_bad_index(std::vector<int>& report) {
    bool is_descending = false;
    bool is_acending = false;
    for (int i = 1; i < report.size(); i++) {
        int abs_diff = std::abs(report[i] - report[i-1]);
        if (abs_diff == 0 || abs_diff > 3) {
            return i;
        }

        if (report[i] > report[i - 1]) {
            is_acending = true;
            if (is_descending) return i;
        } else if (report[i] < report[i -1]) {
            is_descending = true;
            if (is_acending) return i;
        } else {
            return i;
        }
    }

    return -1;
}

int retry_without(std::vector<int>& report, int bad_idx) {
    std::vector<int> report_copy = report;
    report_copy.erase(std::next(report_copy.begin(), bad_idx));
    return get_bad_index(report_copy);
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
        int bi = get_bad_index(report);
        if (bi != -1) {
            // if (bi == 1 || bi == 2) {
            //     if (retry_without(report, 0) == -1) goto label_continue;
            //     if (retry_without(report, 1) == -1) goto label_continue;
            //     if (retry_without(report, 2) == -1) goto label_continue;
            // }

            // bi = retry_without(report, bi);

            for (int i = 0; i < report.size(); i++) {
                if (retry_without(report, i) == -1) break;
            }
        } 
        label_continue:
        if (bi == -1) {
            counter++;
        }
    }

    std::cout << "Number of safe reports: " << counter << std::endl;
    
    file.close();

    return 0;
}
