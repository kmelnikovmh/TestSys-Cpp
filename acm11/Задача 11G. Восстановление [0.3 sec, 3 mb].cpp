
// Created 04.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>

// Красиво в две строчки преобразовал двумерный массив предыдущей задачи

const int64_t mod = 1'000'000'000 + 7;
int main() {
    std::string str;
    std::cin >> str;
    str = ' ' + str;
    int size = str.size();
    std::vector<int32_t> dpPred(size + 1, 0);
    std::vector<int32_t> dpTek(size, 0);
    dpPred[0] = 1;
    /*for (auto z : dpPred) {
        std::cout << z <<" ";
    }
    std::cout << "\n";*/

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (str[i] == '?') {
                dpTek[j] = dpPred[j+1] % mod;
                if (j != 0) dpTek[j] = (dpTek[j] + dpPred[j-1]) % mod;
            }
            if (str[i] == '(' && j!=0) {
                dpTek[j] = dpPred[j-1] % mod;
            }
            if (str[i] == ')') dpTek[j] = dpPred[j+1] % mod;
        }
        dpPred = dpTek;
        dpTek = std::vector<int32_t>(size + 1, 0);
        /*for (auto z : dpPred) {
            std::cout << z <<" ";
        }
        std::cout << "\n";*/
    }

    std::cout << dpPred[0];
}
