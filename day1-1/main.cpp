#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    auto file = std::ifstream("input.txt");

    std::vector<int> first_list{};
    std::vector<int> second_list{};

    while (!file.eof()) {
        int s1;
        int s2;

        file >> s1;
        file >> s2;

        first_list.emplace_back(s1);
        second_list.emplace_back(s2);
    }

    std::sort(first_list.begin(), first_list.end());
    std::sort(second_list.begin(), second_list.end());

    int sum = 0;
    for (int i = 0; i < first_list.size(); i++) {
        sum += std::abs(first_list[i] - second_list[i]);
    }

    std::cout << "The result is: " << sum << std::endl;

    file.close();
    return 0;
}
