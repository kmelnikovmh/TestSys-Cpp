
// Created 25.09.2024 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <string>
#include <map>

// void write(std::vector<int> x) {
//     for (int c : x) {
//         std::cout << " " << c;
//     }
// }

// void writestr(std::vector<std::string> x) {
//     for (std::string c : x){
//         std::cout << " " << c;
//     }
// }

std::map<std::string, int> map = {{"+",0}, {"-",0}, {"(", 10}, {")",10}};

int main() {
    std::vector<int> numbers;
    std::vector<std::string> operators;
    std::string s, opnew, opold;
    std::cin >> s;

    int i = 0;
    while (i != s.size()) {
        if (i != s.size() and s[i] != '+' and s[i] != '-' and s[i] != '(' and s[i] != ')') {
            int j, z;
            j = i;
            while (j != s.size() and s[j] != '+' and s[j] != '-' and s[j] != '(' and s[j] != ')') {
                ++j;
            }
            z = std::stoi(s.substr(i, j-i));
            numbers.push_back(z);
            i = j;
            // std::cout << z; write(numbers); std::cout << " "; writestr(operators);
        } else {
            int zoldold, zold, zitog;
            opnew = s[i];
            // std::cout << opnew << " ";

            if (!operators.empty()) {
                opold = operators.back();
                if (opold != "(" and map[opnew] <= map[opold]) {
                    zold = numbers[numbers.size()-1];
                    zoldold = numbers[numbers.size()-2];
                    numbers.pop_back();
                    numbers.pop_back();
                    operators.pop_back();
                    if (opold=="+") {zitog = zoldold + zold;}
                    if (opold=="-") {zitog = zoldold - zold;}
                    numbers.push_back(zitog);
                    // write(numbers); std::cout << " "; writestr(operators);
                } else if (opnew == ")") { //SKOBKI
                    while (opold != "(") {
                        zold = numbers[numbers.size()-1];
                        zoldold = numbers[numbers.size()-2];
                        numbers.pop_back();
                        numbers.pop_back();
                        operators.pop_back();
                        if (opold == "+") {zitog = zoldold + zold;}
                        if (opold == "-") {zitog = zoldold - zold;}
                        numbers.push_back(zitog);
                        // write(numbers); std::cout << " "; writestr(operators);
                        opold = operators.back();
                    }
                    operators.pop_back();
                }
            }

            if (opnew != ")") {
                operators.push_back(opnew);
            }
            ++i;
        }
        // std::cout << "\n\n";
    }

    if (!operators.empty()) {
        int zoldold, zold, zitog;
        opold = operators.back();
        zold = numbers[numbers.size()-1];
        zoldold = numbers[numbers.size()-2];

        numbers.pop_back();
        numbers.pop_back();
        operators.pop_back();
        if (opold == "+"){zitog = zoldold + zold;}
        if (opold == "-"){zitog = zoldold - zold;}
        numbers.push_back(zitog);
        // write(numbers); std::cout<<" "; writestr(operators);
    }
    std::cout <<  numbers.back();
}
