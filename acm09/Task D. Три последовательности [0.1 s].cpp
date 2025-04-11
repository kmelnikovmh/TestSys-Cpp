
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n;
    std::vector<int> nn(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> nn[i];
    }
    std::cin >> m;
    std::vector<int> mm(m + 1);
    for (int i = 1; i <= m; ++i) {
        std::cin >>  mm[i];
    }
    std::cin >> k;
    std::vector<int> kk(k + 1);
    for (int i = 1; i <= k; ++i) {
        std::cin >> kk[i];
    }

    
    std::vector<std::vector<std::vector<int>>> f(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(k + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (nn[i] == mm[j] && mm[j] == kk[l]) {
                    f[i][j][l] = f[i-1][j-1][l-1] + 1;
                } else {
                    f[i][j][l] = std::max({f[i-1][j][l], f[i][j-1][l], f[i][j][l-1]});
                }
            }
        }
    }
    std::cout << f[n][m][k];
}
