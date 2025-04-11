
// Created 30.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <algorithm>

// NU TAKOE
// NU TAKOE
// NU TAKOE

int main() {
    int64_t n;
    std::cin >> n;
    std::vector<int64_t> nums(n + 1);
    for (int64_t i = n; i >= 1; --i) {
        std::cin >> nums[i];
    }

    //храним длину наибольшей подпослед, оканчивающейся i элементом
    std::vector<int64_t> dp(n + 1, INT64_MAX);
    dp[0] = INT64_MIN;

    int64_t otvetik = 0;
    std::vector<int64_t> pos(n + 1), last(n + 1);
    pos[0] = -1;
    for (int64_t i = 1; i <= n; ++i) {
        int64_t el = nums[i];
        int64_t jel = std::upper_bound(dp.begin(), dp.end(), el) - dp.begin();
        if (dp[jel-1] <= el && el <= dp[jel]) {
            dp[jel] = el;
            pos[jel] = i;
            last[i] = pos[jel-1];
            otvetik = std::max(otvetik, jel);
        }
    }

    std::cout << otvetik << "\n";

    std::vector<int> otvets;
    int p = pos[otvetik];
    while (p > -1) {
        otvets.push_back(p);
        p = last[p];
    }

    for (auto z : otvets) {
        std::cout << n - z + 1 << "\n";
    }
}
