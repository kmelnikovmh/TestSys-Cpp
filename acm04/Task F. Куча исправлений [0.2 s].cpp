
// Created 01.10.2024 by Melnikov Kirill

#include <iostream>
#include "optimization.h"

int main() {
    int n;
    std::cin >> n;
    int queue[n];
    for (int i = 0; i < n; ++i) {
        int z;
        std::cin >> z;
        queue[i] = z;
    }

    int i = 1;
    int k = 0;
    std::string buf[100];
    while(i < n) {
        int father = queue[(i+1)/2 - 1];
        int son = queue[i];
        if (father > son) {
            queue[(i+1)/2 - 1] = son;
            queue[i] = father;
            buf[k] =  std::to_string(i+1) + " " + std::to_string((i+1)/2) + "\n";
            /*for (int c : queue) {
                std::cout << c << " ";
            }
            std::cout << "\n";*/
            i = 0;
            ++k;
        }
        ++i;
    }

    std::cout << k << "\n";
    for (std::string c : buf) {
        std::cout << c;
    }
}
