#include <bits/stdc++.h>
using namespace std;

// Binary Search Tree:
//
// Time Complexity:
// insert(): Average O(log n), Worst O(n)
// search(): Average O(log n), Worst O(n)
// delete(): Average O(log n), Worst O(n)
//
// Space Complexity:
// Memory: O(n)
// insert(): O(1)
// search(): O(1)
// delete(): recursive O(h)

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* curr = node;

        while (curr->left != nullptr) {
            curr = curr->left;
        }

        return curr;
    }

    TreeNode* deleteRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->val) {
            node->left = deleteRecursive(node->left, value);
        }
        else if (value > node->val) {
            node->right = deleteRecursive(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                TreeNode* rightChild = node->right;
                delete node;
                return rightChild;
            }

            if (node->right == nullptr) {
                TreeNode* leftChild = node->left;
                delete node;
                return leftChild;
            }

            TreeNode* successor = minValueNode(node->right);

            node->val = successor->val;

            node->right = deleteRecursive(
                node->right,
                successor->val
            );
        }

        return node;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
            return;
        }

        TreeNode* curr = root;

        while (curr != nullptr) {
            if (value < curr->val) {
                if (curr->left == nullptr) {
                    curr->left = new TreeNode(value);
                    break;
                }

                curr = curr->left;
            }
            else if (value > curr->val) {
                if (curr->right == nullptr) {
                    curr->right = new TreeNode(value);
                    break;
                }

                curr = curr->right;
            }
            else {
                // Такое значение уже есть
                break;
            }
        }
    }

    TreeNode* search(int value) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->val == value) {
                return curr;
            }
            else if (value < curr->val) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        return nullptr;
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    TreeNode* getRoot() {
        return root;
    }
};
