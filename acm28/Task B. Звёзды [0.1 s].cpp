
// Created 19.05.2025 by Melnikov Kirill

#include <vector>
#include <cstdint>
#include "optimization.h"

int n;
std::vector<int> arr;

void build(int n) {
    arr.assign(2*n, 0);
}

int get_sum(int l, int r) {
    int res = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res += arr[l++];
        if (r % 2 == 0) res += arr[r--];
    }
    return res;
}

void change(int i, int x) {
    arr[i+=n] += x;
    for (i /= 2; 1 <= i; i /= 2) {
        arr[i] = arr[2*i] + arr[2*i+1];
    }
}

int main() {
    while(!seekEof()) {
        int n_stars = readInt();

        std::vector<std::pair<int, int>> stars(n_stars);
        int max_len_x = 0;
        for(int i = 0; i < n_stars; ++i) {
            int x = readInt();
            int y = readInt();
            stars[i] = std::make_pair(x, y);
            max_len_x = std::max(max_len_x, x);
        }

        n = max_len_x + 1;
        build(n);

        std::vector<int> lvls_count(n_stars, 0);
        for (int i = 0; i < n_stars; ++i) {
            int x = stars[i].first;
            ++lvls_count[get_sum(0, x)];
            change(x, 1);
        }

        for (auto it : lvls_count) {
            writeInt(it, '\n');
        }
    }
}
