
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, m;
    std::cin >> m >> n;
    std::vector<std::vector<int>> p(n + 1, std::vector<int>(m + 1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> p[i][j];
        }
    }

    /*for (auto v : p) {
        for (int z : v) {
            std::cout << z << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';*/

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) f[i][j] = 0;
            if (i == 1 && j > 1) f[i][j] = f[i][j-1] + std::abs(p[i][j] - p[i][j-1]);
            if (i > 1 && j == 1) f[i][j] = f[i-1][j] + std::abs(p[i][j] - p[i-1][j]);
            if (i > 1 && j > 1) f[i][j] = std::min(f[i][j-1] + std::abs(p[i][j] - p[i][j-1]), f[i-1][j] + std::abs(p[i][j] - p[i-1][j]));
        }
    }

    /*for (auto v : f) {
        for (int z : v) {
            std::cout << z << " ";
        }
        std::cout << '\n';
    }*/

    std::cout << f[n][m];
}
