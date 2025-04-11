
// Created 04.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>

int recur(int l, int r, std::string str, std::vector<std::vector<int>> &dp) {
    if (dp[l][r] != -1) return dp[l][r];
    if (str[l] != str[r]) {
        dp[l][r] = std::max(recur(l + 1, r, str, dp), recur(l, r - 1, str, dp));
    } else {
        dp[l][r] = recur(l + 1, r - 1, str, dp) + 2;
    }
    return dp[l][r];
}

int main() {
    std::string str;
    std::cin >> str;
    int size = str.size();


    std::vector<std::vector<int>> dp(size + 1, std::vector<int>(size + 1, 0));
    std::vector<std::string> pos(size + 1);

    for (int i = 0; i < size; ++i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < size; ++j) {
            dp[i][j] = -1;
        }
    }

    recur(0, size - 1, str, dp);

    int l = 0, r = size - 1;
    int i = l, j = dp[0][size - 1];
    // std::cout << dp[0][size - 1];
    while (!(l > r)) {
        if (dp[l][r] == 1 && l == r) {
            pos[i] = str[l];
            ++i;
            ++l;
            continue;
        }
        if (str[l] == str[r]) {
            pos[i] = str[l];
            ++i;
            ++l;
            pos[j] = str[r];
            --j;
            --r;
            continue;
        }
        if (dp[l+1][r] < dp[l][r-1]) {
            --r;
        } else {
            ++l;
        }
    }

    /*for (auto v : dp) {
        for (auto z : v) {
            std::cout << z << " ";
        }
        std::cout << "\n";
    }*/

    for (auto c : pos) {
        std::cout << c;
    }
}
