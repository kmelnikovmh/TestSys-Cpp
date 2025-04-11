
// Created 05.03.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"

struct edge {
    int a;
    int b;
    int w;
};

int main() {
    int n = readInt();
    std::vector<edge> edges;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int w = readInt();
            if (w == 100'000) continue;
            edges.push_back({i, j, w});
        }
        edges.push_back({s, i, 0});
    }

    int Inf = INT_MAX;
    std::vector<int> dist(n + 1, Inf);
    std::vector<int> puti(n + 1, -1);
    dist[s] = 0;
    int x = -1;
    for (int k = 1; k <= n + 1; ++k) {
        for (auto &t : edges) {
            if (dist[t.a] != Inf && dist[t.b] > dist[t.a] + t.w) {
                if (k != n + 1) {
                    dist[t.b] = dist[t.a] + t.w;
                    puti[t.b] = t.a;
                } else {
                    puti[t.b] = t.a;
                    x = t.b;
                    break;
                }
            }
        }
    }

    if (x != -1) {
        writeWord("YES\n");
        std::vector<int> ans;

        for (int i = 1; i <= n; ++i) {
            x = puti[x];
        }

        int start = x;
        ans.push_back(x);
        start = puti[start];
        while(start != x) {
            ans.push_back(start);
            start = puti[start];
        }
        std::reverse(ans.begin(), ans.end());
        writeInt(ans.size(), '\n');
        for (auto z : ans) {
            writeInt(z, ' ');
        }
    } else {
        writeWord("NO");
    }
}
