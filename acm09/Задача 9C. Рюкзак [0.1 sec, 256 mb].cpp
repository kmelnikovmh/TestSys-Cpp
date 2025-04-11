
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int S, N;
    std::cin >> S >> N;
    std::vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> a[i];
    }

    /*for (auto z : a) {
        std::cout << z << " ";
    }
    std::cout << "\n";*/

    std::vector<std::vector<int>> f(N + 1, std::vector<int>(S + 1, 0));
    if (a[1] <= 1) {
        f[1][1] = a[1];
    } else {
        f[1][1] = 0;
    }
    for (int j = 2; j <= S; ++j) {
        if (a[1] <= j) {
            f[1][j] = a[1];
        }
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= S; ++j) {
            if (j - a[i] >= 0) {
                f[i][j] = std::max(f[i-1][j], a[i] + f[i-1][j-a[i]]);
            } else {
                f[i][j] = f[i-1][j];
            }
            
        }
    }
    /*for (auto v : f) {
        for (auto z : v) {
            std::cout << z << " ";
        }
        std::cout << "\n";
    }*/
   std::cout << f[N][S];
}
