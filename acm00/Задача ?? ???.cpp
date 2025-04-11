
// Created ??.08.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create
    int m, n, k, x, y;
    cin >> m >> n >> k;
    vector<vector<char>> mat(m, vector<char>(n));

    for (int i = 0; i < m; ++i) { 
        for (int j = 0; j < n; ++j) {
            mat[i][j] = '0';
        }
    }

    // Fill *
    for (int i = 0; i < k; ++i) {
        cin >> y >> x;
        --y;
        --x;
        mat[y][x] = '*';
    }
    
    // Fill other
    for (size_t i = 0; i != mat.size(); ++i) {
        for (size_t j = 0; j != mat.size(); ++j) {
            char cen = mat[i][j];
            if (cen == '*') {
                int lk, rk, lm, rm;
                if (i == 0) {
                    lk = 0; rk = 1;
                } else if (int(i) == m) {
                    lk = -1; rk = 0;
                } else {
                    lk = -1; rk = 1;
                }

                if (j == 0) {
                    lm = 0; rm = 1;
                } else if (int(j) == n) {
                    lm = -1; rm = 0;
                } else {
                    lm = -1; rm = 1;
                }

                for (int k = lk; k < rk + 1; ++k) {
                    for (int m = lm; m < rm + 1; ++m) {
                        if (mat[i+k][j+m] != '*') {
                            mat[i+k][j+m] = char(int(mat[i+k][j+m]) + 1);
                        }
                    }
                }
            }
        }
    }

    // Output
    for (size_t i = 0; i != mat.size(); ++i) {
        for (size_t j = 0; j != mat.size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
