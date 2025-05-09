
// Created 15.04.2025 by Melnikov Kirill

#include <iostream>
#include <random>
#include <algorithm>

std::string greedy_first(std::vector<std::string> str) {
    std::sort(str.begin(), str.end(), [](std::string &lhs, std::string &rhs) {
        return lhs < rhs;
    });

    std::string ans_str;
    for (auto s : str) {
        ans_str += s;
    }
    return ans_str;
}

std::string greedy_second(std::vector<std::string> str) {
    std::sort(str.begin(), str.end(), [](std::string &lhs, std::string &rhs) {
        return lhs + lhs < rhs + rhs;
    });
    
    std::string ans_str;
    for (auto s : str) {
        ans_str += s;
    }
    return ans_str;
}

std::string right_greedy(std::vector<std::string> str) {
    std::sort(str.begin(), str.end(), [](std::string &lhs, std::string &rhs) {
        return lhs + rhs < rhs + lhs;
    });
    
    std::string ans_str;
    for (auto s : str) {
        ans_str += s;
    }
    return ans_str;
}

int main() {
    int type;
    std::cin >> type;

    std::mt19937 rng(229);
    bool find_test = false;
    while (!find_test) {
        int n = 2 + rng() % (3 - 2 + 1);
        std::vector<std::string> str(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= (1 + rng() % 3); ++j) {
                bool type_str = rng() % 2;
                if (type_str == 0) {
                    str[i] += "a";
                } else {
                    str[i] += "b";
                }
            }
        }

        std::string ans_right_greedy = right_greedy(str);

        std::string ans_lose_greedy;
        if (type == 1) {
            ans_lose_greedy = greedy_first(str);
        } else {
            ans_lose_greedy = greedy_second(str);
        }

        if (ans_right_greedy != ans_lose_greedy) {
            find_test = true;

            // std::cout << "\nlose : " << ans_lose_greedy << "\n";
            // std::cout << "right : " << ans_right_greedy << "\n\n";

            std::cout << n << "\n";
            for (auto s : str) {
                std::cout << s << " ";
            }
        }
    }    
}