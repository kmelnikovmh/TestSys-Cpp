
// Created 09.10.2024 by Melnikov Kirill

#include <algorithm>
#include <utility>
#include <vector>
#include "optimization.h"

int main() {
    int n, m;
    n = readInt();
    m = readInt();
    std::vector<std::pair<int32_t, int32_t>> otrezki, tochki;
    otrezki.reserve(2*n);
    tochki.reserve(2*m);
    int32_t sum[m];
    int32_t a, b, z;
    for (int32_t i = 0; i < n; ++i) {
        a = readInt();
        b = readInt();
        otrezki.push_back({std::min(a,b), +1});
        otrezki.push_back({std::max(a,b)+1, -1});
    }
    std::sort(otrezki.begin(), otrezki.end());

    for (int i = 0; i < m; ++i) {
        z = readInt();
        tochki.push_back({z, i});
    }
    std::sort(tochki.begin(), tochki.end());

    int32_t j = 0, pref = 0;
    for (auto pair : tochki) {

        while(otrezki[j].first <= pair.first && j < otrezki.size()) {
            pref += otrezki[j].second;
            ++j;
        }
        sum[pair.second] = pref;
    }
    for (int32_t z : sum) {
        writeInt(z, ' ');
    }
}
