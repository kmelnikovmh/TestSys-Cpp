
// Created 18.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <numeric>

void dfs(int a, const std::vector<std::vector<int>> &list, std::vector<int> &mark) {
    mark[a] = 1;
    
    for (auto v : list[a]) {
        if (mark[v] != 1) {
            dfs(v, list, mark);
        }
    }
    return;
}


int main() {
    int v, e;
    std::cin >> v >> e;
    // std::vector<std::vector<int>> MS(v + 1, std::vector<int>(v + 1, 0));
    std::vector<std::vector<int>> list(v + 1, std::vector<int>(0, 0));
    std::vector<int> mark(v + 1, 0);

    int i, j;
    for (int l = 1; l <= e; ++l) {
        std::cin >> i >> j;
        // MS[i][j] = 1;
        // MS[j][i] = 1;
        list[i].reserve(v);
        list[i].push_back(j);
        list[j].reserve(v);
        list[j].push_back(i);
    }

    dfs(1, list, mark);

    /*for (auto z : mark) {
        std::cout << z << " ";
    }*/

    if (std::accumulate(mark.begin(), mark.end(), 0ll) == v && e == v - 1) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
