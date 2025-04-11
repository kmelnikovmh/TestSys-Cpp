
// Created 30.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

int main() {
    int64_t a, b;
    std::cin >> a >> b;
    std::vector<int64_t> numA(a), numB(b);
    std::vector<std::vector<int64_t>> dp(a + 1, std::vector<int64_t>(b + 1,0));
    for (int64_t i = 0; i < a; ++i) {
        std::cin >> numA[i];
    }
    for (int64_t j = 0; j < b; ++j) {
        std::cin >> numB[j];
    }
    
    int64_t otvetik = 1;
    for (int64_t i = 1; i <= a; ++i) {
        int64_t buf = 0; // dp[i-1][j];
        for (int64_t j = 1; j <= b; ++j) {
            if (numA[i-1] == numB[j-1] && dp[i-1][j] < buf +1) {
                dp[i][j] = buf + 1;
            } else {
                dp[i][j] = dp[i-1][j];
            }
            if (numA[i-1] > numB[j-1] && dp[i-1][j] > buf) {
                buf = dp[i-1][j];
            }
            if (i == a) {
                if (dp[i][otvetik] < dp[i][j]) {
                    otvetik = j;
                }
            }
        }
    }
        
    std::cout << dp[a][otvetik];
}
