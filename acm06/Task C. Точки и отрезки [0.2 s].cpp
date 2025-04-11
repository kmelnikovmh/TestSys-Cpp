
// Created 16.10.2024 by Melnikov Kirill

#include <vector>
#include <algorithm>
#include "optimization.h"

int main() {
    int32_t n, m, z;
    n = readInt();
    m = readInt();
    std::vector<int32_t> cats;
    for (int i = 0; i < n; ++i) {
        z = readInt();
        cats.push_back(z);
    }
    std::sort(cats.begin(), cats.end());

    int32_t a, b;
    for (int i = 1; i <= m; ++i) {
        a = readInt();
        b = readInt();
        auto lower = std::lower_bound(cats.begin(), cats.end(), a);
        auto upper = std::upper_bound(cats.begin(), cats.end(), b);
        std::cout << std::distance(cats.begin(), upper) - std::distance(cats.begin(), lower)<<"\n";
    }
}
