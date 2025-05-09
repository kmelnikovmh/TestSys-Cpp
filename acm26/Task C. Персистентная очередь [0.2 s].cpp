
// Created 29.04.2025 by Melnikov Kirill

#include <vector>
#include <deque>
#include "optimization.h"

struct Operation {
    int type;
    int value;
};

int n;
std::vector<std::vector<int>> graph_list;
std::vector<Operation> operations;
std::deque<int> queue;              
std::vector<int> result;            

void dfs(int version) {
    int removed_value;
    int oper_type = operations[version].type;
    if (oper_type == 1) {
        queue.push_back(operations[version].value);
    } else if (oper_type == -1) {
        removed_value = queue.front();
        result[version] = removed_value;
        queue.pop_front();
    }

    for (auto to : graph_list[version]) {
        if (result[to] == -1) {
            dfs(to);
        }
    }

    if (oper_type == 1) {
        queue.pop_back();
    } else if (oper_type == -1) {
        queue.push_front(removed_value);
    }
}

int main() {
    n = readInt();
    operations.resize(n + 1);
    graph_list.resize(n + 1);
    result = std::vector<int>(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        int type = readInt();
        int parent = readInt();
        int value{};
        if (type == 1) value = readInt();

        operations[i] = {type, value};
        graph_list[parent].push_back(i);
    }

    dfs(0);

    for (auto v : result) {
        if (v != -1) {
            writeInt(v, '\n');
        }
    }
}
