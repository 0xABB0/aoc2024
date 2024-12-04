#include "common.h"

void parse_active_regions(const std::string& input, std::vector<std::pair<size_t, size_t>>& active_regions) {
    const std::string pause_marker = "don't()";
    const std::string resume_marker = "do()";
    bool is_active = true;
    size_t pos = 0;

    while (pos < input.length()) {

        if (is_active) {
            size_t next_pause = input.find(pause_marker, pos);
            if (next_pause == std::string::npos) {
                active_regions.emplace_back(pos, input.length() - pos);
                break;
            } else {
                active_regions.emplace_back(pos, next_pause - pos);
                pos = next_pause + pause_marker.length();
                is_active = false;
            }
        } else {
            size_t next_resume = input.find(resume_marker, pos);
            if (next_resume == std::string::npos) {
                break;
            } else {
                pos = next_resume + resume_marker.length();
                is_active = true;
            }
        }
    }
}


int main() {
    std::string input;
    readfile_into_string("input.txt", input);

    const std::regex mul_regex(R"(mul\((\d+),(\d+)\))");

    std::vector<std::pair<size_t, size_t>> active_regions;
    parse_active_regions(input, active_regions);

    int sum_of_muls = 0;

    for (const auto& region : active_regions) {
        std::string active_text = input.substr(region.first, region.second);
        std::print(std::cout, "Active string: {}\n", active_text);

        auto words_begin = std::sregex_iterator(active_text.begin(), active_text.end(), mul_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            int first_number = std::stoi(match[1].str());
            int second_number = std::stoi(match[2].str());
            sum_of_muls += first_number * second_number;
        }
    }

    std::print(std::cout, "Total active strings: {}\n", active_regions.size());

    std::print(std::cout, "The sum of all muls is {}\n", sum_of_muls);
    return 0;
}
