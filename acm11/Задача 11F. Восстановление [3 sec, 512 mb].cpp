
// Created 04.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>

// ne znau, kak eto robit =)))

const int64_t mod = 1'000'000'000 + 7;
int main() {
    std::string str;
    std::cin >> str;
    str = ' ' + str;
    int size = str.size();
    std::vector<std::vector<int32_t>> dp(size + 1, std::vector<int32_t>(size, 0));
    dp[0][0] = 1;

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (str[i] == '?') {
                dp[i][j] = dp[i-1][j+1] % mod;
                if (j != 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            }
            if (str[i] == '(' && j != 0) {
                dp[i][j] = dp[i-1][j-1] % mod;
            }
            if (str[i] == ')') dp[i][j] = dp[i-1][j+1] % mod;
        }
    }

    /*for (auto z : dp) {
        for (auto v : z) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }*/

    std::cout << dp[size-1][0];
}
