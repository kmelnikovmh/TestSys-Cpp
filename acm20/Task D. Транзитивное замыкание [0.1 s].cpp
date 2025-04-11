
// Created 05.03.2025 by Melnikov Kirill

#include <vector>
#include <bitset>
#include "optimization.h"

int main() {
    int n = readInt();
    std::vector<std::bitset<2000>> matrix(n);
    for (int i = 0; i < n; ++i) {
        char buff[n+10];
        readWord(buff);
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = int(buff[j]) - 48;
        }
    }

    std::bitset<2000> buf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                matrix[i] |= matrix[j];
            }
            if (matrix[j][i] == 1) {
                matrix[j] |= matrix[i];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = matrix[i][j];
            writeInt(x);
        }
        writeChar('\n');
    }
}
