
// Created 05.03.2025 by Melnikov Kirill

#include <vector>
#include <deque>
#include "optimization.h"

int main() {
    int64_t n = readInt<long long>();
    int64_t m = readInt<long long>();
    int64_t s = readInt<long long>();
    int64_t t = readInt<long long>();
    std::vector<std::vector<std::pair<int64_t, int64_t>>> matrix(n + 1);
    for (int64_t i = 1; i <= m; ++i) {
        int64_t a = readInt<long long>();
        int64_t b = readInt<long long>();
        int64_t w = readInt<long long>();
        matrix[a].push_back(std::make_pair(b, w));
    }

    std::deque<int64_t> deque;
    std::vector<int64_t> queque(n + 1, 0);
    std::vector<int64_t> dist(n + 1, 1'000'000'000'000'000'000);
    dist[s] = 0;
    queque[s] = 1;
    deque.push_back(s);
    while(deque.size() != 0) {
        int64_t v = deque.front();
        deque.pop_front();
        queque[v] = 0;
        for (auto neigh : matrix[v]) {
            if (dist[neigh.first] > dist[v] + neigh.second) {
                dist[neigh.first] = dist[v] + neigh.second;
                if (queque[neigh.first] == 0) {
                    queque[neigh.first] = 1;
                    deque.push_back(neigh.first);
                }
            }
        }
    }
    
    writeInt(dist[t]);
}
