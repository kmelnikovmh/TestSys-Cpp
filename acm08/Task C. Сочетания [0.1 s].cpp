
// Created 13.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include "optimization.h"

void psp(int begin, int k, std::vector<int> &num, int end) {
    if (k == 0) {
        for (int z : num) {
            std::cout << z << " ";
        }
        std::cout << "\n";
        return;
    }
    for (int i = begin; i <= end; ++i) {
        num.push_back(i);
        psp(i + 1, k - 1, num, end);
        num.pop_back();
    }
    return;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> num;
    num.reserve(n);
    psp(1, k, num, n);
}
