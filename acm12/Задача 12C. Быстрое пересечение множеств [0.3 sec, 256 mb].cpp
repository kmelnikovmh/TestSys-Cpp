
// Created 14.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> sets(N + 1);

    int k, zahl;
    for (int i = 1; i <= N; ++i) {
        std::cin >> k;
        int set = 0;
        while (k > 0) {
            std::cin >> zahl;
            set = set | (1 << zahl);
            --k;
        }
        sets[i] = set;
    }

    int min, index, currXOR;
    for (int i = 1; i <= N; ++i) {
        int currSet = sets[i];
        min = INT32_MAX;
        index = 0;
        for (int j = 1; j <= N; ++j) {
            int maySet = sets[j];
            currXOR = __builtin_popcount(currSet xor maySet);
            if (j != i && currXOR < min) {
                min = std::min(min, currXOR);
                index = j;
            }
        }
        std::cout << index << " " << min << "\n";
    }
}
