
// Created 01.10.2024 by Melnikov Kirill

#include <iostream>
#include <algorithm>
#include "optimization.h"

int main() {
    int64_t n, k;
    n = readInt();
    k = readInt();
    // std::cin >> n >> k;
    int64_t array[n], sum = 0;
    for (int64_t i = 0; i < n; ++i) {
        int64_t z = readInt();
        // std::cin >> z;
        sum += z;
        array[i] = z;
    }
    /*for (int64_t c : array) {
        std::cout << c << " ";
    }
    std::cout << "\n";*/

    int64_t L = 0, R = (sum / k) + 1;
    while (R - L > 1) {
        int64_t m = (R + L) / 2;
        int64_t countkus = 0;
        for (int64_t i = 0; i < n; ++i) {
            countkus += (array[i]/m);
        }
        // std::cout << L << " " << R << " and " << m << " kus " << countkus << "\n";
        if (countkus >= k) {
            L = m;
        } else {
            R = m;
        }
    }
    // std::cout << L << " "<< R;
    writeInt(L);
}
