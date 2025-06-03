
// Created 26.05.2025 by Melnikov Kirill

#include <iostream>
#include <vector>

int MAX_N = 100'001;
std::vector<std::vector<int>> tree(100'001);
std::vector<int> time_in(100'001), time_out(100'001);
int time_dfs = 0;

void dfs(int v) {
    ++time_dfs;
    time_in[v] = time_dfs;

    for (auto to : tree[v]) {
        dfs(to);                // Плевать на условия, ибо дерево
    }

    ++time_dfs;
    time_out[v] = time_dfs;
}

bool is_father(int a, int b) {
    return time_in[a] <= time_in[b] && time_out[b] <= time_out[a];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        int v;
        std::cin >> v;
        tree[v].push_back(i);
    }

    dfs(0);

    int m;
    std::cin >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << is_father(a, b) << "\n";
    }
}