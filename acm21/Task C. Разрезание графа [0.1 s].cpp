
// Created 11.03.2025 by Melnikov Kirill

#include <vector>
#include <unordered_map>
#include "optimization.h"

struct Edge {
    int a, b;
    bool operator==(const Edge &other) const {
        return (a == other.a && b == other.b);
    }
};

struct Hash {
    size_t operator()(const Edge& other) const {
        return 8 * other.a + other.b;
    }
};

struct Request {
    char type;
    int a;
    int b;
};

int p[50'001];
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
    int k = readInt();
    std::vector<Request> req(k);
    std::unordered_map<Edge, int, Hash> edges;
    init(n);
    for (int i = 1; i <= m; ++i) {
        int a = readInt();
        int b = readInt();
        if (a > b) std::swap(a, b);
        edges[{a, b}] = 1;
    }
    for (int i = 0; i < k; ++i) {
        char type[4];
        readWord(type);
        int a = readInt();
        int b = readInt();
        if (type[0] == 'a') {
            req[i] = {'a', a, b};
        } else {
            req[i] = {'c', a, b};
            if (a > b) std::swap(a, b);
            if (a != b && edges[{a, b}] == 1) {
                edges[{a, b}] = 0;
            };
        }
    }

    for (auto &z : edges) {
        if (z.second == 1) {
            join(z.first.a, z.first.b);
        }
    }

    std::vector<int> ans;
    ans.reserve(k / 2);
    for (int i = k - 1; i >= 0; --i) {
        auto &[t, a, b] = req[i];
        if (t == 'a') {
            if (get(a) == get(b)) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        } else {
            join(a, b);
        }
    }

    for (int i = static_cast<int>(ans.size()) - 1; i >= 0; --i) {
        if (ans[i] == 1) {
            writeWord("YES\n");
        } else {
            writeWord("NO\n");
        }
    }
}   
