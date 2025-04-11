
// Created 16.02.2025 by Melnikov Kirill

#include <vector>
#include <random>
#include <chrono>
#include "optimization.h"

int main() {
    std::vector<std::vector<double>> okr(3, std::vector<double>(3, 0));
    double l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            okr[i][j] = readDouble();
        }
        l = std::min(l, okr[i][0] - okr[i][2]);
        r = std::max(r, okr[i][0] + okr[i][2]);
        u = std::max(u, okr[i][1] + okr[i][2]);
        d = std::min(l, okr[i][1] - okr[i][2]);
    }

    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<> gen_lr(l, r);
    std::uniform_real_distribution<> gen_du(d, u);
    double n = 1'000'000;
    double k = 0;
    double S = (u-d) * (r-l);
    double dotX, dotY;
    for (int i = 1; i <= n; ++i) {
        dotX = gen_lr(rng);
        dotY = gen_du(rng);
        if (((okr[0][0] - dotX) * (okr[0][0] - dotX) + (okr[0][1] - dotY) * (okr[0][1] - dotY) <= okr[0][2] * okr[0][2]) &&
            ((okr[1][0] - dotX) * (okr[1][0] - dotX) + (okr[1][1] - dotY) * (okr[1][1] - dotY) <= okr[1][2] * okr[1][2]) &&
            ((okr[2][0] - dotX) * (okr[2][0] - dotX) + (okr[2][1] - dotY) * (okr[2][1] - dotY) <= okr[2][2] * okr[2][2])) {
            ++k;
            // writeInt(1, '\n');
        }
    }
    writeDouble((k / n) * S, 10);
}
