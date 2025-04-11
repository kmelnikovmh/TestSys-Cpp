
// Created 04.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

// Переход: если берем i вершину, то просто суммируем детей, когда их не берем (других вариантов то и нет),
// если же не берем i вершину, то выбираем лучший случай для нас: взять ребенка или не взять ребенка, но взять
// его детей (взятие детей учитывается динамически)

const int min = -10'001;

void recur (int i, std::vector<std::vector<int>> &childs, std::vector<int> &costs, std::vector<std::vector<int>> &dp) {
    if (i == 0) {
        int head = childs[0].back();
        recur(head, childs, costs, dp);
        dp[0][0] = dp[head][0];
        dp[0][1] = dp[head][1];
        return;
    }

    dp[i][1] = costs[i];
    dp[i][0] = 0;
    for (auto j : childs[i]) {
        recur(j, childs, costs, dp);
        dp[i][0] += std::max(dp[j][0], dp[j][1]);
        dp[i][1] += dp[j][0];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> childs(n + 1);
    std::vector<int> costs(n + 1, 0);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, min));

    for (int i = 1; i <= n; ++i) {
        int p, q;
        std::cin >> p >> q;
        childs[p].push_back(i);
        costs[i] = q;
    }

    recur(0, childs, costs, dp);

    /*int i = 0;
    for (auto v : childs) {
        std::cout << i <<  ": ";
        for (auto d : v) {
            std::cout << d << " ";
        }
        ++i;
        std::cout << "   ";
    }
    std::cout << "\n";

    i = 0;
    for (auto c : costs) { 
        std::cout << i << ": " << costs[i] << "   ";
        ++i;
    }
    std::cout << "\n";

    i = 0;
    for (auto v : dp) {
        std::cout << i <<  ": ";
        for (auto d : v) {
            std::cout << d << " ";
        }
        ++i;
        std::cout << "   ";
    }
    std::cout << "\n";*/

    std::cout << std::max(dp[0][0], dp[0][1]);
}
