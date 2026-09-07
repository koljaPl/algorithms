#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Red-Black Tree's:
// Height:     O( 2 * log2 (n + 1) ) ( or h ≤ O( 2 * log2 (n + 1) )
//
// Time Complexity:
// Search:     O(log n)
// Insert:     O(log n)
// Remove:     O(log n)
// Rotations:  O(1)
// Transplant: O(1)
//
// Space Complexity:
// Memory:     O(n)

const bool BLACK = true;
const bool RED = false;

class RedBlackNode {
public:
    int value;

    RedBlackNode* parent;
    bool color;

    RedBlackNode* left;
    RedBlackNode* right;

    RedBlackNode(int value) {
        this->value = value;

        parent = nullptr;
        color = RED;

        left = nullptr;
        right = nullptr;
    }

    string print_color() {
        if (color == BLACK) {
            return "(b)";
        }

        return "(r)";
    }
};

class RedBlackTree {
private:
    RedBlackNode* NIL;

public:
    RedBlackNode* root;

    RedBlackTree() {
        NIL = new RedBlackNode(99999);

        NIL->color = BLACK;

        NIL->left = NIL;
        NIL->right = NIL;

        root = NIL;
    }

    // O(1)
    void left_rotate(RedBlackNode* node) {
        RedBlackNode* right_node = node->right;

        node->right = right_node->left;

        if (right_node->left != NIL) {
            right_node->left->parent = node;
        }

        right_node->parent = node->parent;

        if (node->parent == nullptr) {
            root = right_node;
        }
        else if (node == node->parent->left) {
            node->parent->left = right_node;
        }
        else {
            node->parent->right = right_node;
        }

        right_node->left = node;

        node->parent = right_node;
    }

    // O(1)
    void right_rotate(RedBlackNode* node) {
        RedBlackNode* left_node = node->left;

        node->left = left_node->right;

        if (left_node->right != NIL) {
            left_node->right->parent = node;
        }

        left_node->parent = node->parent;

        if (node->parent == nullptr) {
            root = left_node;
        }
        else if (node == node->parent->right) {
            node->parent->right = left_node;
        }
        else {
            node->parent->left = left_node;
        }

        left_node->right = node;

        node->parent = left_node;
    }

    // O(log n) total
    void insert(int value) {
        RedBlackNode* new_node = new RedBlackNode(value);

        new_node->left = NIL;
        new_node->right = NIL;

        RedBlackNode* right_node = nullptr;

        RedBlackNode* node = root;

        while (node != NIL) {

            right_node = node;

            if (new_node->value < node->value) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }

        new_node->parent = right_node;

        if (right_node == nullptr) {
            root = new_node;
        }
        else if (new_node->value < right_node->value) {
            right_node->left = new_node;
        }
        else {
            right_node->right = new_node;
        }

        insert_fixup(new_node);
    }

    // O(log n)
    void insert_fixup(RedBlackNode* node) {
        while (
            node->parent != nullptr &&
            node->parent->color == RED
        ) {

            if (node->parent == node->parent->parent->left) {

                RedBlackNode* right_node =
                    node->parent->parent->right;

                if (right_node->color == RED) {

                    node->parent->color = BLACK;

                    right_node->color = BLACK;

                    node->parent->parent->color = RED;

                    node = node->parent->parent;
                }
                else {

                    if (node == node->parent->right) {

                        node = node->parent;

                        left_rotate(node);
                    }

                    node->parent->color = BLACK;

                    node->parent->parent->color = RED;

                    right_rotate(node->parent->parent);
                }
            }
            else {
                RedBlackNode* right_node =
                    node->parent->parent->left;

                if (right_node->color == RED) {

                    node->parent->color = BLACK;

                    right_node->color = BLACK;

                    node->parent->parent->color = RED;

                    node = node->parent->parent;
                }
                else {

                    if (node == node->parent->left) {

                        node = node->parent;

                        right_rotate(node);
                    }

                    node->parent->color = BLACK;

                    node->parent->parent->color = RED;

                    left_rotate(node->parent->parent);
                }
            }

            if (node == root) {
                break;
            }
        }

        root->color = BLACK;
    }

