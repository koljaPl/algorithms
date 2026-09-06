#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Pre-order Depth First Search
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

// Time Complexity:      O(n)
// Space Complexity :    O(n)
void preorder_dfs_fast(vector<int>& result, TreeNode* root) {
    if (!root) {
        return;
    }

    result.push_back(root->val);

    preorder_dfs_fast(result, root->left);

    preorder_dfs_fast(result, root->right);
}

// Time Complexity:      O(n ** 2)
// Space Complexity :    O(n)
vector<int> preorder_dfs_slow(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<int> left = preorder_dfs_slow(root->left);
    vector<int> right = preorder_dfs_slow(root->right);

    vector<int> result = {root->val};

    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());

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

    preorder_dfs_fast(result, root);

    for (int x : result) {
        cout << x << " ";
    }

    cout << '\n';

    vector<int> slow_result = preorder_dfs_slow(root);

    for (int x : slow_result) {
        cout << x << " ";
    }

    cout << '\n';
}
