
// Created 12.05.2025 by Melnikov Kirill

#include <iostream>
#include <vector>
#include <random>

std::mt19937 rng(937);

struct Node {
    int val;
    int size;
    int64_t sum;
    Node *left, *right;

    Node(int v) : val(v), size(1), sum(v), left(nullptr), right(nullptr) {}
};

int get_size(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}

int64_t get_sum(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->sum;
}

void update(Node* node) {
    if (node == nullptr) return;

    node->size = 1 + get_size(node->left) + get_size(node->right);
    node->sum = node->val + get_sum(node->left) + get_sum(node->right);;
}

// Split на [0, k) и [k, ...], Merge
void split(Node* node, int k, Node* &left, Node* &right) {
    if (node == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }

    node = new Node(*node);
    int left_size = get_size(node->left);
    if (k <= left_size) {
        split(node->left, k, left, node->left);
        right = node;
    } else {
        split(node->right, k - get_size(node->left) - 1, node->right, right);
        left = node;
    }

    update(node);
}

Node* merge(Node* left, Node* right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    std::uniform_int_distribution<int> like_right_size(0, get_size(left) + get_size(right) - 1);
    if (get_size(left) <= like_right_size(rng)) {
        right = new Node(*right);
        right->left = merge(left, right->left);
        update(right);
        return right;
    } else {
        left = new Node(*left);
        left->right = merge(left->right, right);
        update(left);
        return left;
    }
}

Node* build(std::vector<int> &arr) {
    Node* root = nullptr;

    for (int v : arr) {
        root = merge(root, new Node(v));
    }
    
    return root;
}

// Section действия
int64_t get_lr_sum(Node*& root, int l, int r) {
    Node *left, *middle, *right;
    split(root, r + 1, middle, right);          // поделили на [0, r] и на [r+1, n]
    split(middle, l, left, middle);             // поделили на [0, l-1] и на [l, r]

    int64_t res = get_sum(middle);
    root = merge(left, merge(middle, right));   // мерждим сперва [l, r] и [r+1, n], а потом докидываем [0, l-1]

    return res;
}

void write_bypass(Node* node) {
    if (node == nullptr) return;

    write_bypass(node->left);
    std::cout << node->val << " ";
    write_bypass(node->right);
}

void print_lr_range(Node*& root, int l, int r) {
    Node *left, *middle, *right;
    split(root, r + 1, middle, right);
    split(middle, l, left, middle);

    write_bypass(middle);
    std::cout << "\n";

    root = merge(left, merge(middle, right));
}

// Копируем [a, a+len-1] в [b, b+len-1]
void copy_subtree(Node*& root, int a, int b, int len) {
    // Копируем [a, a+len-1] в middle
    Node *left, *middle, *right;
    split(root, a + len, middle, right);
    split(middle, a, left, middle);

    Node* copied = middle;
    root = merge(left, merge(middle, right));

    // Вырезаем [b, b+len-1] и при мердже подменяем на скопированный ранее
    left = middle = right = nullptr;
    split(root, b + len, middle, right);
    split(middle, b, left, middle);

    root = merge(left, merge(copied, right));
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    int64_t X1, A, B, M;
    std::cin >> n >> X1 >> A >> B >> M;

    std::vector<int> arr(n);
    arr[0] = X1;
    for (int i = 0; i < n - 1; ++i) {
        arr[i+1] = (A * arr[i] + B) % M;
    }

    Node* root = build(arr);

    int k;
    std::cin >> k;
    std::string cmd;
    int a, b, len, l, r;
    for (; k > 0; --k) {
        std::cin >> cmd;
        if (cmd == "cpy") {
            std::cin >> a >> b >> len;
            copy_subtree(root, a - 1, b - 1, len);
        } else if (cmd == "sum") {
            std::cin >> l >> r;
            std::cout << get_lr_sum(root, l - 1, r - 1) << "\n";
        } else if (cmd == "out") {
            std::cin >> l >> r;
            print_lr_range(root, l - 1, r - 1);
        }
    }
}
