class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def copy(self):
        return TreeNode(self.val, self.left, self.right)


root_example = TreeNode(1)
root_example.left = TreeNode(2)
root_example.right = TreeNode(3)

root_example.left.left = TreeNode(4)
root_example.left.right = TreeNode(5)

root_example.right.right = TreeNode(6)