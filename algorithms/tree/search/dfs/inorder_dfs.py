# In-order Depth First Search
from algorithms.tree.design.tree import root

# Time Complexity:      O(n)
# Space Complexity :    O(n)
def inorder_dfs(result: list, root):
    if not root:
        return result

    inorder_dfs(result, root.left)
    result.append(root.val)
    inorder_dfs(result, root.right)

    return result

# Tests
print(inorder_dfs([], root))
