
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<long> stack;
    long a, b, c;
    string s;
    while (cin >> s) {
        // std::cout << s;

        if (isdigit(s[0])) {
            c = stoi(s);
            stack.push_back(c);
        } else {
            b = stack.back();
            stack.pop_back();
            a = stack.back();
            stack.pop_back();
            // std::cout << a << b << "\n";

            if (s=="+") {
                stack.push_back(a+b);
            } else if (s=="-") {
                stack.push_back(a-b);
            } else if (s=="*") {
                stack.push_back(a*b);   
            }
            // std::cout << stack.back();
        }
    }

    std::cout << stack.back();
}
