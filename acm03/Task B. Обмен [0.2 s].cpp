
// Created 25.09.2024 by Melnikov Kirill

#include <iostream>
#include <utility>
using namespace std;

// optimization.h 
// Author: Sergey Kopeliovich
// ...

int main() {
    long long n, a, b, ai, bi, it;
	pair<long long, long long> ta, tb;

    n = readInt<long long>();
    // cin >> n;

    for (long long j = 1; j <= n; ++j) {
        a = readInt<long long>();
        b = readInt<long long>();
        // cin >> a >> b;

		ta = h[index(a)];
		tb = h[index(b)];
        if (ta.first == a) {
            ai = ta.second;
        } else {
            h[index(a)] = {a,a};
            ai = a;
        }
        if (tb.first == b) {
            bi = tb.second;
        } else {
            h[index(b)] = {b,b};
            bi = b;
        }
        // cout << "first " << a << "," << ai << " " << b << "," << bi << "\n";

        if (ai >= bi) {
            it = ai-bi;
        } else {
            it = bi-ai;
        }
        // cout << it << "\n";

        writeInt(it, '\n');
        h[index(a)].second = bi;
        h[index(b)].second = ai;
        // cout << "second " << a << "," << h[index(a)].second << " " << b << "," << h[index(b)].second << "\n";
    }
}
