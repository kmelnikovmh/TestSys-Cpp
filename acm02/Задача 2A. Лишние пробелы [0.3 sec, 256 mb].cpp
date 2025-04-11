
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s, s0;
    getline(cin, s);
    
    bool fl=false;
    while (fl!=true) {
        if (isalpha(s[0])) {
            fl = true;
            break;
        }
        s = s.substr(1);      
    }
    fl=false;
    while (fl!=true) {
        if (isalpha(s[s.size()-1])) {
            fl = true;
            break;
        }
        s = s.substr(0,s.size()-1);
    }

    for (int i = 0; i!=s.size(); ++i) {
        if ((s[i]==s[i+1]) && s[i]==' ') {
            continue;
        } else {
            s0.push_back(s[i]);
        }
    }

    cout << s0;
}
