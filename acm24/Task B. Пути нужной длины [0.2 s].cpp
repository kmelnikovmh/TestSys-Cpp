
// Created 15.04.2025 by Melnikov Kirill

#include <vector>
#include <iostream>
#include "optimization.h"

std::vector<std::vector<int>> graph(100'001);

std::vector<int> deep(100'001, -1);
std::vector<int> par_cen(100'001, -1);

std::vector<std::pair<int, int64_t>> ans;

std::vector<int64_t> freq(100'001, 0);
int mx_depth = 0;

// Очень сложная логика. Считаем не все ans, а только ans[L] как freq[L-curr_dist]
void calc_dist(int v, int p, int depth, bool count_ans) {
    mx_depth = std::max(mx_depth, depth);

    if (count_ans) {
        for (auto &pr : ans) {
            int L = pr.first;
            if (L >= depth) {
                pr.second += freq[L - depth];
            }
        }
    } else {
        freq[depth]++;
    }

    for (int to : graph[v]) {
        if (to != p && deep[to] == -1) {
            calc_dist(to, v, depth + 1, count_ans);
        }
    }
}

void calc_ans(int centroid) {
    mx_depth = 0;
    freq[0] = 1;

    for (int to : graph[centroid]) {
        if (deep[to] != -1) continue;

        calc_dist(to, centroid, 1, true);
        calc_dist(to, centroid, 1, false);
    }

    for (int i = 0; i <= mx_depth; ++i) {
        freq[i] = 0;
    }
}


int get_centroid(int v, int par, int size_tree, int &centroid) {
    int size = 1;

    for (int to : graph[v]) {
        if (to != par && deep[to] == -1) {
            size += get_centroid(to, v, size_tree, centroid);
        }
    }

    if (size * 2 >= size_tree && centroid == -1) {
        centroid = v;
    }

    return size;
}

void build(int v, int par, int size_tree, int deepth) {
    int centroid = -1;
    get_centroid(v, -1, size_tree, centroid);
    if (centroid == -1) centroid = v;
    deep[centroid] = deepth; 
    par_cen[centroid] = par;

    calc_ans(centroid);
    
    for (int to : graph[centroid]) {
        if (deep[to] == -1) {
            build(to, centroid, (size_tree + 1) / 2, deepth + 1);
        }
    }
}

int main() {
    int n = readInt();

    for (int i = 1; i < n; ++i) {
        int par = readInt();
        graph[par].push_back(i);
        graph[i].push_back(par);
    }

    int k = readInt();
    for (int i = 0; i < k; ++i) {
        ans.push_back({readInt(), 0});
    }

    build (0, -1, n, 0);

    for (auto a : ans) {
        writeInt(a.second, ' ');
    }
}