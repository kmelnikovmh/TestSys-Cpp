
// Created 25.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include "optimization.h"
using namespace std;
// #define FAST_ALLOCATOR_MEMORY 1e9


int main() {
    unordered_map<string, pair<string, string>> set;
    pair<string, string> pairtik, pairtiktik, temptik, temptiktik;
    string tik, who, orient, c, neig;
    char cc[11];
    int n;

    readWord(cc);
    tik = cc;
    n = readInt();
    // cin >> tik >> n;

    set[tik] = {"0","0"};
    c = tik;

    for (int i = 1; i <= n; ++i) {
        readWord(cc);
        who = cc;
        readWord(cc);
        tik = cc;
        readWord(cc);
        orient = cc;
        // cin >> who >> tik >> orient;

        // cout << "bilo " << tik << " " << pairtik.first << " " << pairtik.second << "\n";
        if (orient == "l") {
            neig = set[tik].first;
            set[tik].first = who;
            set[neig].second = who;
            set[who].first = neig;
            set[who].second = tik;
        } else {
            neig = set[tik].second;
            set[tik].second = who;
            set[neig].first = who;
            set[who].first = tik;
            set[who].second = neig;
        }   
        /*cout << "stalo " << tik << " "<< temptik.first << " " << temptik.second << "\n"; 
        if (orient == "l") {
            cout << orient << " " << pairtik.first << " " << temptiktik.first << " " << temptiktik.second << "\n";
            cout << "new " << who << " "<< pairtik.first << " " << tik;
        } else {
            cout << orient << " " << pairtik.second << " " << temptiktik.first << " " << temptiktik.second << "\n";
            cout << "new " << who << " "<< tik << " " << pairtik.second;
        }
        cout << "\n";*/
    }

    for (int i = 0; i <= n+1; ++i) {
        pairtik = set[c];
        if (c != "0") {
            // cout << c << "\n";
            writeWord(c.c_str());
            writeChar('\n');
        }
        c = pairtik.second;
    }
}
