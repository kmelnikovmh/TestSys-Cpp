
// Created 19.03.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

struct node {
    int count;
    char m_char;
    node* down;
    node* right;

    node() : m_char('-'), count(), down(), right() {}
    node(char c, int count): m_char(c), count(count), down(), right() {}
};

struct comparator {
    bool operator()(node *lhs, node* rhs) {
        return !(lhs->count < rhs->count);
    }
};

std::priority_queue<node*, std::vector<node*>, comparator> queue;
std::unordered_map<char, int> uses;
std::map<char, std::string> code;
node* root;

void gen(node* node, std::string str) {
    if (node == nullptr) {
        return;
    }

    if (node->m_char != '-') {
        code[node->m_char] = str;
        return;
    }
    gen(node->right, str + '1');
    gen(node->down, str + '0');
}

void build() {
    if (queue.size() == 1) {
        node* a = queue.top();
        queue.pop();
        
        node* ab = new node();
        ab->count = a->count;
        ab->down = a;

        queue.push(ab);
    }
    while (queue.size() > 1) {
        node* a = queue.top();
        queue.pop();
        node* b = queue.top();
        queue.pop();

        node* ab = new node();
        ab->count = a->count + b->count;
        ab->down = a;
        ab->right = b;

        queue.push(ab);
    }
}

std::string raw_str;
std::string answer;
void print() {
    for (auto c : raw_str) {
        answer = answer + code[c];
    }
    std::cout << code.size() << " " << answer.size() << "\n";
    for (auto c : code) {
        std::cout << c.first <<": " << c.second << "\n";
    }
    std::cout << answer;
}

int main() {
    std::cin >> raw_str;

    for (auto c : raw_str) {
        ++uses[c];
    }
    for (auto c : uses) {
        queue.push(new node(c.first, c.second));
    }

    build();
    gen(queue.top(), "");
    
    if (code.size() != 1) {
        print();
    } else {
        code.begin()->second = "0";
        print();
    }
}
