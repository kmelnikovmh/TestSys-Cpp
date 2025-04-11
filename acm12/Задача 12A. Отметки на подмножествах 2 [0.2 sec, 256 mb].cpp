
// Created 14.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include "optimization.h"

void add(int set, /*std::unordered_set<int> &maskFirst,*/ std::vector<int> &maskInc) {
    if (maskInc[set] == 1) return;

    // maskFirst.insert(set);
    maskInc[set] = 1;

    int size = 20, buff = set;
    for (int i = 0; i < size + 1; ++i) {
        if ((buff >> i) & 1) {
            buff = set & ~(1 << i);
            if (buff != set) add(buff, /*maskFirst,*/ maskInc);
        }
    }
}

void remove(int set, /*std::unordered_set<int> &maskFirst,*/ std::vector<int> &maskInc, std::vector<int> &maskRem) {
    if (maskRem[set] == 1) return;

    if (maskInc[set] == 1) {
        // maskFirst.erase(set);
        maskInc[set] = 0;
    }
    maskRem[set] = 1;

    int size = 20, buff = set;
    for (int i = 0; i < size + 1; ++i) {
        if ((buff >> i) & 1) {
            buff = set & ~(1 << i);
            if (buff != set) remove(buff, /*maskFirst,*/ maskInc, maskRem);
        }
    }
}

int main() {
    int n, x, y;
    int k, zahl;
    n = readInt();
    x = readInt();
    y = readInt();

    // std::unordered_set<int> maskFirst;
    std::vector<int> maskInc(1 << (n + 1), 0);
    std::vector<int> maskRem(1 << (n + 1), 0);

    for (int i = 0; i < x; ++i) {
        k = readInt();

        int set = 0;
        for (int j = 0; j < k; ++j) {
            zahl = readInt();
            set = set | (1 << zahl);
        }
        add(set, /*maskFirst,*/ maskInc);
    }

    /*for (auto z : maskFirst) {
        std::cout << z << "\n";
    }*/

    for (int i = 0; i < y; ++i) {
        k = readInt();

        int set = 0;
        for (int j = 0; j < k; ++j) {
            zahl = readInt();
            set = set | (1 << zahl);
        }
        remove(set, /*maskFirst,*/ maskInc, maskRem);
    }

    /*std::cout << "\n";
    for (auto z : maskFirst) {
        std::cout << z << "\n";
    }*/

    writeInt(std::accumulate(maskInc.begin(), maskInc.end(), 0ll));
    //std::cout << maskFirst.size();
}
