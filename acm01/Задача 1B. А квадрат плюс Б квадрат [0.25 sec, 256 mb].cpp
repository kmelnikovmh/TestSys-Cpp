
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long int t, n, b, kol;
    vector<int> otv;
    cin >> t;

    for (long int i=0; i<t; ++i) {
        cin >> n;
        kol = 0;

        for (long int a=1; a*a<=n; ++a) {
            b = sqrt(n - a*a);
            // cout << "b " << b << " n-a*a: " << n-a*a << "\n";
            kol += (b>0 && b*b == n-a*a);
        }
        // cout << "kol "<< kol << "\n\n";
        // otv.push_back(kol);
        cout << kol<<"\n";
    }
}
