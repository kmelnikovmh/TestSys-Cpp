
// Created 19.05.2025 by Melnikov Kirill

#include <vector>
#include <cstdint>
#include "optimization.h"

int n;
std::vector<int64_t> arr;

void build(int n, std::vector<int64_t> &arr) {
    arr.resize(2*n);
    for (int i = 0; i < n; ++i)
        arr[i+n] = arr[i];
    for (int i = n - 1; 0 < i; --i)
        arr[i] = arr[2*i] + arr[2*i+1];
}

int64_t get_sum(int l, int r) {
    int64_t res = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res += arr[l++];
        if (r % 2 == 0) res += arr[r--];
    }
    return res;
}

void change(int i, int x) {
    arr[i+=n] = x;
    for (i /= 2; 1 <= i; i /= 2) {
        arr[i] = arr[2*i] + arr[2*i+1];
    }
}

int main() {
    n = readInt();
    int k = readInt();
    build(n, arr);

    char cmd[2];
    int i, x, l, r;
    for (int j = k; 0 < j; --j) {
        readWord(cmd);
        if (cmd[0] == 'A') {
            i = readInt();
            x = readInt();
            change(i - 1, x);
        } else {
            l = readInt();
            r = readInt();
            writeInt(get_sum(l - 1, r - 1), '\n');
        }
    }
}
