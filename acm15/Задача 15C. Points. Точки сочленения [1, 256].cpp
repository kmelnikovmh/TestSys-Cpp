
// Created 29.01.2025 by Melnikov Kirill

#include <vector>
#include <set>
#include "optimization.h"

std::vector<std::vector<int>> graph;
std::vector<int> buff, begin, end;
std::set<int> ans;
int t = 1;

void dfs(int v, int parent) {
    int count = 0;
    buff[v] = 1;
    begin[v] = t;
    end[v] = t;
    ++t;

    for (auto to : graph[v]) {
        if (to != parent && buff[to] == 1) {
            end[v] = std::min(end[v], begin[to]);
        }
        if (to != parent && buff[to] == 0) {
            ++count;
            dfs(to, v);
            end[v] = std::min(end[v], end[to]);
            if (parent !=- 1 && (begin[v] <= end[to])) {
                ans.insert(v);
            }
        }
    }
    if (parent == -1 && count > 1) {
        ans.insert(v);
    }
}

int main() {
    int n, m;
    n = readInt();
    m = readInt();

    graph = std::vector(n + 1, std::vector<int>(0));
    buff = std::vector(n + 1, 0);
    begin = std::vector(n + 1, 0);
    end = std::vector(n + 1, 0);

    int a, b;
    for (int i = 1; i <= m; ++i) {
        a = readInt();
        b = readInt();
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (buff[i] == 0) {
            dfs(i, -1);
        }
    }

    writeInt(ans.size(), '\n');
    for (auto v : ans) {
        writeInt(v, '\n');
    }
}
