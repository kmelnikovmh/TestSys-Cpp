
// Created 09.10.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m;
    std::cin >> m;
    std::vector<std::pair<int,int>> OX, pomnim;
    while (true) {
        int a, b;
        std::cin >> a >> b;
        OX.push_back({a,b});
        if (a == 0 && b == 0) break;
    }
    std::sort(OX.begin(), OX.end());

    /*for (auto [a,b] : OX) {
        writeInt(a, ' ');
        writeInt(b, '\n');
    }*/
    int i = 0, lastindab = 0, lastb = 0, a = -1, b = -1, kol = 0;
    bool konez = true;
    while (lastindab < OX.size()-1 && lastb < m) {
        // std::cout << lastindab << " " << lastb << " kol " << kol <<  " -> ";
        int maxind = lastindab, maxb = lastb, j = lastindab;
        while (j < OX.size()) {
            a = OX[j].first;
            b = OX[j].second;
            if (a > lastb) break;
            if (b > maxb) {
                maxind = j;
                maxb = b;
            }
            ++j;
        }
        if (maxb == lastb) {
            konez = false;
            break;
        } else {
            lastb = maxb;
        }
        lastindab = maxind;
        kol++;
        pomnim.push_back(OX[lastindab]);
        // std::cout << lastindab << " " << lastb << " kol " << kol << "\n";
    }
    if (konez && lastb >= m) {
        std::cout << kol << "\n";
        for (int i = 0; i < pomnim.size(); ++i) {
            std::cout << pomnim[i].first << " " << pomnim[i].second << "\n";
        }
    } else {
        std::cout << "No solution";
    }
}
