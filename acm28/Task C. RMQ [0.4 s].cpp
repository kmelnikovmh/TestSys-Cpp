
// Created 19.05.2025 by Melnikov Kirill

#include <vector>
#include <cstdint>
#include "optimization.h"

int n;
std::vector<int64_t> tree;
std::vector<int64_t> wait_op;

void build(const std::vector<int64_t> &arr, int root, int l, int r) {
    tree.resize(4*n, INT64_MIN);
    wait_op.resize(4*n, 0);

    if (l == r) {
        tree[root] = arr[l];
        return;
    }

    int m = (l + r) / 2;
    build(arr, 2 * root, l, m);
    build(arr, 2 * root + 1, m + 1, r);

    tree[root] = std::max(tree[2*root], tree[2*root+1]);
}

void push(int v) {
    if (wait_op[v] == 0) return;

    wait_op[2*v] += wait_op[v];
    wait_op[2*v+1] += wait_op[v];

    tree[2*v] += wait_op[v];
    tree[2*v+1] += wait_op[v];

    wait_op[v] = 0;
}

int64_t get_max(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) return INT64_MIN;
    if (l <= vl && vr <= r) return tree[v];
    
    push(v);
    int vm = (vl + vr) / 2;
    int64_t fl = get_max(2 * v, vl, vm, l, r);
    int64_t fr = get_max(2 * v + 1, vm + 1, vr, l, r);
    
    return std::max(fl, fr);
}

void change(int v, int vl, int vr, int l, int r, int64_t val) {
    if (vr < l || r < vl) return;
    if (l <= vl && vr <= r) {
        tree[v] += val;
        wait_op[v] += val;
        return;
    }

    push(v);
    int vm = (vl + vr) / 2;
    change(2 * v, vl, vm, l, r, val);
    change(2 * v + 1, vm + 1, vr, l, r, val);

    tree[v] = std::max(tree[2*v], tree[2*v+1]);
}

int main() {
    n = readInt();
    int q = readInt();

    std::vector<int64_t> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = readInt();
    }

    build(arr, 1, 0, n - 1);

    char cmd[4];
    int l, r, val;
    for (int j = q; 0 < j; --j) {
        readWord(cmd);
        if (cmd[0] == 'm') {
            (l = readInt())--;
            (r = readInt())--;
            writeInt(get_max(1, 0, n - 1, l, r), '\n');
        } else {
            (l = readInt())--;
            (r = readInt())--;
            val = readInt();
            change(1, 0, n - 1, l, r, val);
        }
    }
}

