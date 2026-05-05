class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def copy(self):
        return TreeNode(self.val, self.left, self.right)

    def deep_copy(self):
        new_node = TreeNode(self.val)

        if self.left:
            new_node.left = self.left.deep_copy()
        if self.right:
            new_node.right = self.right.deep_copy()
        
        return new_node

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

root.right.right = TreeNode(6)