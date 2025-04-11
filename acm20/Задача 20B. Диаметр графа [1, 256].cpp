
// Created 05.03.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"

int main() {
    int n = readInt();
    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, INT16_MAX));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a = readInt();
            if (a >= 0) {
                dist[i][j] = a; 
            }
        }
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ma = -1, mi = INT16_MAX, maloc;
    for (int i = 1; i <= n; ++i) {
        maloc = -1;
        for (int j = 1; j<= n; ++j) {
            if (dist[i][j] != INT16_MAX) {
                ma = std::max(ma, dist[i][j]);
                maloc = std::max(maloc, dist[i][j]);
            }
        }
        mi = std::min(mi, maloc);
    }
    writeInt(ma, '\n');
    writeInt(mi);
}
