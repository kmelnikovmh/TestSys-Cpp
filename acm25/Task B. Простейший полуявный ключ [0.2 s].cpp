#include <iostream>
#include <unordered_map>
#include <string>

struct Node {
    int key;
    int size;
    Node* left;
    Node* right;

    Node(int k) : key(k), size(1), left(nullptr), right(nullptr) {}
};

int get_size(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}

Node* add(Node* v, int key) {
    if (!v) {
        return new Node(key);
    }

    if (key < v->key) {
        v->left = add(v->left, key);
    } else if (key > v->key) {
        v->right = add(v->right, key);
    }

    v->size = 1 + get_size(v->left) + get_size(v->right);
    return v;
}

int kth(Node* node, int k) {
    int leftSize = get_size(node->left);

    if (k == leftSize + 1) {
        return node->key;
    } else if (k <= leftSize) {
        return kth(node->left, k);
    } else {
        return kth(node->right, k - leftSize - 1);
    }
}

int main() {
    Node* root = nullptr;
    std::unordered_map<int, int> to_be;

    std::string str;
    while (std::getline(std::cin, str)) {
        int x = std::stoi(str.substr(2));

        if (str[0] == '+') {
            if (to_be[x] == 0) {
                to_be[x] = 1;
                root = add(root, x);
            }
        } else {
            std::cout << kth(root, x) << "\n";
        }
    }
}
