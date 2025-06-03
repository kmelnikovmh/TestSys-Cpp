
// Created 19.03.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct node {
    int m_count;
    char m_char;
    node* m_down;
    node* m_right;

    node(char c, int count): m_char(c), m_count(count), m_down(nullptr), m_right(nullptr) {}
	node(char c, int count, node *down, node *right): m_char(c), m_count(count), m_down(down), m_right(right) {}
};

struct comparator {
    bool operator()(node *lhs, node* rhs) {
        return !(lhs->m_count < rhs->m_count);
    }
};

std::priority_queue<node*, std::vector<node*>, comparator> queue;
std::unordered_map<char, int> uses;
std::unordered_map<char, std::string> code;
node* root;

void gen(node* node, std::string str) {
    if (node == nullptr) {
        return;
    }

    if (node->m_char != '\0') {
        code[node->m_char] = str;
        return;
    }
	gen(node->m_down, str + '0');
    gen(node->m_right, str + '1');
}

void build() {
    if (queue.size() == 1) {
        node* a = queue.top();
        queue.pop();
        
        node* ab = new node('\0', a->m_count, a, nullptr);

        queue.push(ab);
    } else {
		while (queue.size() > 1) {
			node* a = queue.top();
			queue.pop();
			node* b = queue.top();
			queue.pop();

			node* ab = new node('\0', a->m_count + b->m_count, a, b);

			queue.push(ab);
		}
	}
}

std::string raw_str;
std::string answer;
void print() {
    for (char c : raw_str) {
        answer += code[c];
    }
    std::cout << code.size() << " " << answer.size() << "\n";
    for (auto &c : code) {
        std::cout << c.first <<": " << c.second << "\n";
    }
    std::cout << answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> raw_str;

    for (char c : raw_str) {
        ++uses[c];
    }
    for (auto &c : uses) {
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
