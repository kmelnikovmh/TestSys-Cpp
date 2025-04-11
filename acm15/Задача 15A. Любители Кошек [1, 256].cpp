
// Created 29.01.2025 by Melnikov Kirill

#include <vector>
#include <set>
#include "optimization.h"

int main() {
    int n,m;
    n = readInt();
    m = readInt();

    std::vector<std::vector<int>> mat(n + 1, std::vector<int>(n + 1, 0));
    std::set<std::pair<int, int>> edge;

    int a, b;    
    for (int i = 1; i <= m; ++i) {
        a = readInt();
        b = readInt();

        mat[a][b] = mat[b][a] = 1;

        if (a < b) {
            edge.emplace(a, b);
        } else {
            edge.emplace(b, a);
        }
    }

    int count = 0, A = 0;
    for (auto e : edge) {
        a = e.first;
        b = e.second;

        for (int c = 1; c <= n; ++c) {
            if (c == a || c == b) continue;
            if ((mat[a][c] == 1) && (mat[b][c] == 1)) {
                ++count;
            }
        }
    }

    writeInt(count / 3);
}
