
// Created 13.11.2024 by Melnikov Kirill

#include <iostream>
#include <unordered_set>

int k = 0;
std::unordered_set<std::string> mult;

void psp (std::string &str, int j) {
    if (j == str.size()) {
        k += 1;
        return;
    }
    for (int i = j + 1; i <= str.size(); ++i) {
        std::string first = str.substr(j, i - j);
        if (mult.find(first) == mult.end()) {
            mult.insert(first);
            psp (str, i);
            mult.erase(first);
        }
    }
}

int main() {
    std::string str;
    std::cin >> str;
    psp(str, 0);
    std::cout << k;
}
