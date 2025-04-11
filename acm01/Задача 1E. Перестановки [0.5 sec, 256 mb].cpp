
// Created 07.09.2024 by Melnikov Kirill

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> aob;
vector<string> list;
vector<int> swap(vector<int>a, int b, int c) {
    int _ = a[b];
    a[b] = a[c];
    a[c] = _;
    return a;
}

void perm(vector<int> a, int n) {
    if (n==0) {
        string s = "";
        for (int i=0; i!=a.size(); ++i) {
            s.insert(i, to_string(a[i]));
        }
        list.push_back(s);
    }

    for (int i=0; i<=n; ++i) {
        a = swap(a, i, n);
        perm(a, n-1);
        a = swap(a, i, n);
    }
}

int main() {
    int dl;
    cin >> dl;
    for (int i=1; i<=dl; ++i) {
        aob.push_back(i);
    }

    if (dl==1) {
        cout << 1;
    } else {
        perm(aob, dl-1);
        sort(list.begin(), list.end());

        for (int j=0; j!=list.size(); ++j) {
            for (char c : list[j]) {
                cout << c << " ";
            }
            cout << "\n";    
        }
    }
}
