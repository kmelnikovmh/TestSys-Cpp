
// Created 25.09.2024 by Melnikov Kirill

#include <iostream>
#include <map>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    cin >> n;

    map<int64_t,int64_t> set;
    char c;
    int64_t x, count;
    for (int i = 1; i <= n; ++i) {
        cin >> c >> x;
        count = set[x];

        if (c == '+') {
            set[x] += 1;
        } else {
            if (count == 1) {
                set[x] = 0;
                cout << "after query " << i << " number " << x << " disappeared\n";
            } else if (count == 0) {
                cout << "query #" << i << ": can not delete " << x << "\n";
            } else {
                set[x] -= 1;
            }
        }
    }
}
