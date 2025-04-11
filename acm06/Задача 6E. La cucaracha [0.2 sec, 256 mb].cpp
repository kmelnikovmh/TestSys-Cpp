
// Created 16.10.2024 by Melnikov Kirill

#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include "optimization.h"

int main() {
    int64_t n, x, y, timeMax = -1e11, timeMin = 1e11, sumMax = -1e11, sumMin = 1e11;
    n = readInt();
    std::vector<std::pair<int64_t, int64_t>> tochki;
    tochki.reserve(n);
    for (int64_t i = 1; i <= n; ++i) {
        x = readInt();
        y = readInt();
        tochki.push_back({x,y});
        timeMax = std::max(timeMax, x-y);
        timeMin = std::min(timeMin, x-y);
        sumMax = std::max(sumMax,x+y);
        sumMin = std::min(sumMin, x+y);
    }

    long double X = (((timeMax+timeMin)*1.0)/2 + ((sumMax+sumMin)*1.0)/2) / 2;
    long double Y = (-((timeMax+timeMin)*1.0)/2 + ((sumMax+sumMin)*1.0)/2) / 2;
    int64_t xw, yw;
    int64_t max = 0, itog = 1e11, m = 0;
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            xw = std::floor(X);
            yw = std::floor(Y);
        } else if (i == 1) {
            xw = std::floor(X);
            yw = std::ceil(Y);
        } else if (i == 2) {
            xw = std::ceil(X);
            yw = std::floor(Y);
        } else {
            xw = std::ceil(X);
            yw = std::ceil(Y);
        }
        max = 0;
        for (auto [x,y] : tochki) {
            max = std::max(max, abs(x-xw) + abs(yw-y));
        }
        if (max < itog) {
            itog = max;
            m = i;
        }
    }
    if (m == 0) {
        xw = std::floor(X);
        yw = std::floor(Y);
        writeInt(xw, ' ');
        writeInt(yw);
    } else if (m == 1) {
        xw = std::floor(X);
        yw = std::ceil(Y);
        writeInt(xw, ' ');
        writeInt(yw);
    } else if (m == 2) {
        xw = std::ceil(X);
        yw = std::floor(Y);
        writeInt(xw, ' ');
        writeInt(yw);
    } else {
        xw = std::ceil(X);
        yw = std::ceil(Y);
        writeInt(xw, ' ');
        writeInt(yw);
    }
}
