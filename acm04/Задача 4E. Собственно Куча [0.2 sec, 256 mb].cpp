
// Created 01.10.2024 by Melnikov Kirill

#include <string>
#include <queue>
#include "optimization.h"

int main() {
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> likeheap;
    int n;
    n = readInt();
    for (int i = 1; i <= n; ++i) {
        std::string op, num;
        char bufop[1], bufnum[15];
        readWord(bufop);
        op = bufop;
        if (op == "+") {
            int64_t z = readInt();
            likeheap.push(z);
        } else {
            int64_t z;
            z = likeheap.top();
            writeInt(z);
            writeWord("\n");
            likeheap.pop();
        }
    }
}
