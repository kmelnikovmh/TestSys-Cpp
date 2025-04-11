
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    char a, b;
    cin >> s;

    vector<bool> exp(s.size(), false);
    stack<int> stack;

    /*for (int c : exp) {
            cout << c;
        }
    cout << "\n";*/

    for (int i = 0; i != s.size(); i++) {
        b = s[i];
        if (b=='(' || b=='[' || b=='{') {
            stack.push(i);
        } else {
            if (!stack.empty()) {
                a = s[stack.top()];
                if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) {
                    exp[i] = true;
                    exp[stack.top()] = true;
                    // cout << i << " " << stack.top() << "\n";
                    stack.pop();
                } else {
                    while (!stack.empty()) {
                        stack.pop();
                    }
                }
            }
        }
    }

    /*for (int c : exp) {
            cout << c;
        }
    cout << "\n";*/

    int l = -1, curr = 0, lm = -1, currm = 0;
    for (int i = 0; i != s.size(); ++i) {
        if (exp[i]) {
            if (curr == 0) {
                l = i;
            }
            curr++;
        } else {
            if (curr > currm) {
                currm = curr;
                lm = l;
            }
            curr = 0;
        }
    }

    if (curr > currm) {
        currm = curr;
        lm = l;
    }

    if (lm == -1) {
        cout << "";
    } else {
        cout << s.substr(lm, currm);
    }
}
