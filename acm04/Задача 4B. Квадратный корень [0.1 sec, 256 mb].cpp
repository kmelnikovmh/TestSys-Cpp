
// Created 01.10.2024 by Melnikov Kirill

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);
    uint64_t n;
    while (std::cin >> n) {

        uint64_t L = 0, R;
        if (n > 100) {
            R = n;
        } else {
            R = n + 1;
        }
        while (R - L > 1) {
            uint64_t m = (R + L) / 2;
            // std::cout << L << " " << R << " and " << m << " mm " << m*m <<  "\n";
            if (m < 4294967296ULL && m * m <= n) {
                L = m;
            } else {
                R = m;
            }
        }
        std::cout << L << "\n";
    }
}
