
// Created 13.11.2024 by Melnikov Kirill

#include <vector>
#include "optimization.h"
 
std::string s = "";
void Permut(int n, int begin, std::vector<int> &numbers) {
    if (n == 0){
        for (char c : s) {
            writeChar(c);
            writeChar(' ');
        }
        writeChar('\n');
        return;
    }

    for (int i = 1; i <= begin; i++) {
        if (!numbers[i]) {
            s += char(i + '0');
            numbers[i] = 1;
            Permut(n - 1, begin, numbers);
            s.pop_back();
            numbers[i] = 0;
        }
    }
}
 
int main() {
    int n;
    n = readInt();
    std::vector<int> numbers(n + 1);
    Permut(n, n, numbers);
}
