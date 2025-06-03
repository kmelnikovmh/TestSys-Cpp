
// Created 02.06.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <queue>

// First - первый побеждает из текущей вершины
// Second - первый проигрывает из текущей вершины (второй побеждает)
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    int MAX_SIZE = 300'001 + 1;
    std::vector<std::vector<int>> graph(MAX_SIZE);
    std::vector<std::vector<int>> re_graph(MAX_SIZE);
    std::vector<int> out_degree(MAX_SIZE);
    std::vector<int> status(MAX_SIZE);  // First 1, Second -1, Draw 0

    while (std::cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            graph[i].clear();
            re_graph[i].clear();
            out_degree[i] = 0;
        }

        int a, b;
        for (int i = 1; i <= m; ++i) {
            std::cin >> a >> b;
            graph[a].push_back(b);
            ++out_degree[a];
            re_graph[b].push_back(a);
        }

        // Game
        std::queue<int> queue;
        for (int i = 1; i <= n; ++i) {
            if (out_degree[i] == 0) {
                status[i] = -1;
                queue.push(i);
                continue;
            }
            status[i] = 0;
        }
        
        int v;  // u, v
        while (!queue.empty()) {
            v = queue.front();
            queue.pop();

            for (auto from : re_graph[v]) {
                if (status[from] != 0) continue;

                if (status[v] == 1) {
                    --out_degree[from];
                    if (out_degree[from] == 0) {
                        status[from] = -1;
                        queue.push(from);
                    }
                }
                if (status[v] == -1) {
                    status[from] = 1;
                    queue.push(from);
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            int st = status[i];
            if (st == 1) std::cout << "FIRST\n";
            if (st == 0) std::cout << "DRAW\n";
            if (st == -1) std::cout << "SECOND\n";
        }
    }
}