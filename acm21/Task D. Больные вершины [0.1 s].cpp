
// Created 11.03.2025 by Melnikov Kirill

#include <vector>
#include "optimization.h"

struct Request {
    char type;
    int v;
};

int p[100'001];

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
    int t = readInt();
    for (int k = 1; k <= t; ++k) {
        int n = readInt();
        int q = readInt();
        std::vector<Request> req(q);

        int par[n+1];
        par[1] = 1;
        p[1] = 1;
        bool ill_kor = 0;
        for (int i = 2; i <= n; ++i) {
            par[i] = readInt();
            p[i] = par[i];
        }

        for (int i = 0; i < q; ++i) {
            char type[2];
            readWord(type);
            int v = readInt();
            if (type[0] == '-') {
                p[v] = v;
                if (v == 1) {
                    ill_kor = 1;
                }
            }
            req[i] = {type[0], v};
        }

        std::vector<int> ans;
        for (int i = q - 1; i >= 0; --i) {
            auto [type, v] = req[i];
            if (type == '-') {
                join(v, par[v]);
                if (v == 1) {
                    ill_kor = 0;
                }
            } else {
                int buff = get(v);
                if (buff == 1 && ill_kor != 1) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(buff);
                }
            }
        }
        std::reverse(ans.begin(), ans.end());
        for (auto b : ans) {
            writeInt(b, ' ');
        }
        writeChar('\n');
    }
}    
