
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> gv(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> gv[i];
    }
    std::sort(gv.begin(), gv.end());

    /*for (auto z : gv) {
        std::cout << z << " ";
    }
    std::cout << '\n';*/

    std::vector<int> f(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (i == 0 || i == 1) {
            f[i] = 0;
        } else if (i == 2) {
            f[i] = gv[i] - gv[i-1];
        } else if (i == 3) {
            f[i] = f[i-1] + gv[i] - gv[i-1];
        } else {
            f[i] = std::min(f[i-1], f[i-2]) + gv[i] - gv[i-1];
        }
    }

    /*for (auto z : f) {
        std::cout << z << " ";
    }
    std::cout << '\n';*/
    std::cout << f[n];
}
