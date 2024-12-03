#include <iostream>
#include <fstream>
#include <vector>

int how_many_times_dumb(int needle, std::vector<int>& haystack) {
    int counter = 0;
    for (auto i : haystack) {
        if (i == needle) counter += 1;
    }
    return counter;
}

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
    
    file.close();
    
    int sum = 0;
    for (int mark : first_list) {
        sum += mark * how_many_times_dumb(mark, second_list);
    }

    std::cout << "The result is: " << sum << std::endl;
    return 0;
}
