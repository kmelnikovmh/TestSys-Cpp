
// Created 05.03.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"

struct edge {
    int a;
    int b;
    int64_t w;
};

void dfs(int v, std::vector<int> &used, std::vector<std::vector<int>> &matrix) {
    used[v] = 1;
    for (auto to : matrix[v]) {
        if (used[to] == 0) {
            dfs(to,used,matrix);
        }
    }
}

int main() {
    int n = readInt();
    int m = readInt();
    int s = readInt();
    std::vector<std::vector<int>> matrix(n + 1);
    std::vector<edge> edges(m);
    for (int64_t i = 0; i < m; ++i) {
        int a = readInt();
        int b = readInt();
        int64_t w = readInt<long long>();
        matrix[a].push_back(b);
        edges[i] = {a, b, w};
    }
    int64_t Inf = INT64_MAX;
    std::vector<int64_t> dist(n + 1, Inf);
    std::vector<int> used(n + 1);
    dist[s] = 0;
    for (int k = 1; k <= n + 1; ++k) {
        for (auto t : edges) {
            if (k == n && dist[t.a] != Inf && dist[t.b] > dist[t.a] + t.w && used[t.b] == 0) {
                dfs(t.b, used,matrix);
            } else if (dist[t.a] != Inf && dist[t.b] > dist[t.a] + t.w) {
                dist[t.b] = dist[t.a] + t.w;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 1) {
            writeChar('-');
            writeChar('\n');
        } else if (dist[i] == Inf) {
            writeChar('*');
            writeChar('\n');
        } else {
            writeInt(dist[i], '\n');
        }
    }
}
