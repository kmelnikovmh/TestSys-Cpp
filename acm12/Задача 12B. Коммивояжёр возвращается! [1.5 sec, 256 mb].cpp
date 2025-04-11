
// Created 14.12.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

// Специально все косо-криво =)

int n;
int max = INT32_MAX;
std::vector<std::vector<int>> heaps;
std::vector<std::vector<int>> dp;
std::vector<int> res;

int recur(int heap, int l) {
    if (l == 0){
        dp[l][heap] = 0;
        return dp[l][heap];
    }
    if (dp[l][heap] < max) return dp[l][heap];

    int aaaa = 0, buff = max, curr;
    while (aaaa < n) {
        if ((l >> aaaa) & 1) {
            curr = heaps[aaaa][heap] + recur(aaaa, l - (1 << aaaa));
            dp[l][heap] = std::min(dp[l][heap], curr);
        }
        ++aaaa;
    }
    
    return dp[l][heap];
}

void ans(int index, int mask) {
    int i = n - 1;
    while (i > -1) {
        if (mask != (1 << index)) {
            for (int j = 0; j < n; ++j) {
                bool usl = static_cast<bool>(dp[mask - (1<<j)][j] + heaps[j][index] == dp[mask][index]);
                if(usl && ((mask >> j) & 1)) {
                    index = j;
                    mask = mask - (1 << j);
                    res[i] = j;
                    ++res[i];
                    break;
                }
            }
        } else {
            res[i] = index;
            ++res[i];
            break;
        }
        --i;
    }
}

int main() {
    int zahl, cost = max, index = 0;
    std::cin >> n;
    heaps = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    dp = std::vector<std::vector<int>>(1 << n, std::vector<int>(n, max));
    res = std::vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> zahl;
            if (i == j) {
                heaps[i][j] = 0;
                continue;
            } else {
                heaps[i][j] = zahl;
            }
            if (i == 0) {
                dp[i][j] = 0;
            }
        }
    }

    int aaaa = 0, buff = max;
    while (aaaa < n) {
        buff = recur(aaaa, (1 << n) - 1);
        if (buff < cost) {
            cost = std::min(cost, buff);
            index = aaaa;
        }
        ++aaaa;
    }
    std::cout << cost << "\n";
    ans(index, (1 << n) - 1);

    for (auto z : res) {
        std::cout << z << " ";
    }
}
