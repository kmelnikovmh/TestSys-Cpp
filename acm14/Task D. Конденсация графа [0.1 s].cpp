
// Created 22.01.2025 by Melnikov Kirill

#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include "optimization.h"

void dfs(int v, const std::vector<std::vector<int>> &list, std::vector<int> &mark, std::vector<int> &answer) {
    mark[v] = 1;

    for (int i : list[v]) {
        if (mark[i] == 0) {
            dfs(i, list, mark, answer);
        }
    }
    answer.push_back(v);
}

void dfsKCC(int v, int c, std::vector<std::vector<int>> &tlist, std::vector<int> &tmark, std::vector<int> &color) {
    tmark[v] = 1;
    color[v] = c;
    for (int i : tlist[v]) {
        if (tmark[i] == 0) {
            dfsKCC(i, c, tlist, tmark, color);
        }
    }
}

int main() {
    int v, e;
    v = readInt();
    e = readInt();

    std::vector<std::vector<int>> list(v + 1, std::vector<int>(0, 0));
    std::vector<std::vector<int>> tlist(v + 1, std::vector<int>(0, 0));
    std::vector<int> mark(v + 1, 0);
    std::vector<int> tmark(v + 1, 0);
    std::vector<int> color(v + 1, 0);
    std::vector<int> answer;
    answer.reserve(v + 1);

    int a, b;
    for (int i = 1; i <= e; ++i) {
        a = readInt();
        b = readInt();
        list[a].push_back(b);
        tlist[b].push_back(a);
    }

    for (int i = 1; i <= v; ++i) {
        if (mark[i] == 0) {
            dfs(i, list, mark, answer);
        }
    }
    std::reverse(answer.begin(), answer.end());

    int c = 1;
    for (int x : answer) {
        if (tmark[x] == 0) {
            dfsKCC(x, c, tlist, tmark, color);
            ++c;
        }
    }

    std::set<std::pair<int, int>> ans;
    for (int i = 1; i <= v; ++i) {
        for (int x : list[i]) {
            if (color[i] != color[x]) {
                ans.insert(std::make_pair(color[i], color[x]));
            }
        }
    }

    writeInt(ans.size());
} 
