
// Created 13.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <unordered_set>

std::unordered_set<int> fib = {0, 1, 2, 3, 5, 8, 13, 21, 34};
int k = 0;
// std::vector<int> num;

void psp(int n, int v, int len, int end) {
    if (n < 0 || v > end) return;
    if (n == 0 && fib.find(len) == fib.end()) {
        /*for (int z : num) {
            std::cout << z << " ";
        }
        std::cout << "\n";*/
        ++k;
        return;
    }

    if (fib.find(v) == fib.end()) {
        // num.push_back(v);
        psp(n-v, v, len+1, end);
        // num.pop_back();
    }
    psp(n, v+1, len, end);
    return;
}

int main() {
    int n;
    std::cin >> n;
    // num.reserve(60);
    psp(n, 4, 0, n);
    std::cout << k;
}
