
// Created 18.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include "optimization.h"

void dfs(int a, int i, const std::vector<std::vector<int>> &list, std::vector<int> &mark) {
    mark[a] = i;
    
    for (auto v : list[a]) {
        if (mark[v] == 0) {
            // std::cout << "vizv doch " << v << "\n";
            dfs(v, i, list, mark);
        }
    }
    return;
}


int main() {
    int v, e;
    // std::cin >> v >> e;
    v = readInt();
    e = readInt();
    // std::vector<std::vector<int>> MS(v + 1, std::vector<int>(v + 1, 0));
    std::vector<std::vector<int>> list(v + 1, std::vector<int>(0, 0));
    std::vector<int> mark(v + 1, 0);

    int i, j;
    for (int l = 1; l <= e; ++l) {
        // std::cin >> i >> j;
        i = readInt();
        j = readInt();

        // MS[i][j] = 1;
        // MS[j][i] = 1;
        list[i].push_back(j);
        list[j].push_back(i);
    }

    i = 1;
    for (int j = 1; j <= v; ++j) {
        if (mark[j] == 0) {
            // std::cout << "vizv " << j << "\n";
            dfs(j, i, list, mark);
            ++i;
        }
    }

    /*for (auto z : mark) {
        std::cout << z << " ";
    }*/

    // std::cout << i - 1 << "\n";
    writeInt(i - 1, '\n');
    for (int j = 1; j <= v; ++j) {
        // std::cout << mark[j] << " ";
        writeInt(mark[j], ' ');
    }
}
