
// Created 30.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>

void answer(int l, int r, std::string &str, std::vector<std::vector<int>> &dp, std::vector<std::vector<int>> &index) {
    if (index[l][r] == -2) {
        std::cout << str[l];
        answer(l + 1, r - 1, str, dp, index);
        std::cout << str[r];
        return;
    } else if (dp[l][r] == 0) {
        std::cout << str.substr(l, r - l + 1);
        return;
    } else if (r == l) {
        return;
    } else {
        answer(l, index[l][r], str, dp, index);
        answer(index[l][r] + 1, r, str, dp, index);
    }
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<std::vector<int>> dp(str.size(), std::vector<int>(str.size(), 0));
    std::vector<std::vector<int>> index(str.size(), std::vector<int>(str.size(), 0));
    for (int r = 0; r < str.size(); ++r) {
        for (int l = r; l >= 0 ; --l) {
            int minInd = -2;
            if (l != r) {
                if (str[l] == '(' and str[r] == ')' || 
                    str[l] == '[' and str[r] == ']' ||
                    str[l] == '{' and str[r] == '}') {
                    dp[l][r] = dp[l+1][r-1];
                } else {
                    dp[l][r] = INT_MAX;
                }
                for (int Ind = l; Ind < r; ++Ind) {
                    if (dp[l][r] > dp[l][Ind] + dp[Ind+1][r]) {
                        dp[l][r] = dp[l][Ind] + dp[Ind+1][r];
                        minInd = Ind;
                    }
                }
                index[l][r] = minInd;
            } else {
                dp[l][r] = 1;
            }
        }
    }

    answer(0, str.size() - 1, str, dp, index);
}
