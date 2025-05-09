
// Created 22.04.2025 by Melnikov Kirill

#include <utility>
#include "optimization.h"

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

void update(Node* v) {
    v->size = 1 + get_size(v->left) + get_size(v->right);
}

std::pair<Node*, Node*> split_by_pos(Node* t, int pos) {
    if (!t) return {nullptr, nullptr};

    int left_size = get_size(t->left);

    if (left_size < pos) {
        auto p = split_by_pos(t->right, pos - left_size - 1);
        t->right = p.first;
        update(t);
        return {t, p.second};
    } else {
        auto p = split_by_pos(t->left, pos);
        t->left = p.second;
        update(t);
        return {p.first, t};
    }
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;

    if (get_size(l) <= get_size(r)) {
        r->left = merge(l, r->left);
        update(r);
        return r;
    } else {
        l->right = merge(l->right, r);
        update(l);
        return l;
    }
}

Node* insert(Node* root, int pos, int val) {
    auto p = split_by_pos(root, pos);
    Node* new_node = new Node(val);
    return merge(merge(p.first, new_node), p.second);
}

void write_bypass(Node* v) {
    if (!v) return;
    write_bypass(v->left);
    writeInt(v->val, ' ');
    write_bypass(v->right);
}


int main() {
    Node* root = nullptr;

    while (!seekEof()) {
        int i = readInt();
        int x = readInt();
        root = insert(root, i, x);
    }

    write_bypass(root);
}
