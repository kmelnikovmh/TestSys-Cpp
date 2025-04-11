
// Created 09.10.2024 by Melnikov Kirill

#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    long long stoilo[n], z;
    for (int i = 0; i < n; ++i) {
        std::cin >> z;
        stoilo[i] = z;
    }
    long long r = stoilo[n-1] + 1, l = -1, m;
    while (r - l > 1) {
        m = (r + l) / 2;
        int kolzan = 1, poslzan = 0;
        for (int i = 1; i < n; ++i) {
            if (stoilo[i] - stoilo[poslzan] >= m) {
                kolzan++;
                poslzan = i;
            }
        }
        if (kolzan >= k) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << l;
}
