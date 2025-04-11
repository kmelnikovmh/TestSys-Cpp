
// Created 16.10.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include "optimization.h"

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

int main() {
    uint64_t n, q;
    n = readInt();
    q = readInt();
    std::vector<uint32_t> zahl;
    a = readInt();
    b = readInt();
    zahl.reserve(n);
    for (uint64_t i = 0; i < n; ++i) {
        zahl.push_back(nextRand32());
        // std::cout << zahl.back() << "\n";
    } 
    uint64_t L = 0, R = 4294967297, M, kol;
    while (R - L > 1) {
        M = (R + L) / 2;
        kol = 0;
        for (uint64_t z : zahl) {
            if (z <= M) {
                ++kol;
            }
        }
        if (kol < q) {
            L = M;
        } else {
            R = M;
        }
        // std::cout << L << "  " << R << "  :" << kol <<  "\n";
    }

    uint64_t otvet = 0;
    for (uint64_t z : zahl) {
        if (z <= R && otvet < z) {
            otvet = z;
        }
    }
    writeInt(otvet);
}
