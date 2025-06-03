
// Created 26.05.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <utility>

int MAX_N_TZ = 150'001;
int MAX_DEEP_TZ = 18;           // 2 ^ 18 > 150'001
std::vector<std::vector<std::pair<int, int>>> tree(MAX_N_TZ);
std::vector<int> depth(MAX_N_TZ), dist(MAX_N_TZ);
std::vector<std::vector<int>> up(MAX_DEEP_TZ, std::vector<int>(MAX_N_TZ));

void dfs(int v, int father) {
    up[0][v] = father;
    for (int i = 1; i < MAX_DEEP_TZ; ++i) {
        up[i][v] = up[i-1][up[i-1][v]];
    }

    for (auto &[to, w] : tree[v]) {
        if (to == father) continue;

        depth[to] = depth[v] + 1;
        dist[to] = dist[v] + w;
        dfs(to, v);
    }
}

int jump(int v, int dist) {
    for (int k = 0; k < MAX_DEEP_TZ; ++k) {
        if (!(dist & (1 << k))) continue;
        v = up[k][v];
    }
    return v;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) std::swap(a, b);
    a = jump(a, depth[a] - depth[b]);

    for (int k = MAX_DEEP_TZ - 1; k >= 0; --k) {
        if (up[k][a] == up[k][b]) continue;

        a = up[k][a];
        b = up[k][b];
    }

    if (a == b) return a;
    return up[0][a];
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    
    int u, v, w;
    for (int i = 1; i < n; ++i) {
        std::cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    depth[0] = 0;
    dist[0] = 0;
    dfs(0, 0);      // up[0][root] = root;

    int m, a, b;
    std::cin >> m;
    for (int i = 1; i <= m; ++i) {
        std::cin >> a >> b;
        int father = lca(a, b);
        std::cout << - (2 * dist[father] - dist[a] - dist[b]) << "\n";
    }
}