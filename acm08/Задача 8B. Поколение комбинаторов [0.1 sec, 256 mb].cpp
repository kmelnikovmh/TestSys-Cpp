
// Created 13.11.2024 by Melnikov Kirill

#include <vector>
#include "optimization.h"

void psp (int begin, int k, std::vector<int> &num) {
    if (k == 0) {
        for (int z : num) {
            writeInt(z, ' ');
        }
        writeChar('\n');
        return;
    }
    for (int i = begin; i > 0; --i) {
        num.push_back(i);
        psp(i - 1, k - 1, num);
        num.pop_back();
    }
    return;
}

int main() {
    int n, k;
    n = readInt();
    k = readInt();
    std::vector<int> num;
    num.reserve(n);
    psp(n, k, num);
}
