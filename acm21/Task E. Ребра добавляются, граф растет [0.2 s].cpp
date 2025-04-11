
// Created 11.03.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"

int p[300'001];
int link[300'001];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
}
int get(int i) {
    if (p[i] == i) {
        return i;
    } else {
        p[i] = get(p[i]);
        return p[i];
    }
}
void join(int a, int b) {
    a = get(a), b = get(b);
    p[a] = b;
}

int main() {
    int n = readInt();
    int m = readInt();
    init(n);
    int dvudol = true;
    for (int i = 1; i <= m; ++i) {
        int a = readInt();
        int b = readInt();
        if (link[a] == 0) link[a] = b;
        if (link[b] == 0) link[b] = a;

        if (get(a) == get(b)) {
            dvudol = false;
        } else {
            if (get(link[a]) != get(b)) {
                join(link[a], b);
            }
            if (get(link[b]) != get(a)) {
                join(link[b], a);
            }
        }
        writeInt(dvudol);
    }
}    
