
// Created 02.06.2025 by Melnikov Kirill

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int k;
    std::cin >> k;
    std::vector<int> can_moves(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> can_moves[i];
    }
    int N, max_N = 0;
    std::cin >> N;
    std::vector<int> size_play(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> size_play[i];
        max_N = std::max(max_N, size_play[i]);
    }

    // G[n] = mex(G[n-m1], G[n-m2], ...)
    // Вычисляем, если ли дальше проигрышная позиция, то бишь 0, если есть, то
    // наше текущее значение отлично от нуля - mex, то есть выигрышная
    // Если же дальше только выигрышные позиции, то бишь нет ни одного 0, то
    // наше текущее значение по mex эт 0, то есть проигрышная
    std::vector<int> grundy(max_N);
    std::vector<int> used_digits(max_N);
    int cc = 0;
    for (int n = 1; n <= max_N; ++n) {
        // Отметили использованные значения всех G[n-m?] для поиска mex
        ++cc;
        for (int m : can_moves) {
            if (n < m) continue;
            used_digits[grundy[n-m]] = cc;
        }
        // Ищем минимальное, которого нет среди использованных
        for (int i = 0; i <= n; ++i) {
            if (used_digits[i] != cc) {
                grundy[n] = i;
                break;
            }
        }
    }

    for (int N_i : size_play) {
        std::cout << (grundy[N_i] ? "First\n" : "Second\n");
    }
}