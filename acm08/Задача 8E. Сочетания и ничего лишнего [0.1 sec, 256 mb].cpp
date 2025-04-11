
// Created 13.11.2024 by Melnikov Kirill

#include <vector>
#include "optimization.h"

void psp(int j, int begin, int n, std::vector<int> &num, int end) {
    if (end - begin + 1 < n) {
        return;
    }
    if (n == 0) {
        for (int z : num) {
            writeInt(z, ' ');
        }
        writeChar('\n');
        return;
    }
    for (int i = begin; i <= end; ++i) {
        num[j] = i;
        psp(j + 1, i + 1, n - 1, num, end);
        num[j] = i;
    }
    return;
}

int main() {
    int n, k;
    n = readInt();
    k = readInt();
    std::vector<int> num(n);
    psp(0, 1, n, num, k);
}
