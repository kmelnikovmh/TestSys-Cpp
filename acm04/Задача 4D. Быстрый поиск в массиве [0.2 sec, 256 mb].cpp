
// Created 01.10.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <algorithm>
#include "optimization.h"

int main() {
    int64_t n, k;
    // std::cin >> n;
    n = readInt();
    int64_t z;
    std::vector<int64_t> array;
    array.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        // std::cin >> z;
        z = readInt();
        array.push_back(z);
    }
    std::sort(array.begin(), array.end());

    // std::cin >> k;
    k = readInt();
    for (int64_t i = 1; i <= k; ++i) {
        int64_t a,b;
        // std::cin >> a >> b;
        a = readInt();
        b = readInt();

        int64_t L = -1, R = array.size();
        while (R - L > 1) {
            int64_t m = (R + L) / 2;
            // std::cout << L << " " << R << " and " << m << "\n";
            if (array[m] < a) {
                L = m;
            } else {
                R = m;
            }
        }
        int64_t left = R;

        L = -1, R = array.size();
        while (R - L > 1) {
            int64_t m = (R + L) / 2;
            // std::cout << L << " " << R << " and " << m << "\n";
            if (array[m] <= b) {
                L = m;
            } else {
                R = m;
            }
        }
        int64_t right = L;
        // std::cout << right-left+1 << " ";
        writeInt(right - left + 1);
        writeWord(" ");
    }
}
