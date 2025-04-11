
// Created 29.01.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include "optimization.h"

std::vector<std::vector<int>> graph, tgraph;
std::vector<int> buff, topsort, component, ans;

void dfs(int v) {
    buff[v] = 1;
    for (auto to : graph[v]) {
        if (buff[to] == 0) {
            dfs(to);
        }
    }
    topsort.push_back(v);
}

void dfsCo(int v, int co) {
    component[v] = co;
    for (auto to : tgraph[v]) {
        if (component[to] == -1) {
            dfsCo(to, co);
        }
    }
}

int main() {
    int n, m;
    while(!seekEof()) {
        n = readInt();
        m = readInt();

        graph = std::vector(2 * n, std::vector<int>(0));
        tgraph = std::vector(2 * n, std::vector<int>(0));
        buff = std::vector(2 * n, 0);
        topsort = std::vector<int>();
        component = std::vector(2 * n, -1);

        int i1, i2, e1, e2;
        for (int i = 1; i <= m; ++i) {
            i1 = readInt();
            e1 = readInt();
            i2 = readInt();
            e2 = readInt();

            int a, b;
            if (e1 == 1) {
                a = i1 + n; // a -> not a
            } else {
                a = i1;     // not a -> a
            }
            if (e2 == 1) {
                b = i2;     // b -> b
            } else {
                b = i2 + n; // not b -> not b
            }
            // std::cout << a << "->" << b << "\n";
            graph[a].push_back(b);
            tgraph[b].push_back(a);

            if (e2 == 1) {
                b = i2 + n; // b -> not b
            } else {
                b = i2 ;    // not b -> b
            }
            if (e1 == 1) {
                a = i1;     // a -> a
            } else {
                a = i1 + n; // not a -> not a
            }
            // std::cout << b << "->" << a << "\n";
            graph[b].push_back(a);
            tgraph[a].push_back(b);
        }

        for (int i = 0; i < 2*n; ++i) {
            if (buff[i] == 0) {
                dfs(i);
            }
        }

        std::reverse(topsort.begin(), topsort.end());
        int color = 0;
        for (auto i : topsort) {
            if (component[i] == -1) {
                dfsCo(i, color);
                ++color;
            }
        }
        
        ans = std::vector<int>(n, 0);

        for (int i = 0; i < n; ++i) {
            if (component[i] < component[i+n]) {
                ans[i] = 0;
            } else {
                ans[i] = 1;
            }
        }

        for (auto i : ans) {
            writeInt(i);
        }
        writeChar('\n');
    }   
}
