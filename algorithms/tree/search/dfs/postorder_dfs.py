# Post-order Depth First Search
from algorithms.tree.design.tree import root, TreeNode


# Time Complexity:      O(n)
# Space Complexity :    O(n)
def postorder_dfs(result: list, root):
    if not root:
        return result

    postorder_dfs(result, root.left)
    postorder_dfs(result, root.right)

    result.append(root.val)

    return result

# Tests
print(postorder_dfs([], root))
