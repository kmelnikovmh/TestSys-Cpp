
// Created 20.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include "optimization.h"

int main() {
    int N;
    N = readInt();

    std::vector<int> f(2 * N);
    f[1] = 0;
    int i = 2;
    for (; i <= N; ++i) {
        if (i % 2 == 0 && i % 3 == 0) {
            f[i] = std::min({f[i-1], f[i/2], f[i/3]}) + 1;
        } else if (i % 2 == 0 && i % 3 != 0) {
            f[i] = std::min(f[i-1], f[i/2]) + 1;
        } else if (i % 3 == 0 && i % 2 != 0) {
            f[i] = std::min(f[i-1], f[i/3]) + 1;
        } else {
            f[i] = f[i-1] + 1;
        }
    }

    writeInt(f[N], '\n');
 
    int j = N;
    std::set<int> ans = {N};
    while (true){
        if (j == 1) break;

        if (j % 3 == 0 && f[j] - f[j/3] == 1) {
            j = j / 3;
            ans.insert(j);
        }
        if (j % 2 == 0 && f[j] - f[j/2] == 1) {
            j = j / 2;
            ans.insert(j);
        }
        if (f[j] - f[j-1] == 1) {
            j = j - 1;
            ans.insert(j);
        }   
    }

    for (auto &z : ans) {
        writeInt(z, ' ');
    }
}
