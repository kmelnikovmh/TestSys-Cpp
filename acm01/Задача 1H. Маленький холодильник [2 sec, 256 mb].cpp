
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long n, min=pow(2, 64);
    vector<long long> ot = {0,0,0};
    cin >> n;
    
    vector<long long> mn;
    for (long long a=1; a*a<=n+1; ++a) {
        if (n%a==0) {
            mn.push_back(a);
            mn.push_back(n/a);
            }
    }

    for (long long a : mn) {
        for (long long b : mn) {
            long long c = n/(a*b);
            if (a*b*c==n && 2*(a*b+a*c+b*c)<min ) {
                min = 2*(a*b+a*c+b*c);
                ot = {a,b,c};
            }
        }
    }

    /*for (long long c : mn) {
        cout << c << " ";
    }
    cout << "\n";
    cout << mn.size() << "\n";*/
    sort(ot.begin(), ot.end());
    cout << min << " " << ot[0] << " " << ot[1] << " " << ot[2];
}
