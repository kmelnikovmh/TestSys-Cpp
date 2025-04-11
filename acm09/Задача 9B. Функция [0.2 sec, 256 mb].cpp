
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <unordered_map>

std::unordered_map<uint64_t, uint64_t> cache;
uint64_t func(int64_t z) {
    if (z <= 2) {
        cache[z] = 1;
        return cache[z];
    }
    if (cache.find(z) != cache.end()) return cache[z];
    if (z % 2 == 1) {
        cache[z] = func(6 * z / 7) + func(2 * z / 3);
    }
    if (z % 2 == 0) {
        cache[z] = func(z - 1) + func(z - 3);
    }
    return cache[z];
}

int main() {
    uint64_t n;
    uint32_t ans;
    std::cin >> n;

    ans = func(n);
    std::cout << ans;
}
