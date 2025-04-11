
// Created 22.01.2025 by Melnikov Kirill

#include <string>
#include <vector>
#include "optimization.h"

int bb = 0;

void dfs(int v, const std::vector<std::vector<int>> &list, std::vector<int> &mark, std::vector<int> &answer) {
    if (bb != 0) return;
    mark[v] = 1;
    answer.push_back(v);

    for (int i : list[v]) {
        if (bb != 0) return;
        if (mark[i] == 1) {
            bb = i;
            return;
        }
        dfs(i, list, mark, answer);
    }
    if (bb != 0) return;
    mark[v] = 2;
    answer.pop_back();
}

int main() {
    int v, e;
    v = readInt();
    e = readInt();

    std::vector<std::vector<int>> list(v + 1, std::vector<int>(0, 0));
    std::vector<int> mark(v + 1, 0);
    std::vector<int> answer;
    answer.reserve(v);

    int a, b;
    for (int i = 1; i <= e; ++i) {
        a = readInt();
        b = readInt();
        list[a].push_back(b);
    }

    int begin = 0;
    for (int i = 1; i <= v; ++i) {
        if (mark[i] == 0) {
            dfs(i, list, mark, answer);
        }
    }

    for (int i = 1; i < answer.size(); ++i) {
        if(answer[i] == bb) {
            begin = i;
            break;
        }
    }

    if (bb != 0) {
        writeWord(std::string("YES").c_str());
        writeChar('\n');
        for (int i = begin; i < answer.size(); ++i) {
            writeInt(answer[i], ' ');
        }
    } else {
        writeWord(std::string("NO").c_str());
    }
}
