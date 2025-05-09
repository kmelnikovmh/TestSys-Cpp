
// Created 29.04.2025 by Melnikov Kirill

#include <iostream>
#include <string>
#include <vector>

struct Node {
    int val;
    int size;
    Node* left;
    Node* right;

    Node(int k) : val(k), size(1), left(nullptr), right(nullptr) {}
    Node(int k, Node* left, Node* right) : val(k), size(1 + (left ? left->size : 0) + (right ? right->size : 0)), left(left), right(right) {}
};

int get_size(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}


Node* build(std::vector<int> &array, int l, int r) {
    if (l > r) return nullptr;

    int mid = (l + r) / 2;
    return new Node(array[mid], build(array, l, mid - 1), build(array, mid + 1, r));
}

Node* create(Node* node, int k, int val) {
    int leftSize = get_size(node->left);

    if (k == leftSize) {
        return new Node(val, node->left, node->right);
    } else if (k < leftSize) {
        return new Node(node->val, create(node->left, k, val), node->right);
    } else {
        return new Node(node->val, node->left, create(node->right, k - leftSize - 1, val));
    }
}

int kth(Node* node, int k) {
    int leftSize = get_size(node->left);

    if (k == leftSize) {
        return node->val;
    } else if (k < leftSize) {
        return kth(node->left, k);
    } else {
        return kth(node->right, k - leftSize - 1);
    }
}

int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }


    int m;
    std::cin >> m;

    std::vector<Node*> version_map;
    version_map.push_back(build(array, 0, n - 1));

    for (int i = 0; i < m; ++i) {
        std::string cmd;
        std::cin >> cmd;
        
        if (cmd == "create") {
            int version, el, val;
            std::cin >> version >> el >> val;
            --version;
            --el;

            Node *new_version = create(version_map[version], el, val);

            version_map.push_back(new_version);

        } else {
            int version, el;
            std::cin >> version >> el;
            --version;
            --el;

            std::cout << kth(version_map[version], el) << std::endl;
        }
    }
}
