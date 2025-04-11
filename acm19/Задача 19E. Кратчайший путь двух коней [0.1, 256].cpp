
// Created 25.02.2025 by Melnikov Kirill

#include <vector>
#include <deque>
#include <map>
#include "optimization.h"

bool valid(std::pair<int, int> &x) {
    return (x.first>=1 && x.first <= 8 && x.second >= 1 && x.second <=8);
}

int main() {
    std::vector<int> vv;
    std::vector<std::pair<int, int>> start, end;
    for (int i = 1; i <= 4; ++i) {
        std::string str;
        std::cin >> str;
        char a = str[0];
        int b = str[1] - '0';
        vv.push_back(a - '`');
        vv.push_back(b);
    }
    start = {{vv[0], vv[1]}, {vv[2], vv[3]}};
    end = {{vv[4], vv[5]}, {vv[6], vv[7]}};

    std::deque<std::vector<std::pair<int, int>>> deque;
    std::map<std::vector<std::pair<int, int>>, std::pair<int, std::vector<std::pair<int, int>>>> dist;

    std::vector<std::pair<int, int>> move = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    dist[start] = {1, start};
    deque.push_back(start);
    int i = 1;
    while(deque.size() != 0) {
        std::vector<std::pair<int, int>> v = deque.front();
        std::pair One = v[0];
        std::pair Two = v[1];
        if (v == end) break;

        // first
        for (auto mv : move) {
            std::pair<int, int> New = {One.first + mv.first, One.second + mv.second};
            if (valid(New) && New != Two && dist[{New, Two}].first == 0) {
                dist[{New, Two}].first = dist[v].first + 1;
                dist[{New, Two}].second = v;
                deque.push_back({New, Two});
            }
        }
        
        // second
        for (auto mv : move) {
            std::pair<int, int> New = {Two.first + mv.first, Two.second + mv.second};
            if (valid(New) && New != One && dist[{One, New}].first == 0) {
                dist[{One, New}].first = dist[v].first + 1;
                dist[{One, New}].second = v;
                deque.push_back({One, New});
            }
        }
        deque.pop_front();
    }

    // writeInt(dist[end].first + 1);

    std::vector<std::vector<int>> ans;
    std::vector<std::pair<int, int>> v = end;
    int j = 0;
    while (j != dist[end].first - 1) {
        std::vector<std::pair<int, int>> u = dist[v].second;
        if (u[0] != v[0]) {
            std::pair One = v[0];
            ans.push_back({1, One.first, One.second});
        } else {
            std::pair Two = v[1];
            ans.push_back({2, Two.first, Two.second});
        }
        v = u;
        ++j;
    }
    std::reverse(ans.begin(), ans.end());
    for (auto vec : ans) {
        std::cout << vec[0] << " " << char(vec[1] + 96) << vec[2] << "\n";
    }
}
