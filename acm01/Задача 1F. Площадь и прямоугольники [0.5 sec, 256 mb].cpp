
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, xl,yl, xr,yr, xln,yln, xrn,yrn, S;
    cin >> n;
    xl = -1000000001; yl=-1000000001; xr=1000000001, yr=1000000001;

    for (long long i=1; i<=n; ++i) {
        cin >> xln >> yln >> xrn >> yrn;
        xl = max(xl, xln);
        yl = max(yl, yln);
        xr = min(xr, xrn);
        yr = min(yr, yrn);
    }
    
    S = (xr-xl) * (yr-yl);
    if ((xr-xl < 0) || (yr-yl<0)) {
        cout << 0;
    } else {
        cout << S;
    }
}
