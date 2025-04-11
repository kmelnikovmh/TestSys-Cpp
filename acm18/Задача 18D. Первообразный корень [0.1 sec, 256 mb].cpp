
// Created 16.02.2025 by Melnikov Kirill

#include <vector>
#include <random>
#include <chrono>
#include <cmath>
#include "optimization.h"

int pow(int64_t a, int pow, int mod) {
    int64_t itog = 1;
    while (pow > 0) {
        if (pow % 2 != 0) {
            itog = (itog * a) % mod;
        }
        a = (a * a) % mod;
        pow = pow / 2;
    }
    return itog;
}


int main() {
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::vector<int> delit_phi;
    delit_phi.reserve(1000);

    while (!seekEof()) {
        int p = readInt();
        int phi = p - 1;

        if (p == 2) {
            writeInt(1, '\n');
            continue;
        }

        for (int i = 2; i * i <= phi; ++i) {
            if (phi % i == 0) {
                delit_phi.push_back(i);
                while (phi % i == 0) {
                    phi = phi / i;
                }
            }
        }
        if (phi != 1) delit_phi.push_back(phi);
        phi = p - 1;

        int dot = 1;
        while (true) {
            dot = 2 + rng() % (phi - 2 + 1);
            bool next = false;
            for (auto d : delit_phi) {
                if (pow(dot, phi / d, p) == 1) {
                    next = true;
                    break;
                }
            }
            if (next == false) {
                break;
            }
        }
        writeInt(dot, '\n');
        delit_phi.clear();
    }
}
