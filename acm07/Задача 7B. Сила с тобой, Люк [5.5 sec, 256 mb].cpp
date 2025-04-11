
// Created 06.11.2024 by Melnikov Kirill

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include "optimization.h"

struct countIV {
    size_t count;
    int64_t index, value;
};

bool operator<(const countIV &lhs, const countIV &rhs) {
    if (lhs.count != rhs.count) {
        return lhs.count < rhs.count;
    } else {
        return lhs.index < rhs.index;
    }
}

std::vector<int64_t> values;
std::unordered_map<int64_t, std::set<int64_t>> values_index;
std::set<countIV> countInVa;

int main() {
    int64_t n, q, z;
    n = readInt();

    for (int i = 0; i < n; ++i) {
        z = readInt();
        values.push_back(z);
        if (!values_index[z].empty()) {
            countInVa.erase({values_index[z].size(), *values_index[z].begin(), z});
        }
        values_index[z].insert(i);
        countInVa.insert({values_index[z].size(), *values_index[z].begin(), z});
    }

    q = readInt();
    char buff[5];
    for (int j = 0; j < q; ++j) {
        readWord(buff);
        if (buff[0] == '?') {
            writeInt((*countInVa.begin()).index, '\n');
        } else {
            int64_t i = readInt();
            int64_t newv = readInt();
            int64_t oldv = values[i];

            countInVa.erase({values_index[oldv].size(), *values_index[oldv].begin(), oldv});
            values_index[oldv].erase(i);
            if (!values_index[oldv].empty()) {
                countInVa.insert({values_index[oldv].size(), *values_index[oldv].begin(), oldv});
            }

            values[i] = newv;

            if (!values_index[newv].empty()) {
                countInVa.erase({values_index[newv].size(), *values_index[newv].begin(), newv});
            }
            values_index[newv].insert(i);
            countInVa.insert({values_index[newv].size(), *values_index[newv].begin(), newv});
        }
    }
}
