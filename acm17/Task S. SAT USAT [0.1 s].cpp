
// Created 12.02.2025 by Melnikov Kirill

#include <vector>
#include <random>
#include "optimization.h"

// 85 баллов из 100

int main() {
    std::mt19937_64 rng(2394);
    int n, m;
    n = readInt();
    m = readInt();
    std::vector<int> xVec(n + 1, 1);
    std::vector<std::vector<int>> klos(m + 1, std::vector<int>(7, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= 5; j = j + 2) {
            klos[i][j] = readInt();
            klos[i][j+1] = readInt();
        }
    }

    bool br;
    int x1, x2, x3;
    int xRand;
    while (true) {
        for (int i = 1; i <= 0.5 * n; ++i) {
            xVec[i] = rng() % (2);
        }

        for (int k = 1; k <= 3 * m; ++k) {
            br = false;
            for (int i = 1; i <= m; ++i) {
                int x1Val = klos[i][2];
                int x2Val = klos[i][4];
                int x3Val = klos[i][6];
                if (!(xVec[klos[i][1]] == x1Val || xVec[klos[i][3]] == x2Val || xVec[klos[i][5]] == x3Val)) {
                    br = true;
                    x1 = klos[i][1];
                    x2 = klos[i][3];
                    x3 = klos[i][5];
                    break;
                }
            }
            if (br == false) break;
            xRand = 1 + rng() % 3;
            if (xRand == 1) {
                xVec[x1] = 1 - xVec[x1];
            } else if (xRand == 2) {
                xVec[x2] = 1 - xVec[x2];
            } else if (xRand == 3) {
                xVec[x3] = 1 - xVec[x3];
            }
        }

        if (br == true) {
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            writeInt(xVec[i]);
        }
        break;
    }
}
