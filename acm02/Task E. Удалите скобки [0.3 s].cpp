
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int count = 0;
    vector<char> stack = {' '};
    string s = "";
    char pred;
    getline(cin, s);

    bool fl = true;
    if (s.size() == 0) {
        fl = false;
    }
    
    for (char c : s) {
        if (c=='(' || c=='[' || c=='{') {
            stack.push_back(c);
        } else {
            pred = stack.back();
            stack.push_back(c);
            if ((pred=='(' && c==')') || (pred=='[' && c==']') || (pred=='{' && c=='}')) {
                stack.pop_back();
                stack.pop_back();
            } else {
                ++count;
            }
        }
    }

    cout << "\n" << stack.size()-1;
    /*cout << "\n";
    for (char c : stack) {
        cout << c;
    }*/
}
