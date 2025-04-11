
// Created 09.10.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <algorithm>
#include "optimization.h"

int main() {
    int n, m, l;
    // std::cin >> n >> m  >> l;
    n = readInt();
    m = readInt();
    l = readInt();
    std::vector<int32_t> nki[n], mki[m];
    int32_t z;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++ j) {
            z = readInt();
            nki[i].push_back(z);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < l; ++ j) {
            z = readInt();
            mki[i].push_back(z);
        }
    }

    int q;
    q = readInt();
    for (int i = 1; i <= q; ++i) {
        int ni, mi;
        ni = readInt();
        mi = readInt();
        std::vector<int32_t>& nnow = nki[ni-1];
        std::vector<int32_t>& mnow = mki[mi-1];
        int32_t R = l-1, L = 0, m, mink, min=1000000000;
        while (L <= R) {
            m = (R + L) / 2;
            int32_t tek = std::max(nnow[m], mnow[m]);
            if (tek < min) {
                mink = m;
                min = tek;
            }
            if (nnow[m] >= mnow[m]) {
                R = m - 1;
            } else {
                L = m + 1;
            }
        }
        writeInt(mink + 1, '\n');
    }
}
