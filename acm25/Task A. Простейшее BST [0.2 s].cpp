
// Created 22.04.2025 by Melnikov Kirill

#include <iostream>
#include <string>
#include <set>

int main() {
    
    std::set<int> bst;
    std::string str;
    while (std::getline(std::cin, str)) {
        int x = std::stoi(str.substr(2));
        if (str[0] == '+') {
            bst.insert(x);
        } else {
            auto ans = bst.upper_bound(x);
            if (ans == bst.end()) {
                std::cout << "0\n";
            } else {
                std::cout << *ans << "\n";
            }
        }
    }   
}