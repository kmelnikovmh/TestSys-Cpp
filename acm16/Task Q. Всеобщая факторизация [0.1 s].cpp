
// Created 05.02.2025 by Melnikov Kirill

#include <iostream>
#include <numeric>
#include <random>
#include <chrono>

int64_t N, x, y, gcc = 1;
int64_t f(__int128_t num1) {
    return (num1 * num1 + 1) % N;
}

int64_t findDevisor() {
    for (int i = 2; i <= 1000; ++i) {
        if (N % i == 0) {
            return N / i;
        }
    }
    return N;
}

int main() {
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::cin >> N;
    x = 2 + rng() % (N - 2 + 1) ;
    // std::cout << x;
    y = f(x);
    // std::cout << "   " << y << "\n";

    int64_t m = findDevisor();
    if (m != 1 && m != N) {
        std::cout << m << ' ' << N/m;
        return 0;
    }

    int k = pow(N, 1.0 / 4);
    for (int i = 1; i <= k; ++i) {
        x = f(x);
        y = f(f(y));
        gcc = std::gcd(std::abs(y - x), N);
        if (gcc != 1 && gcc != N) break;
    }

    if (gcc == 1 || gcc == N) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }
    std::cout << gcc << ' ' << N/gcc;
}
