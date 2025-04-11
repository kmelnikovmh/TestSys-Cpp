
// Created 22.01.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"


int dfs(int v, const std::vector<std::vector<int>> &list, std::vector<int> &mark) {
    int locmax = 0;
    for (int i : list[v]) {
        if (mark[i] == 0) {
            locmax = std::max(locmax, dfs(i, list, mark) + 1);
        } else {
            locmax = std::max(locmax, mark[i] + 1);
        }
    }

    mark[v] = locmax;
    return mark[v];
}

int main() {
    int v, e;
    v = readInt();
    e = readInt();

    std::vector<std::vector<int>> list(v + 1, std::vector<int>(0, 0));
    std::vector<int> mark(v + 1, 0);
    std::vector<int> degIn(v + 1, 0);

    int a, b;
    for (int i = 1; i <= e; ++i) {
        a = readInt();
        b = readInt();
        ++degIn[b];
        list[a].push_back(b);
    }

    int max = 0;
    for (int i = 1; i <= v; ++i) {
        if (degIn[i] == 0) {
            max = std::max(max, dfs(i, list, mark));
        }
    }

    writeInt(max);
}
