
// Created 05.02.2025 by Melnikov Kirill

#include <string>
#include <numeric>
#include <random>
#include <chrono>
#include "optimization.h"

int64_t N, x, y, Tgcc = 1, P = 1;
std::string s = "IMPOSSIBLE\n";
int64_t f(__int128_t num1) {
    return (num1 * num1 + 1) % N;
}

int64_t findDevisor() {
    for (int i = 2; i <= 30'000; ++i) {
        if (N % i == 0) {
            return N / i;
        }
    }
    return N;
}

int64_t mul(__int128_t a, __int128_t b) {
    return (a * b) % N;
}

int main() {
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    while (!seekEof()) {
        N = readInt<long long>();
        x = 2 + rng() % (N - 2 + 1);
        y = x;

        int64_t m = findDevisor();
        if (m != 1 && m != N) {
            // std::cout << m << ' ' << N/m;
            writeInt<long long>(m, ' ');
            writeInt<long long>(N / m, '\n');
            continue;
        }
        if (N <= 30'000) {
            writeWord(s.c_str());
            continue;
        }

        int k = pow(N, 1.0 / 4);
        int j = 1;
        for (int i = 1; i <= 2 * k; ++i) {
            x = f(x);
            y = f(f(y));
            if (x < y) {
                P = mul(P, y - x);
            } else {
                P = mul(P, x - y);
            }

            if (j == 64) {
                Tgcc = std::gcd(P, N);
                P = 1;
                j = 1;
                if (Tgcc != 1 && Tgcc != N) {
                    break;
                }
            }
            ++j;
        }

        if (Tgcc == 1 || Tgcc == N) {
            writeWord(s.c_str());
        } else {
            writeInt<long long>(Tgcc, ' ');
            writeInt<long long>(N/Tgcc, '\n');
        }
    }
}
