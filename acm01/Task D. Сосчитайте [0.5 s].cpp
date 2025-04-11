
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n0, m0, k, n;
    cin >> m0 >> n0;
    k = m0-1;
    
    int64_t C, Al=0;
    for (int i=0; i<=n0; ++i) {
        n = i+k;
        // cout << "koef " << n << " " << k << " ab ";

        int a,b;    
        if (k>n-k) {
            a = n-k;
        } else {
            a = k;
        }
        // cout << a << "\n";
        
        int l=1;
        C = 1.0;
        for (int j=0; j<a; ++j) {
            C = C * (n-j) / (j+1);
            //cout << "*"<< (n-j) << " ";
            //cout << "/" << (j+1) << " ";    
        }

        // cout << "\nC " << C << "\n";
        Al += C;
    }
    cout << Al; 
}
