
// Created 16.10.2024 by Melnikov Kirill

#include <vector>
#include <cmath>
#include <algorithm>
#include "optimization.h"

int64_t n;
uint32_t a, b;
uint32_t cur = 0; 

uint32_t nextRand24() {
     cur = cur * a + b;
 return cur >> 8;
}

uint32_t nextRand32() {
    uint32_t a = nextRand24(), b = nextRand24();
return (a << 8) ^ b; 
}

int main () {
    n = readInt();
    a = readInt();
    b = readInt();
    std::vector<uint32_t> ox;
    ox.reserve(n);
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        ox.push_back(nextRand32());
        sum += ox.back();
        // writeInt(ox.back(), ' ');
    }
    // writeInt(sum, '\n');
    int64_t g = std::gcd(sum, n);
    writeInt(sum/g, '/');
    writeInt(n/g);
}
