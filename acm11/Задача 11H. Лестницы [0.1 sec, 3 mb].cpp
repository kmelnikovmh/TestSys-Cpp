
// Created 04.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

// тип свернутное dp[n][k] = dp[n][k-1] + dp[n-k][k-1],
// где n кол-во кубиков, а k эт тип в правом столбике не больше, чем k кубиков
// сразу бахнем в линию, ведь у нас по факту следующее вычисляется из предыдущего
// надо аккурат забахать перебор k, дабы верно посчитать

int main() {
    int64_t n;
    std::cin >> n;
    std::vector<int64_t> dp(n + 2, 0);
    // dp[0] = 0;
    dp[1] = 1;

    for (int i = 1; i < n + 1; ++i) {
        for (int k = n + 1; k > i; --k) {
            dp[k] += dp[k-i];
        }
    }
    std::cout << dp[n+1] - 1;
}
