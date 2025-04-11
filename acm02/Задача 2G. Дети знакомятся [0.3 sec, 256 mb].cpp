
// Created 17.09.2024 by Melnikov Kirill

#include <iostream>
#include <string>
#include <unordered_map>
#include "optimization.h"
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    n = readInt();
    
    unordered_map<int, int> leftmap, rightmap;
    char buf[15];
    string c, name[n];
    readWord(buf);
    c = buf;
    name[0] = c;
    for (int i = 1; i <= n-1; ++i) {
        readWord(buf);
        c = buf;
        name[i] = c;
        leftmap[i] = i-1;
        rightmap[i-1] = i;
    }
    leftmap[0] = n-1;
    rightmap[n-1] = 0;

    int z, l, r;
    string lname, rname;
    for (int i = 1; i <= n-3; ++i) {
        z = readInt();
        z = z-1;
        c = name[z];
        l = leftmap[z];
        lname = name[l];
        r = rightmap[z];
        rname = name[r];
        writeWord((lname+" ").c_str());
        writeWord(rname.c_str());
        writeWord("\n");

        // name[z][1] = "-1";
        rightmap[l]=r;
        leftmap[r]=l;
    }
}
