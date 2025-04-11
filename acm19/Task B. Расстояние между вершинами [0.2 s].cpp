
// Created 25.02.2025 by Melnikov Kirill

#include <vector>
#include <queue>
#include <utility>
#include "optimization.h"

int main() {
    int n = readInt();
    int m = readInt();
    int s = readInt();
    int t = readInt();

    std::vector<std::vector<std::pair<int,int>>> matrix(n + 1);

    for (int i = 1; i <= m; ++i) {
        int a = readInt();
        int b = readInt();
        int w = readInt();
        matrix[a].push_back(std::make_pair(b, w));
        matrix[b].push_back(std::make_pair(a, w));
    }

    std::vector<int> dist(n + 1, INT_MAX);
    std::priority_queue<std::pair<int,int>> queue;
    dist[s] = 0;
    queue.push(std::make_pair(0, s));
    while (queue.size() != 0) {
        int v = queue.top().second;
        int dist_v = -queue.top().first;
        queue.pop();

        for (auto towe : matrix[v]) {
            int to = towe.first;
            int we = towe.second;
            if (dist[to] > dist_v+we) {
                dist[to] = dist_v+we;
                queue.push(std::make_pair(-dist[to], to));
            }
        }
    }
    
    if (dist[t] == INT_MAX) {
        writeInt(-1);
        return 0;
    }
    writeInt(dist[t]);
}