    // O(log n) total
    bool remove(int value) {
        RedBlackNode* node = search(value);

        if (node == NIL) {
            return false;
        }

        RedBlackNode* moved_node = node;

        bool moved_node_orig_color =
            moved_node->color;


        // case 1
        RedBlackNode* replacement;

        if (node->left == NIL) {

            replacement = node->right;

            transplant(node, node->right);
        }

        // case 2
        else if (node->right == NIL) {

            replacement = node->left;

            transplant(node, node->left);
        }

        // case 3
        else {

            moved_node = minimum(node->right);

            moved_node_orig_color =
                moved_node->color;

            replacement = moved_node->right;

            if (moved_node->parent == node) {

                replacement->parent = moved_node;
            }
            else {

                transplant(
                    moved_node,
                    moved_node->right
                );

                moved_node->right =
                    node->right;

                moved_node->right->parent =
                    moved_node;
            }

            transplant(node, moved_node);

            moved_node->left = node->left;

            moved_node->left->parent =
                moved_node;

            moved_node->color =
                node->color;
        }

        if (moved_node_orig_color == BLACK) {
            delete_fixup(replacement);
        }

        delete node;

        return true;
    }

    // O(log n)
    void delete_fixup(RedBlackNode* node) {
        while (
            node != root &&
            node->color == BLACK
        ) {

            if (node == node->parent->left) {

                RedBlackNode* sibling =
                    node->parent->right;

                // type 1 - brother is RED
                if (sibling->color == RED) {

                    sibling->color = BLACK;

                    node->parent->color = RED;

                    left_rotate(node->parent);

                    sibling =
                        node->parent->right;
                }

                // type 2 - brothers kids are all BLACK
                if (
                    sibling->left->color == BLACK &&
                    sibling->right->color == BLACK
                ) {

                    sibling->color = RED;

                    node = node->parent;
                }
                else {

                    // type 3 - right brothers kid is BLACK
                    if (sibling->right->color == BLACK) {

                        sibling->left->color = BLACK;

                        sibling->color = RED;

                        right_rotate(sibling);

                        sibling =
                            node->parent->right;
                    }

                    // type 4 - right brothers kid is RED
                    sibling->color =
                        node->parent->color;

                    node->parent->color = BLACK;

                    sibling->right->color = BLACK;

                    left_rotate(node->parent);

                    node = root;
                }
            }
            else {
                // Mirror of another case
                RedBlackNode* sibling =
                    node->parent->left;

                // type 1
                if (sibling->color == RED) {

                    sibling->color = BLACK;

                    node->parent->color = RED;

                    right_rotate(node->parent);

                    sibling =
                        node->parent->left;
                }

                // type 2
                if (
                    sibling->right->color == BLACK &&
                    sibling->left->color == BLACK
                ) {

                    sibling->color = RED;

                    node = node->parent;
                }
                else {

                    // type 3
                    if (sibling->left->color == BLACK) {

                        sibling->right->color = BLACK;

                        sibling->color = RED;

                        left_rotate(sibling);

                        sibling =
                            node->parent->left;
                    }

                    // type 4
                    sibling->color =
                        node->parent->color;

                    node->parent->color = BLACK;

                    sibling->left->color = BLACK;

                    right_rotate(node->parent);

                    node = root;
                }
            }
        }

        node->color = BLACK;
    }

    // O(1)
    void transplant(
        RedBlackNode* u,
        RedBlackNode* v
    ) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }

        v->parent = u->parent;
    }

    // O(h) = O(log n) for RB trees
    RedBlackNode* minimum(RedBlackNode* node) {
        while (node->left != NIL) {
            node = node->left;
        }

        return node;
    }

    // O(h) = O(log n) for RB trees
    RedBlackNode* search(int value) {
        RedBlackNode* node = root;

        while (
            node != NIL &&
            value != node->value
        ) {

            if (value < node->value) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }

        return node;
    }

    // As I understand it, a Red-Black Tree is not faster than an AVL tree for simple lookups, as its height is
    // still slightly greater than that of an AVL tree; however, due to its structure, it is better suited for a
    // balance between insertion, deletion and lookup speeds.
    //
    // Where it is used:
    // This is not really intended for problems of the Codeforces or AtCoder variety, but is more of a
    // low-level algorithm. We use it behind the scenes because of its ability to achieve an exact
    // O(log) time complexity.
    //
    // But we can use it in types of problems like:
    // 1. Dynamic Set (support a set of numbers and perform the following operations: insert ; delete ; find ; next/previous element)
    // 2. Ordered Set / Ordered Map Problems ("find the kth element" or "how many numbers are less than x")
    // 3. Sweep Line ( Geometry and intervals:
    //                       - Example problems:
    //                       - intersection of line segments
    //                       - nearest points
    //                       - active events )
    // 4. Interval Scheduling / Calendar Systems
    // 5. Networking / OS-Level Scheduling
    //
    // Tss... To be more specific about the tasks:
    // 1. Maintain sorted set with updates
    // 2. Dynamic median
    // 3. Intervals + queries
    // 4. Online queries
    //
    // But probobly you gonna used behind the scene
};
