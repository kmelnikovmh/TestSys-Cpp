
// Created 06.11.2024 by Melnikov Kirill

#include <iostream>
#include <vector>

int64_t n, m, a, b;

uint32_t cur = 0;
uint32_t nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}

int64_t kol = 0;
void merge(std::vector<int64_t>& vector, int64_t left, int64_t mid, int64_t right) {
    int64_t sizeL = mid - left + 1;
    int64_t sizeR = right - mid;

    std::vector<int64_t> L(sizeL), R(sizeR);

    for (int64_t i = 0; i < sizeL; i++) {
        L[i] = vector[left + i];
    }   
    for (int64_t j = 0; j < sizeR; j++) {
        R[j] = vector[mid + 1 + j];
    }

    int64_t i = 0, j = 0;
    int64_t k = left;
    while (i < sizeL && j < sizeR) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
            kol += j;
        } else {
            vector[k] = R[j];
            j++;
            kol += sizeL-i;
        }
        k++;
    }

    while (i < sizeL) {
        vector[k] = L[i];
        i++;
        k++;
        kol += j;
    }

    while (j < sizeR) {
        vector[k] = R[j];
        j++;
        k++;
        kol += sizeL-i;
    }
}

void mergeSort(std::vector<int64_t>& vector, int64_t left, int64_t right) {
    if (left >= right) return;

    int64_t mid = (left + right ) / 2;
    mergeSort(vector, left, mid);
    mergeSort(vector, mid + 1, right);
    merge(vector, left, mid, right);
}

int main() {
    std::cin >> n >> m >> a >> b;
    std::vector<int64_t> vector(n);

    for (size_t i = 0; i < n; ++i) {
        vector[i] = nextRand24() % m;
    }

    mergeSort(vector, 0, vector.size() - 1);

    /*for (int64_t i : vector) {
        std::cout << i << " ";
    }*/
    std::cout << kol/2;
}
