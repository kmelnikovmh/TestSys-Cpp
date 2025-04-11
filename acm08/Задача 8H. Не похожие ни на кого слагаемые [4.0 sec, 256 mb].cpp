
// Created 13.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <unordered_set>
#include "optimization.h"

// std::unordered_set<int> used;
int k = 0;
// std::vector<int> num;

void psp(int n, int v, int len, int end) {
    if (n < 0 || (v > end + 1)) return;
    if (n == 0) {
        /*for (int z : num) {
            std::cout << z << " ";
        }*/
        
        int kol = 1;
        for (int i = len; i > 0; --i) {
            kol *= i;
        }
        k += kol;

        // std::cout << kol << " \n";
        return;
    }

    psp(n, v + 1, len, end);
    // num.push_back(v);
    psp(n - v, v + 1, len + 1, end);
    // num.pop_back();
    return;
}

int main() {
    int n;
    std::cin >> n;
    // num.reserve(60);
    psp(n, 1, 0, n);
    std::cout << k;
}
