
// Created 11.03.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"

struct Edge {
    int a, b, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int p[100'001], rank[100'001];
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        rank[i] = 1;
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
void join(int a, int b){
    a = get(a), b = get(b);
    p[a] = b;
    rank[b] += rank[a];
}

int main() {
    int t = readInt();

    for (int k = 1; k <= t; ++k) {
        int n = readInt();
        int par[n+1];
        p[0] = 0;
        rank[0] = 1;
        for (int i = 1; i <= n - 1; ++i) {
            p[i] = i;
            par[i] = readInt();
            rank[i] = 1;
        }

        int max = -1;
        for (int i = 1; i <= n - 1; ++i) {
            int x = readInt();
            join(x, par[x]);
            max = std::max(max, rank[get(x)]);
            writeInt(max, ' ');
        }
        writeChar('\n');
    }
}  
