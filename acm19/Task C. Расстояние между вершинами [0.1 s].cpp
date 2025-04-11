
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

    std::vector<std::pair<int,int>> dist(n + 1, std::make_pair(INT_MAX, 0));
    std::priority_queue<std::pair<int,int>> queue;
    dist[s] = std::make_pair(0, s);
    queue.push(std::make_pair(0, s));
    while (queue.size() != 0) {
        int v = queue.top().second;
        int dist_v = -queue.top().first;
        queue.pop();

        for (auto towe : matrix[v]) {
            int to = towe.first;
            int we = towe.second;
            if (dist[to].first > dist_v + we) {
                dist[to].first = dist_v + we;
                dist[to].second = v;
                queue.push(std::make_pair(-dist[to].first, to));
            }
        }
    }
    
    if (dist[t].first == INT_MAX) {
        writeInt(-1);
        return 0;
    }
    
    writeInt(dist[t].first, '\n');
    std::vector<int> ans;
    int v = t;
    ans.push_back(v);
    while (v != s) {
        v = dist[v].second;
        ans.push_back(v);
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        writeInt(ans[i], ' ');
    }
}
