
// Created 04.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include "bigint.inc.cpp"

// Тут вроде все банально, просто идем по полю в обратном направлении и считаем для каждой клетки количество, 
// если еще не были в ней

bigint rec(int i, int j, int n, int m, std::vector<std::vector<bigint>> &dp) {
    if (!(0 <= i  && i < n && 0 <= j && j < m)) {
        return 0;   
    }
    if (dp[i][j] == 0) {
        dp[i][j] = rec(i - 2, j - 1, n, m, dp) + rec(i - 2, j + 1, n, m, dp);
        dp[i][j] += rec(i - 1, j - 2, n, m, dp) + rec(i + 1, j - 2, n, m, dp);
        // dp[i][j] += rec(i - 1, j + 2, n, m, dp) + rec(i + 1, j + 2, n, m, dp);
        // dp[i][j] += rec(i + 2, j - 1, n, m, dp) + rec(i + 2, j + 1, n, m, dp);
    }
    return dp[i][j];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<bigint>> dp(n, std::vector<bigint>(m, 0));
    dp[0][0] = 1;

    rec(n - 1, m - 1, n, m, dp);

    /*for (auto z : dp) {
        for (auto v : z) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }*/

    std::cout << dp[n-1][m-1];
}
