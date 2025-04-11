
// Created 25.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "optimization.h"

std::map<std::string, long> map = {{"+",0}, {"-",0}, {"*", 5}, {"/",5}, {"(", -2}, {")",10}};

int main() {
    std::vector<long> numbers;
    std::vector<std::string> operators;
    std::string s, opnew, opold;
    char buf [1'000'000];
    readWord(buf);
    s = buf;
    s = '('+s+')';

    long i = 0;
    while (i != s.size()) {
        if (i != s.size() and '0' <= s[i] and s[i] <= '9') {
            long j, z;
            j = i;
            while (j != s.size() and '0' <= s[j] and s[j] <= '9') {
                ++j;
            }
            z = std::stoi(s.substr(i, j-i));
            numbers.push_back(z);
            i = j;
        } else {
            long zoldold, zold, zitog;
            opnew = s[i];
            // std::cout << opnew << " ";

            if (opnew == "(") {
                operators.push_back(opnew);
            } else if (opnew == ")") {
                opold = operators.back();
                while (opold != "(") {
                    zold = numbers[numbers.size()-1];
                    zoldold = numbers[numbers.size()-2];
                    numbers.pop_back();
                    numbers.pop_back();
                    operators.pop_back();
                    if (opold == "+") {numbers.push_back(zoldold + zold);}
                    if (opold == "-") {numbers.push_back(zoldold - zold);}
                    if (opold == "*") {numbers.push_back(zoldold * zold);}
                    if (opold == "/") {numbers.push_back(zoldold / zold);}
                    opold = operators.back();
                }
                operators.pop_back();
            } else {
                opold = operators.back();
                while (!operators.empty() and map[opnew] <= map[opold]) {
                        zold = numbers[numbers.size()-1];
                        zoldold = numbers[numbers.size()-2];
                        numbers.pop_back();
                        numbers.pop_back();
                        operators.pop_back();
                        if (opold == "+") {numbers.push_back(zoldold + zold);}
                        if (opold == "-") {numbers.push_back(zoldold - zold);}
                        if (opold == "*") {numbers.push_back(zoldold * zold);}
                        if (opold == "/") {numbers.push_back(zoldold / zold);}
                        opold = operators.back();
                    }
                operators.push_back(opnew);
            }
            ++i;
        }
        // std::cout << "\n\n";
    }
    while (!operators.empty()) {
        long zoldold, zold, zitog;
        opold = operators.back();
        zold = numbers[numbers.size()-1];
        zoldold = numbers[numbers.size()-2];

        numbers.pop_back();
        numbers.pop_back();
        operators.pop_back();
        if (opold == "+") {numbers.push_back(zoldold + zold);}
        if (opold == "-") {numbers.push_back(zoldold - zold);}
        if (opold == "*") {numbers.push_back(zoldold * zold);}
        if (opold == "/") {numbers.push_back(zoldold / zold);}
    }
    // std::cout <<  numbers.back();
    writeInt(numbers.back());
}
