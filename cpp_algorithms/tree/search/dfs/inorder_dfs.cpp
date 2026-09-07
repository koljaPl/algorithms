#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// In-order Depth First Search
// Time Complexity:      O(n)
// Space Complexity :    O(n)

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> inorder_dfs(vector<int>& result, TreeNode* root) {
    if (!root) {
        return result;
    }

    inorder_dfs(result, root->left);

    result.push_back(root->val);

    inorder_dfs(result, root->right);

    return result;
}

// Tests
int main() {
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    vector<int> result;

    inorder_dfs(result, root);

    for (int x : result) {
        cout << x << " ";
    }

    cout << '\n';
}
