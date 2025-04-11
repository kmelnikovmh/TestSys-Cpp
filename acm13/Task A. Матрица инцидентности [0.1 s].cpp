
// Created 18.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

int main() {
    int v, e;
    std::cin >> v >> e;
    std::vector<std::vector<int>> MI(v + 1, std::vector<int>(e + 1, 0));

    int i, j;
    for (int l = 1; l <= e; ++l) {
        std::cin >> i >> j;
        MI[i][l] = 1;
        MI[j][l] = 1;
    }

    for (int i = 1; i <= v; ++i) {
        for (int j = 1; j <= e; ++j) {
            std::cout << MI[i][j] << " ";
        }
        std::cout << "\n";
    }
}
