
// Created 22.01.2025 by Melnikov Kirill

#include <string>
#include <vector>
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

int main() {
    int v, e;
    v = readInt();
    e = readInt();

    std::vector<std::vector<int>> list(v + 1, std::vector<int>(0, 0));
    std::vector<int> mark(v + 1, 0);
    std::vector<int> digIn(v + 1, 0);
    std::vector<int> answer;
    answer.reserve(v);

    int a, b;
    for (int i = 1; i <= e; ++i) {
        a = readInt();
        b = readInt();
        ++digIn[b];
        list[a].push_back(b);
    }

    for (int i = 1; i <= v; ++i) {
        if (digIn[i] == 0) {
            dfs(i, list, mark, answer);
        }
    }

    int bb = 1;
    for (int i = answer.size() - 1; i > 0; --i) {
        int tek = answer[i];
        int cled = answer[i-1];
        if (std::find(list[tek].begin(), list[tek].end(), cled) == list[tek].end()) {
            bb = 0;
            break;
        }
    }

    if (bb == 1) {
        writeWord(std::string("YES").c_str());
        writeChar('\n');
        for (int i = answer.size() - 1; i >=0; --i) {
            writeInt(answer[i], ' ');
        }
    } else {
        writeWord(std::string("NO").c_str());
    }
}
