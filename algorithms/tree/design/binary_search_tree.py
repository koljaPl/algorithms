class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value) -> None:
        if self.root is None:
            self.root = TreeNode(value)
            return

        curr = self.root
        while curr:
            if value < curr.val:
                if curr.left is None:
                    curr.left = TreeNode(value)
                    break
                curr = curr.left
            elif value > curr.val:
                if curr.right is None:
                    curr.right = TreeNode(value)
                    break
                curr = curr.right
            else:
                break

    def search(self, value) -> TreeNode | None:
        curr = self.root
        while curr:
            if curr.val == value:
                return curr
            elif value < curr.val:
                curr = curr.left
            else:
                curr = curr.right

        return None

    def delete(self, value):
        self.root = self._delete_recursive(self.root, value)

    def _min_value_node(self, node):
        curr = node

        while curr.left:
            curr = curr.left

        return curr

    def _delete_recursive(self, node, value):
        if not node:
            return None

        if value < node.val:
            node.left = self._delete_recursive(node.left, value)
        elif value > node.val:
            node.right = self._delete_recursive(node.right, value)
        else:
            if not node.left:
                return node.right
            elif not node.right:
                return node.left

            successor = self._min_value_node(node.right)
            node.val = successor.val

            node.right = self._delete_recursive(node.right, successor.val)

        return node