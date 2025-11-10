#pragma once

template<typename T>
class SplayTree {
private:
    struct Node {
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(const T& v) : value(v) {}
    };

    Node* root = nullptr;

    // ----- Rotations -----
    Node* rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // ----- Splay Operation -----
    Node* splay(Node* h, const T& key) {
        if (!h) return nullptr;

        if (key == h->value)
            return h;

        // --- Key is in left subtree ---
        if (key < h->value) {
            if (!h->left) return h;

            // Zig-Zig (left-left)
            if (key < h->left->value) {
                h->left->left = splay(h->left->left, key);
                h = rotateRight(h);
            }
            // Zig-Zag (left-right)
            else if (key > h->left->value) {
                h->left->right = splay(h->left->right, key);
                if (h->left->right)
                    h->left = rotateLeft(h->left);
            }

            return h->left ? rotateRight(h) : h;
        }

        // --- Key is in right subtree ---
        else {
            if (!h->right) return h;

            // Zag-Zag (right-right)
            if (key > h->right->value) {
                h->right->right = splay(h->right->right, key);
                h = rotateLeft(h);
            }
            // Zag-Zig (right-left)
            else if (key < h->right->value) {
                h->right->left = splay(h->right->left, key);
                if (h->right->left)
                    h->right = rotateRight(h->right);
            }

            return h->right ? rotateLeft(h) : h;
        }
    }

    // ----- Delete entire subtree -----
    void destroy(Node* n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

public:

    ~SplayTree() {
        destroy(root);
    }

    // ----- Insert -----
    void insert(const T& value) {
        if (!root) {
            root = new Node(value);
            return;
        }

        root = splay(root, value);

        // Key already exists → replace value
        if (root->value == value) {
            root->value = value;
            return;
        }

        Node* newNode = new Node(value);

        if (value < root->value) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }

        root = newNode;
    }

    // ----- Find -----
    // Returns: Node* (nullptr if not found)
    Node* find(const T& key) {
        if (!root) return nullptr;
        root = splay(root, key);
        if (root->value == key) return root;
        return nullptr;
    }

    // ----- Remove -----
    void remove(const T& key) {
        if (!root) return;

        root = splay(root, key);

        if (!(root->value == key))
            return; // not found

        Node* temp;
        if (!root->left) {
            temp = root->right;
        } else {
            temp = root->left;
            temp = splay(temp, key);
            temp->right = root->right;
        }

        delete root;
        root = temp;
    }
};