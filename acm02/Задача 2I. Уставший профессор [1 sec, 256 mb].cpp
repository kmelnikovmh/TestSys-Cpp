
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
#include <deque>
using namespace std;

int main() {
    const int64_t m = 1073741824;
    int64_t n, k, c, x, y;
    cin >> n >> k;

    deque<int64_t> desk;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        desk.push_back(c);
    }

    for (; k > 0; --k) {
        x = desk.front();
        y = desk.back();

        if (x < y) {
            desk.pop_front();
            desk.push_back((x + y) & ((1 << 30) - 1));
        } else {
            desk.pop_back();
            desk.push_front((y-x) & ((1 << 30) - 1));
        }
    }

    for (int64_t cc : desk) {
        cout << cc << " ";
    }
}
