
// Created 01.10.2024 by Melnikov Kirill

#include<iostream>
#include<string>

int main() {
	int L, R, m, n, cin;
	std::string s;
	std::cin >> n;
	std::cin >> s;
	L = -1; R = n;

	while (R - L > 1) {
		m = (L+R) / 2;
		if (s[m] == '0') {
			L = m;
		} else {
			R = m;
		}
		// std::cout << m << " " << L << " " << R << "\n";
	}
	std::cout << L << " " << R;
}
