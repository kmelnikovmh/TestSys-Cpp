
// Created 25.09.2024 by Melnikov Kirill

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string g;
    getline(cin, g);
    long arraypp[g.size()+1], arraypz[g.size()+1];
    arraypp[0] = 0;
    arraypz[0] = 0;
    
    long pp = 0, pz = 0;
    for (size_t i = 0; i != g.size(); ++i) {
        char c = g[i];
        if (c == '(') {
            ++pp;
        } else {
            ++pz;
        }
        arraypp[i+1] = pp;
        arraypz[i+1] = pz;
        // cout << arraypp[i+1];
    }
    /*cout << "\n";
    for (int i = 1; i != g.size()+1; ++i) {
        cout << arraypz[i];
    }
    cout << "\n";*/

    int n;
    cin >> n;

    for (int j = 1; j <= n; ++j) {
        int l, r;
        cin >> l >> r;

        // cout << arraypp[r] - arraypp[l-1] << " " << arraypz[r] - arraypz[l-1] << "\n";
        if ((arraypp[r] - arraypp[l-1]) == (arraypz[r] - arraypz[l-1])) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}
