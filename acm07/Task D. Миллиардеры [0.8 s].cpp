
// Created 06.11.2024 by Melnikov Kirill

#include <string>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include "optimization.h"

int main() {
    int64_t n = readInt();
    std::unordered_map<std::string, std::pair<std::string, int64_t>> nameCityValue;
    std::unordered_map<std::string, int64_t> unCityValue;
    std::set<std::pair<int64_t, std::string>> ValueCity;
    std::map<std::string, int64_t> cityDays;

    char buffName[25], buffCity[25];
    int64_t val = 0;
    for (int i = 0; i < n; ++i) {
        readWord(buffName);
        readWord(buffCity);
        val = readInt<long long>();
        nameCityValue[buffName] = {buffCity, val};
        unCityValue[buffCity] += val;
    }

    for (auto &CiVa : unCityValue) {
        ValueCity.insert({CiVa.second, CiVa.first});
    }

    int64_t t, t0 = 0, ttek, k;
    t = readInt();
    k = readInt();
    for (int i = 0; i < k; ++i) {
        ttek = readInt();
        readWord(buffName);
        readWord(buffCity);

        if (ValueCity.size() < 2 || (*--ValueCity.end()).first != (*(----ValueCity.end())).first) {
            cityDays[(*--ValueCity.end()).second] += ttek - t0;
        }

        std::string oldCity = nameCityValue[buffName].first;
        int64_t personVal = nameCityValue[buffName].second;
        
        ValueCity.erase({unCityValue[oldCity], oldCity});
        unCityValue[oldCity] -= personVal;
        if (unCityValue[oldCity] < 0) {
            unCityValue[oldCity] = 0;
        }
        ValueCity.insert({unCityValue[oldCity], oldCity});
            
        nameCityValue[buffName].first = buffCity;
        
        if (unCityValue.find(buffCity) != unCityValue.end()) {
            ValueCity.erase({unCityValue[buffCity], buffCity});
        }
        unCityValue[buffCity] += personVal;
        ValueCity.insert({unCityValue[buffCity], buffCity});

        t0 = ttek;
    } 

    if (ValueCity.size() < 2 || (*--ValueCity.end()).first != (*(----ValueCity.end())).first) {
        cityDays[(*--ValueCity.end()).second] += t - t0;
    }
    for (auto pp : cityDays) {
        if (pp.second != 0) {
            std::cout << pp.first << " " << pp.second << "\n";
        }
    }
}
