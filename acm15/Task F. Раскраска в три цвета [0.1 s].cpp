
// Created 29.01.2025 by Melnikov Kirill

#include <vector>
#include <string>
#include "optimization.h"

std::vector<std::vector<int>> graph, tgraph;
std::vector<int> buff, topsort, component;
std::vector<std::string> ans;

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

    n = readInt();
    m = readInt();

    graph = std::vector(2 * n, std::vector<int>(0));
    tgraph = std::vector(2 * n, std::vector<int>(0));
    buff = std::vector(2 * n, 0);
    topsort = std::vector<int>();
    component = std::vector(2 * n, -1);

    std::string rgb = "RGB";
    std::vector<int> colors(n + 1, 0);
    std::vector<std::pair<int, int>> edge;
    edge.reserve(m);
    char cc[1001];
    readWord(cc);
    std::string str = cc;

    int a, b;
    for (int i = 1; i <= m; ++i) {
        a = readInt();
        --a;
        b = readInt();
        --b;
        
        if (str[a] == 'R') colors[a] = 0;
        if (str[a] == 'G') colors[a] = 1;
        if (str[a] == 'B') colors[a] = 2;
        if (str[b] == 'R') colors[b] = 0;
        if (str[b] == 'G') colors[b] = 1;
        if (str[b] == 'B') colors[b] = 2;
        edge.push_back(std::make_pair(a,b));
    }

    int u, v;
    for (auto el : edge) {
        a = el.first;
        b = el.second;
        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 2; ++l) {
                u = (colors[a] + k + 1) % 3;
                v = (colors[b] + l + 1) % 3;
                if (u != v) continue;
                graph[a*2+k].push_back(2 * b + (1 - l));
                graph[b*2+l].push_back(2 * a + (1 - k));
                tgraph[a*2+(1-k)].push_back(2 * b + l);
                tgraph[b*2+(1-l)].push_back(2 * a + k);
            }
        }
    }



    for (int i = 0; i < 2 * n; ++i) {
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
    
    ans = std::vector<std::string>(n);

    for (int i = 0; i < n; ++i) {
        if (component[2*i]==component[2*i+1]) {
            writeWord("Impossible");
            return 0;
        }
        if (component[2*i] < component[2*i+1]) {
            ans[i] = rgb[(colors[i] + 2) % 3];

        } else {
            ans[i] = rgb[(colors[i] + 1) % 3];
        }
    }

    for (auto i : ans) {
        writeWord(i.c_str());
    }
    writeChar('\n');
}
