
// Created 09.04.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <random>

int dp_backpack(int N, int W, std::vector<int> &weight_items, std::vector<int> &cost_items) {
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1,0));
    for (int k = 1; k <= N; ++k) {
        for (int s = 1; s <= W; ++s) {
            if (s >= weight_items[k]) {
                dp[k][s] = std::max(dp[k-1][s], dp[k-1][s-weight_items[k]] + cost_items[k]);
            } else {
                dp[k][s] = dp[k-1][s];
            }
        }
    }
    return dp[N][W];
}

int greedy_backpack(int N, int W, std::vector<int> &weight_items, std::vector<int> &cost_items) {
    int cost = 0;
    for (int i = 1; i <= N; ++i) {
        int loc_weight = weight_items[i], loc_cost = cost_items[i];
        std::vector<std::pair<double, int>> cost_divide_weight;
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;
            cost_divide_weight.push_back({1.0 * cost_items[j] / weight_items[j], j});
        }
        std::sort(cost_divide_weight.begin(), cost_divide_weight.end(),
              [](const std::pair<double, int>& a, const std::pair<double, int>& b) {
                  return a.first > b.first;
              });
        
        for (auto qi : cost_divide_weight) {
            int j = qi.second;
            if (loc_weight + weight_items[j] <= W) {
                loc_weight += weight_items[j];
                loc_cost += cost_items[j];
            }
        }
        cost = std::max(cost, loc_cost);
    }
    return cost;
}

int main() {
    int N, W;
    int low_w, high_w, low_cost, high_cost;
    std::cin >> N >> W >> low_w >> high_w >> low_cost >> high_cost;

    bool find_failed_test = false;
    std::mt19937 rng(239);
    int i = 1;
    while (!find_failed_test) {
        std::vector<int> weight_items(N + 1);
        std::vector<int> cost_items(N + 1);
        for (int i = 1; i <= N; ++i) {
            weight_items[i] = low_w + rng() % (high_w - low_w +1);
            cost_items[i] = low_cost + rng() % (high_cost - low_cost +1);
        }

        int dp_ans = dp_backpack(N, W, weight_items, cost_items);
        int greedy_ans = greedy_backpack(N, W, weight_items, cost_items);
        if (dp_ans != greedy_ans) {
            // std::cout << i << "\n";
            // std::cout << dp_ans << " != " << greedy_ans << "\n";
            std::cout << N << " " << W << "\n";
            for (int i = 1; i <= N; ++i) {
                std::cout << weight_items[i] << " " << cost_items[i] << "\n";
            }
            find_failed_test = true;
        }
        ++i;
    }
}
