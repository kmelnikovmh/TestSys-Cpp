
// Created 02.06.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>

std::mt19937 rng(937);

struct Node {
    int val;
    int size;
    Node *left, *right, *parent;

    Node(int v) : val(v), size(1), left(nullptr), right(nullptr), parent(nullptr) {}
};

int get_size(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}

void update(Node* node) {
    if (node == nullptr) return;

    node->size = 1 + get_size(node->left) + get_size(node->right);;
    if (node->left != nullptr) node->left->parent = node;
    if (node->right != nullptr) node->right->parent = node;
}

// Split на [0, k) и [k, ...], Merge
void split(Node* node, int k, Node* &left, Node* &right) {
    if (node == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }

    int left_size = get_size(node->left);
    if (k <= left_size) {
        split(node->left, k, left, node->left);
        update(node);
        right = node;
        right->parent = nullptr;
    } else {
        split(node->right, k - get_size(node->left) - 1, node->right, right);
        update(node);
        left = node;
        left->parent = nullptr;
    }
}

Node* merge(Node* left, Node* right) {
    if (left == nullptr) {
        if (right != nullptr) right->parent = nullptr;
        return right;
    }
    if (right == nullptr) {
        if (left != nullptr) left->parent = nullptr;
        return left;
    }

    std::uniform_int_distribution<int> like_right_size(0, get_size(left) + get_size(right) - 1);
    if (get_size(left) <= like_right_size(rng)) {
        right->left = merge(left, right->left);
        right->parent = nullptr;
        update(right);
        return right;
    } else {
        left->right = merge(left->right, right);
        left->parent = nullptr;
        update(left);
        return left;
    }
}

void bypass(Node* node, std::vector<int> &arr) {
    if (node == nullptr) return;

    bypass(node->left, arr);
    arr.push_back(node->val);
    bypass(node->right, arr);
}

Node* find_root(Node* node) {
    while (node->parent != nullptr) {
        node = node->parent;
    }
    return node;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<Node*> arr(n + 1);
    std::unordered_set<Node*> roots;
    for (int i = 1; i <= n; ++i) {
        arr[i] = new Node(i);
        roots.insert(arr[i]);
    }

    char cmd;
    int i, j, k;
    for (; m > 0; --m) {
        std::cin >> cmd;
        if (cmd == '+') {
            std::cin >> i >> j;
            Node* root_i = find_root(arr[i]);
            Node* root_j = find_root(arr[j]);
            roots.erase(root_i);
            roots.erase(root_j);

            Node* new_merged = merge(root_i, root_j);
            roots.insert(new_merged);

        } else if (cmd == '-') {
            std::cin >> i >> k;
            Node* root_i = find_root(arr[i]);
            roots.erase(root_i);

            Node *new_left, *new_right;
            split(root_i, k, new_left, new_right);

            roots.insert(new_left);
            roots.insert(new_right);
        } else if (cmd == '!') {
            std::cin >> i >> k;
            Node* root_i = find_root(arr[i]);
            roots.erase(root_i);

            Node *new_left, *new_right;
            split(root_i, k, new_left, new_right);

            Node* new_merged_rotate = merge(new_right, new_left);
            roots.insert(new_merged_rotate);
        }
    }

    std::vector<std::vector<int>> res;
    for (auto &root : roots) {
        std::vector<int> temp;
        bypass(root, temp);
        res.push_back(temp);
    }

    std::sort(res.begin(), res.end());

    std::cout << res.size() << "\n";
    for (auto &vec : res) {
        std::cout << vec.size() << " ";
        for (auto el : vec) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
}
