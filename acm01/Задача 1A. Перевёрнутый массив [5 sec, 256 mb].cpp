
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long int n, c;
    cin >> n;
    vector<long int> a(n);
    // cout << a.size() << "\n";

    for (long int i=0; i!=n; ++i) {
        cin >> c;
        a[i] = c;
    }
    
    for (long int i = (n-1); i>=0; --i) {
        cout << a[i] << " ";
    }
}
