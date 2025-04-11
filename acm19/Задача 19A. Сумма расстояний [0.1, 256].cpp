
// Created 25.02.2025 by Melnikov Kirill

#include <vector>
#include <deque>
#include "optimization.h"

int main() {
    int n = readInt();
    int m = readInt();
    std::vector<std::vector<int>> matrix(n + 1);
    for (int i = 1; i <= m; ++i) {
        int a = readInt();
        int b = readInt();
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    std::deque<int> deque;
    std::vector<int> dist(n + 1, -1);
    int sum = 0;
    for (int s = 1; s <= n; ++s) {
        deque.push_back(s);
        dist[s] = 0;
        while(deque.size() != 0) {
            int v = deque.front();
            for (auto neigh : matrix[v]) {
                if (dist[neigh] == -1) {
                    dist[neigh] = dist[v] + 1;
                    sum += dist[neigh];
                    deque.push_back(neigh);
                }
            }
            deque.pop_front();
        }
        dist.assign(n + 1, -1);
    }
    writeInt(sum / 2);
}
