
// Created 11.03.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"

struct Edge {
    int a, b, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int p[20'001];
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
}
int get(int i) {
    if (p[i] == i) {
        return i;
    } else {
        p[i] = get(p[i]);
        return p[i];
    }
}
void join(int a, int b) {
    a = get(a), b = get(b);
    p[a] = b;
}

int main() {
    int n = readInt();
    int m = readInt();
    init(n);
    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int a = readInt();
        int b = readInt();
        int w = readInt();
        edges[i] = {a, b, w};
    }
    std::sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto &e : edges) {
        int a = e.a;
        int b = e.b;
        int w = e.w;
        // writeInt(w, ' ');
        if (get(a) == get(b)) {
            continue;
        } else {
            join(a, b);
            ans += w;
        }
    }
    writeInt(ans);
}   
