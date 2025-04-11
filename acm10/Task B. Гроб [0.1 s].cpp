
// Created 30.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

int recur(int fat, std::vector<std::vector<int>> &usels, std::vector<int> &wins) {
    if (wins[fat] != -1) return wins[fat];

    int size = usels[fat].size();
    if (size == 1) {
        wins[fat] = 0;
        return 0;
    }

    int sum = 0;
    for (int j = 1; j < size; ++j) {
        sum += recur(usels[fat][j], usels, wins);
    }
    if (sum == size-1) {
        wins[fat] = 0;
        return 0;
    }

    wins[fat] = 1;
    return 1;
}

int main() {
    int n; 
    std::cin >> n;
    std::vector<std::vector<int>> usels(n + 1, std::vector<int>(1,0));
    std::vector<int> wins(n + 1, -1);
    int fat;
    for (int i = 1; i <= n; ++i) {
        std::cin >> fat;
        usels[fat].push_back(i);
    }
    
    int ans =  not recur(0, usels, wins);
    if (ans == 1) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
