
// Created 16.10.2024 by Melnikov Kirill

#include <vector>
#include <algorithm>
#include "optimization.h"

uint32_t n, a, b;
uint32_t cur = 0; 

uint32_t nextRand24() {
     cur = cur * a + b;
 return cur >> 8;
}

uint32_t nextRand32() {
    uint32_t a = nextRand24(), b = nextRand24();
return (a << 8) ^ b; 
}

int main() {
    n = readInt();
    a = readInt();
    b = readInt();
    std::vector<uint32_t> ox;
    
    for (int i = 0; i < n; ++i) {
        ox.push_back(nextRand32());
    }
    auto m = ox.begin() + n / 2;
    std::nth_element(ox.begin(), m, ox.end());
    uint64_t sumMin = 1e17;
    for (uint32_t i = n/2 - 1; i <= n/2 + 1; i += 1) {
        uint64_t sum = 0;
        for (uint32_t z : ox) {
            if (z>ox[i]) {
                sum += z-ox[i];
            } else {
                sum += ox[i]-z;
            }
        }
        sumMin = std::min(sum, sumMin);
    }
    writeInt(sumMin);
}
