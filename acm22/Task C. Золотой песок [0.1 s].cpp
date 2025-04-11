
// Created 19.03.2025 by Melnikov Kirill

#include <vector>
#include <algorithm>
#include "optimization.h"

struct foo {
    int a;
    int b;
    bool operator<(const foo& lhs) const {
        return a * lhs.b > b * lhs.a;
    }
};

int main() {
    int n = readInt();
    int v = readInt();
    std::vector<foo> vec(n);

    for (auto& [a,b] : vec) {
        a = readInt();
        b = readInt();
    }

    int k = 0;
    std::sort(vec.begin(), vec.end());
    double answer;

    int i = 0l;
    for (; i < vec.size() && v >= k + vec[i].b; ++i) {
        answer += vec[i].a;
        k += vec[i].b;
    }
    if (vec.size() > i && !(v >= k + vec[i].b)) {
        answer += (v - k) * (double(vec[i].a) / double(vec[i].b));
    }

    writeDouble(answer, 4);
}
