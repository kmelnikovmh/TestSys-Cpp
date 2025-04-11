
// Created 13.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

// precalc
std::vector<int64_t> calc = {1, 4, 12, 36, 100, 284, 780, 2172, 5916, 
                            16268, 44100, 120292, 324932, 881500, 2374444, 
                            6416596, 17245332, 46466676, 124658732, 335116620, 
                            897697164, 2408806028, 6444560484};

int main() {
    int n;
    std::cin >> n;
    std::cout << calc[n];
}
