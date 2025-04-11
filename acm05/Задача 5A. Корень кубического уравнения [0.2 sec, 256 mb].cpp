
// Created 09.10.2024 by Melnikov Kirill

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    long double L = -1000000, R = 1000000, m;
    
    while (R - L > 1e-7) {
        m = (R + L) / 2;
        if ( (a*L*L*L + b*L*L + c*L + d) * (a*m*m*m + b*m*m + c*m + d) > 0) {
            L = m;
        } else {
            R = m;
        }
    }
    std::cout << std::fixed << std::setprecision(6) << m;
}
