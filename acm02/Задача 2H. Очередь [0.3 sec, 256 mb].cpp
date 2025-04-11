
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<vector<int>> deq;
    deque<int> tovar[10001];

    int type, t, a, t0;
    for (int i = 1; i <= n; ++i) {
        cin >> type >> t >> a;
        t0 = t;

        if (type == 2) {
            deq.push_back({a, t});
        } else {
            if (!deq.empty() && a == deq.front()[0]) {
                cout << t - deq.front()[1] << " ";
                deq.pop_front();
            } else {
                tovar[a].push_back(t);
            }
        }
        /*cout << "\n";
        for (vector<int> v : deq) {
        cout << v[0] << " " << v[1] << "  ";
        cout << "\n";
        }*/

        if (!deq.empty()) {
            a = deq.front()[0];
            //cout << !tovar[a].empty() << "\n";
            while (!tovar[a].empty()) {
                cout << t0 - deq.front()[1] << " ";
                deq.pop_front();
                tovar[a].pop_front();
                if (!deq.empty()) {
                    a = deq.front()[0];
                } else {
                    break;
                }
            }
        }
    }

    if (!deq.empty()) {
        for (int i = 0; i != deq.size(); ++i) {
            cout << "-1 ";
        }
    }
}
