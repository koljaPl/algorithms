#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Breadth First Search
//
// Time Complexity:  O(n)
// Space Complexity: O(n)

vector<int> bfs(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<int> result;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        result.push_back(node->val);

        if (node->left != nullptr) {
            q.push(node->left);
        }

        if (node->right != nullptr) {
            q.push(node->right);
        }
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    vector<int> result = bfs(root);

    for (int x : result) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
