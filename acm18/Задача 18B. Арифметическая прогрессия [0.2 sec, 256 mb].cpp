
// Created 16.02.2025 by Melnikov Kirill

#include <vector>
#include <random>
#include <algorithm>
#include "optimization.h"

int l, l_val, r, r_val, k=1, dot, dot_val, d, up;
int main() { 
    int n = readInt();
    std::vector<int> vec(2 * n);
    std::mt19937_64 rng(777);

    int max_val = 0;
    int min_val = INT32_MAX;
    for (int i = 0; i < 2 * n; ++i) {
        vec[i] = readInt();
        max_val = std::max(vec[i], max_val);
        min_val = std::min(vec[i], min_val);
    }

    std::sort(vec.begin(), vec.end());

    std::vector<int> delit;
    while (true) {
        dot = rng() % (2 * n);
        dot_val = vec[dot];
        up = std::abs(dot_val - vec[rng() % (2 * n)]);

        for (int i = 1; i * i <= up; ++i) {
            if (up % i == 0) {
                delit.push_back(i);
            }
        }
        if (up != 1) delit.push_back(up);

        for (int i = 1; i <= 1000; ++i) {
            k = 1;
            d = delit[rng() % (delit.size() + 1)];

            r_val = dot_val;
            r = dot + 1;
            while (r < 2 * n) {
                if (k == n) {
                    break;
                }
                if (vec[r] - r_val > d) {
                    break;
                }
                if (vec[r] - r_val == d) {
                    ++k;
                    r_val = vec[r];
                }
                ++r;
            }

            l_val = dot_val;
            l = dot - 1;
            while (l >= 0) {
                if (k == n) {
                    break;
                }
                if (l_val - vec[l] > d) {
                    break;
                }
                if (l_val - vec[l] == d) {
                    ++k;
                    l_val = vec[l];
                }
                --l;
            }
            if (k == n) {
                break;
            }
        }
        if (k == n) {
            break;
        }
        delit.clear();
    }
    writeInt(l_val, ' ');
    writeInt(d, '\n');
}
