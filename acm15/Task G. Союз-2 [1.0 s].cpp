
// Created 29.01.2025 by Melnikov Kirill

#include <vector>
#include <bitset>
#include "optimization.h"

int main() {
    int n, m;
    n = readInt();
    m = readInt();

    std::vector<std::bitset<10001>> mat(n + 1, 0);
    std::vector<std::pair<int, int>> edge;
    edge.reserve(m);

    int a, b;    
    for (int i = 1; i <= m; ++i) {
        a = readInt();
        b = readInt();

        if (mat[a][b] != 1) {
            if (a < b) {
                edge.push_back(std::make_pair(a, b));
            } else {
                edge.push_back(std::make_pair(b, a));
            }
        }
        mat[a][b] = 1;
        mat[b][a] = 1;
    }


    int64_t count = 0, A = 0;
    for (auto e : edge) {
        a = e.first;
        b = e.second;

        if ((mat[a] & mat[b]) != 0) {
            count = count + (mat[a] & mat[b]).count();
        }
    }

    writeDouble((double)(count / 3) / 4, 10);
    writeChar('\n');
}
