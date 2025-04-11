
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <unordered_map>
#include "optimization.h"

int main() {
    int64_t mod = 1'000'000'000 + 7;
    int n;
    n = readInt();
    // std::cin >> n;
    std::vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        nums[i] = readInt();
        // std::cin >> nums[i];
    }

    int64_t ans = 0, oldi;
    std::unordered_map<int64_t, int64_t> Being;
    for (int i = 1; i <= n; ++i) {
        oldi = ans;

        if (Being.find(nums[i]) == Being.end()) {
            ans = (ans * 2 + 1) % mod;
        } else {
            ans = (ans * 2 + 1 + mod - Being[nums[i]]) % mod;
        }
        Being[nums[i]] = (oldi + 1) % mod;
    }

    writeInt(ans);
    // std::cout << ans;
}
