
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t n, x, y, a0;
    cin >> n >> x >> y >> a0;
    int64_t pref[n];
    pref[0] = a0;
    for (int i = 0; i < n-1; ++i) {
        a0 = (x*a0+y) % 65536;
        pref[i+1]=(pref[i]+a0);
    }

    int64_t m, z, t, b0;
    cin >> m >> z >> t >> b0;
    int64_t c[2*m];
    c[0] = b0 % n;
    for (int i = 0; i < m*2 - 1; ++i) {
        b0 = (z*b0+t) & ((1 << 30) - 1);
        c[i+1] = b0 % n;
    }

    int64_t l, r, temp, sum = 0;
    for (int i=0; i<m;++i) {
        l = c[2*i];
        r = c[2*i+1];
        if (r < l) {
            temp = r;
            r = l;
            l = temp;
        }
        if (l > 0) {
            sum += pref[r] - pref[l-1];
        } else {
            sum += pref[r];
        }
        // cout << sum <<" ";
    }

    /*cout << "\n\n";
    for (int64_t c : a) {
        cout << c << " ";
    }
    cout << "\n";
    for (int64_t c : pref) {
        cout << c << " ";
    }
    cout << "\n";
    for (int64_t c : b) {
        cout << c << " ";
    }
    cout << "\n";
    for (int64_t c : c) {
        cout << c << " ";
    }*/
    cout << sum;
}
