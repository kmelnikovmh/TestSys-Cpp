
// Created 22.01.2025 by Melnikov Kirill

#include <vector>
#include <set>
#include <map>
#include <utility>
#include "optimization.h"

std::set<int> ans;
std::map<std::pair<int,int>,int> edges;
int bb;

void dfs(int v, int par, int &time, const std::vector<std::vector<int>> &list, std::vector<int> &mark, std::vector<int> &timeIn, std::vector<int> &buff) {
    mark[v] = 1;
    timeIn[v] = time;
    buff[v] = time;
    ++time;

    for (int i : list[v]) {
        if (mark[i] == 1 && i != par) {
            buff[v] = std::min(buff[v], timeIn[i]);
        }
        if (mark[i] == 0 && i != par) {
            dfs(i, v, time, list, mark, timeIn, buff);
            buff[v] = std::min(buff[v], buff[i]);
            if (buff[i] > timeIn[v]) {
                if (v < i) {
                    ans.insert(edges[std::make_pair(v, i)]);
                } else {
                    ans.insert(edges[std::make_pair(i, v)]);
                }
            }
        }
    }
    buff.push_back(v);
}

int main() {
    int v, e;
    v = readInt();
    e = readInt();

    std::vector<std::vector<int>> list(v + 1, std::vector<int>(0, 0));
    std::vector<int> mark(v + 1, 0);
    std::vector<int> timeIn(v + 1, 0);
    std::vector<int> buff(v + 1, 0);

    int a, b;
    for (int i = 1; i <= e; ++i) {
        a = readInt();
        b = readInt();
        list[a].push_back(b);
        list[b].push_back(a);
        
        if (a < b) {
            edges.emplace(std::make_pair(a, b), i);
        } else {
            edges.emplace(std::make_pair(b, a), i);
        }
    }

    int time = 1;
    for (int i = 1; i <= v; ++i) {
        if (mark[i] == 0) {
            dfs(i, -1, time, list, mark, timeIn, buff);
        }
    }

    writeInt(ans.size(), '\n');

    for (auto it : ans) {
        writeInt(it, '\n');
    }
} 
