#include <iostream>
#include <string>

struct Node {
    int val;
    int size;
    Node* left;
    Node* right;

    Node(int v) : val(v), size(1), left(nullptr), right(nullptr) {}
};

int get_size(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}

Node* add(Node* v, int val) { 
    if (!v) {
        return new Node(val);
    }

    if (val < v->val) {
        v->left = add(v->left, val);
    } else {
        v->right = add(v->right, val);
    }

    v->size = 1 + get_size(v->left) + get_size(v->right);
    return v;
}

void print_debug(Node* node, int depth = 0) {
    if (node == nullptr) return;

    print_debug(node->left, depth + 1);

    std::cout << std::string(2 * depth, ' ') 
            << "x=" << node->val << " size=" << node->size << "\n";

    print_debug(node->right, depth + 1);
}

int main() {
    Node* root = nullptr;

    int x, count = 0;
    while (std::cin >> x) {
        if (count != 0) std::cout << "-\n"; ++count;
        
        root = add(root, x);
        print_debug(root);
    }
}
