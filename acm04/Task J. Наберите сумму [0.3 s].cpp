
// Created 01.10.2024 by Melnikov Kirill

#include <iostream>
#include "optimization.h"

int main() {
    long long n, k;
    // std::cin >> n;
    n = readInt<long long>();
    long long array[n], prefarray[n+1], pref = 0;
    prefarray[0] = 0;
    for (size_t i = 0; i < n; ++i) {
        long long z;
        // std::cin >> z;
        z = readInt<long long>();
        array[i] = z;
        pref += z;
        prefarray[i+1] = pref;
    }

    /*for (long long c:array) {
        std::cout << c << " ";
    }
    std::cout << "\n";*/

    /*for (long long c : prefarray) {
        std::cout << c << " ";
    }
    std::cout << "\n";*/

    //std::cin >> k;

    k = readInt<long long>();
    while (k--) {
        long long pos, s;
        // std::cin >> pos >> s;
        pos = readInt<long long>();
        s = readInt<long long>();
        int L = -1, R = n - pos + 2, ans = 0;
        while (R - L > 1) {
            long long m = (R + L) / 2, sum = prefarray[pos-1+m] - prefarray[pos-1];
            // std::cout << L << " " << R << " and " << m << " sum " << sum << "\n";
            if (sum < s) {
                L = m;
            } else {
                R = m;
                ans = 1;
            }
        }
        if (ans == 0) {
            // std::cout << -1 << "\n";
            writeInt(-1, '\n');
        } else {
            // std::cout << R << "\n";
            writeInt(R, '\n');
        }
    }
}
// 3 6 9 12 15 
