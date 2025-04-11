
// Created 01.10.2024 by Melnikov Kirill

#include <iostream>
#include "optimization.h"

int main() {
    int n, k;
    // std::cin >> n >> k;
    n = readInt();
    k = readInt();
    int64_t array[n];
    int64_t z;
    for (size_t i = 0; i < n; ++i) {
        // std::cin >> z;
        z = readInt();
        array[i]=z;
    }
    for (int i = 1; i <= k; ++i) {
        bool in = false;
        // std::cin >> z;
        z = readInt();
        size_t L=-1, R=n, m;
        while (R - L > 1) {
            m = (R + L) / 2;
            if (array[m] <= z) {
                L = m;
            } else {
                R = m;
            }
            if (array[L] == z || array[R] == z) {
                in = true;
                break;
            }
        }
        if (in) {
            // std::cout << "YES\n";
            writeWord("YES\n");
        } else {
            // std::cout << "NO\n";
            writeWord("NO\n");
        }
    }
}
