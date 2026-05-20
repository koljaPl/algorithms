# Pre-order Depth First Search
from algorithms.tree.design.tree import root

# Time Complexity:      O(n)
# Space Complexity :    O(n)
def preorder_dfs_fast(result: list, root):
    if not root:
        return result

    result.append(root.val)

    preorder_dfs_fast(result, root.left)
    preorder_dfs_fast(result, root.right)

    return result


# Time Complexity:      O(n ** 2)
# Space Complexity :    O(n)
def preorder_dfs_slow(root):
    if not root:
        return []

    return [root.val] + preorder_dfs_slow(root.left) + preorder_dfs_slow(root.right)

# Tests
print(preorder_dfs_fast([], root))

print(preorder_dfs_slow(root))
