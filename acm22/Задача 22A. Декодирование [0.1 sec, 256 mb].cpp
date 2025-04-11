
// Created 19.03.2025 by Melnikov Kirill

#include <iostream>
#include <vector>

struct node {
    char m_char;
    node* down;
    node* right;

    node(): m_char('-'), down(), right() {}
};

int main() {
    int k, l;
    scanf("%d %d\n", &k, &l);

    node root;
    node* curr = &root;
    char raw_code[1'000'100];
    std::string raw_str_code;
    char raw_sym;

    for (int i = 1; i <= k; ++i) {
        curr = &root;
        scanf("%c: %s\n", &raw_sym, raw_code);
        raw_str_code = raw_code;
        for (auto c : raw_str_code) {
            if (c != '0') {
                if (curr->right == nullptr) {
                    curr->right = new node();
                }
                curr = curr->right;
            } else {
                if (curr->down == nullptr) {
                    curr->down = new node();
                }
                curr = curr->down;
            }
        }
        curr->m_char = raw_sym;
    }

    std::string answer;
    scanf("%s\n", raw_code);
    raw_str_code = raw_code;
    curr = &root;
    for (auto c : raw_str_code) {
        if (c != '0') {
            curr = curr->right;
        } else {
            curr = curr->down;   
        }
        if (curr->m_char != '-') {
            answer.push_back(curr->m_char);
            curr = &root;
        }
    }
    printf("%s", answer.c_str());
}
