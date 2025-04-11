
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, min=1000000000;
    vector<long long> ot;
    cin >> n;
    
    for (long long a=1; a<=n; ++a) {
        for (long long b=a; b<=(n/a); ++b) {
            long long c = n/(a*b);
            if (c*a*b==n && 2*(a*b+a*c+b*c)< min) {
                min = 2*(a*b+a*c+b*c);
                ot = {a,b,c};
            }
        }
    }

    cout << /*min << " " <<*/ ot[0] << " " << ot[1] << " " << ot[2];
}
