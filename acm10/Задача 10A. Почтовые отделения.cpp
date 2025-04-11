
// Created 30.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> domiks(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> domiks[i];
    }

    std::vector<std::vector<int>> cost(n + 1, std::vector<int>(n + 1,0));
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n;  ++i) {
        for (int j = i; j <= n; ++j) {
            int med = (i + j) / 2;
            for (int x = i; x <= j; ++x) {
                cost[i][j] += std::abs(domiks[x] - domiks[med]);
            }
        }
    }

    for (int otr = 1; otr <= m; ++otr) {
        for (int doms = 1; doms <= n; ++doms) {
            for (int l = 1; l <= n ; ++l) {
                if (dp[otr-1][l-1] != INT_MAX) {
                    dp[otr][doms] = std::min(dp[otr][doms], dp[otr-1][l-1] + cost[l][doms]);
                }
            }
        }
    }

    std::vector<int> res(m);
    int otr = m;
    int doms = n;
    while (otr > 0) {
        for (int l = 1; l <= doms; ++l) {
            if(dp[otr][doms] == dp[otr-1][l-1] + cost[l][doms]) {
                res[otr-1] = domiks[(l + doms) / 2];
                doms = l - 1;
                --otr;
            }
        }
    }
    std::cout << dp[m][n] << "\n";
    for (auto z : res) {
        std::cout << z << " ";
    }
}
