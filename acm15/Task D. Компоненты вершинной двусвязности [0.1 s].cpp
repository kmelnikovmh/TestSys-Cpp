
// Created 29.01.2025 by Melnikov Kirill

#include <vector>
#include <map>
#include "optimization.h"

std::vector<std::vector<int>> graph;
std::vector<int> buff, comp, begin, end;
std::map<std::pair<int, int>, std::vector<int>> edge;
int t = 1, ansCo = 0;

void dfs(int v, int parent) {
    buff[v] = 1;
    begin[v] = t;
    end[v] = t;
    ++t;

    for (auto to : graph[v]) {
        if (to != parent && buff[to] == 1) {
            end[v] = std::min(end[v], begin[to]);
        }
        if (to != parent && buff[to] == 0) {
            dfs(to, v);
            end[v] = std::min(end[v], end[to]);
        }
    }
}

std::pair<int, int> get(int a, int b) {
    if (a < b) {
        return std::make_pair(a, b);
    }
    return std::make_pair(b,a);
}

void set(int v, int to, int co) {
    for (auto i : edge[get(v, to)]) {
        comp[i] = co;
    }
}

void dfsCo(int v, int parent, int co) {
    buff[v] = 1;
    
    for (auto to : graph[v]) {
        if (to != parent && buff[to] == 0) {
            if (begin[v] <= end[to]) {
                set(v, to, ++ansCo);
                dfsCo(to, v, ansCo);
            } else {
                set(v, to, co);
                dfsCo(to, v, co);
            }
        }
        if (to != parent && buff[to] == 1 && begin[v] > begin[to]) {
            set(v, to, co);
        }
    }
}


int main() {
    int n, m;
    n = readInt();
    m = readInt();

    graph = std::vector(n + 1, std::vector<int>(0));
    buff = std::vector(n + 1, 0);
    comp = std::vector(m + 1, 0);
    begin = std::vector(n + 1, 0);
    end = std::vector(n + 1, 0);

    int a, b;
    for (int i = 1; i <= m; ++i) {
        a = readInt();
        b = readInt();

        graph[a].push_back(b);
        graph[b].push_back(a);
        edge[get(a,b)].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (buff[i] == 0) {
            dfs(i, -1);
        }
    }

    buff.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (buff[i] == 0) {
            dfsCo(i, -1, ansCo);
        }
    }

    writeInt(ansCo, '\n');
    for (int i = 1; i <= m; ++i) {
        writeInt(comp[i], ' ');
    }
}
