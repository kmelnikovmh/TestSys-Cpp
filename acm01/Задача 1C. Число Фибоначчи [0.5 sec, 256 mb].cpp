
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {1,1};
int fib(int n) {
    if (a[n]!=0) {
        return a[n];
    } else {
        a[n] = fib(n-2) + fib(n-1);
        return a[n];
    }
}

int main() {
    int newn;
    cin >> newn;
    a.resize(newn+1);
    cout << fib(newn);
}
