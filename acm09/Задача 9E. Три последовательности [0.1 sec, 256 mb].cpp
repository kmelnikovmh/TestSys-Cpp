
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

    std::vector<std::vector<std::vector<int>>> f(n + 1, std::vector<std::vector<int>>(m + 1,std::vector<int>(k + 1, 0)));
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

    int ans = f[n][m][k];
    std::cout << ans << "\n";
    std::vector<int> slice(ans + 1);
    int i = n, j = m, l = k;
    while (i != 0 && j != 0 && l != 0 && ans != 0) {
        if (nn[i] == mm[j] && mm[j] == kk[l]) {
            slice[ans] = nn[i];
            --ans;
            --i;
            --j;
            --l;
        } else if (f[i-1][j][l] == f[i][j][l]) {
            --i;
        } else if (f[i][j-1][l] == f[i][j][l]) {
            --j;
        } else if (f[i][j][l-1] == f[i][j][l]) {
            --l;
        }
    }

    for (int t = 1; t <= slice.size() - 1; ++t) {
        std::cout << slice[t] << " ";
    }
}
