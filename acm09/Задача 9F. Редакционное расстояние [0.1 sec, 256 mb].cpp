
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::vector<std::vector<int>> f(a.size() + 1, std::vector<int>(b.size() + 1, 0));

    for (int i = 0; i <= a.size(); ++i) {
        for (int j = 0; j <= b.size(); ++j) {
            if (i == j == 0) f[i][j] = 0;
            if (i == 0 && j > 0) f[i][j] = j;
            if (i > 0 && j == 0) f[i][j] = i;

            if (i > 0 && j > 0) {
                int w;
                if (a[i-1] == b[j-1]) w = 0; else w = 1;
                f[i][j] = std::min({f[i-1][j] + 1, f[i][j-1] + 1, f[i-1][j-1] + w});
            }
        }
    }

    /*for (auto v : f) {
        for (auto z : v) {
            std::cout << z << " ";
        }
        std::cout << "\n";
    }*/
    std::cout << f[a.size()][b.size()];
}
