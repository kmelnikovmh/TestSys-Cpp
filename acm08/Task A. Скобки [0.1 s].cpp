
// Created 13.11.2024 by Melnikov Kirill

#include <iostream>
#include <string>

void psp(int n, int balance, std::string& str) {
    if (str.size() == n) {
        if (balance == 0 && n != 0) {
            for (auto s : str) {
                std::cout << s;
            }
            std::cout << "\n";
        }
        return;
    }

    if (balance < 0) {
        return;
    }

    str += "(";
    balance += 1;
    psp (n, balance, str);
    str.erase(str.size() - 1, 1);
    balance -= 1;

    str += ")";
    balance -= 1;
    psp (n, balance, str);
    str.erase(str.size() - 1, 1);
    balance += 1;
}

int main() {
    int n;
    std::string s = "";
    std::cin >> n;
    psp (2*n, 0, s);
}
