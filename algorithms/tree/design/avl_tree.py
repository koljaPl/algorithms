from collections import deque

# Height of AVL Tree:
# O( 1,44 * log2(n) )

class AVLTreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def __init__(self):
        self.root = None

    def get_height(self, node):
        return 0 if not node else node.height

    def get_balance_factor(self, node):
        return 0 if not node else (self.get_height(node.left) - self.get_height(node.right))

    def get_min_node(self, node):
        return node if not node or not node.left else self.get_min_node(node.left)

    # O(1)
    def left_rotate(self, node):
        right = node.right
        left_right = right.left

        right.left = node
        node.right = left_right

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        right.height = 1 + max(self.get_height(right.left), self.get_height(right.right))

        return right

    # O(1)
    def right_rotate(self, node):
        left = node.left
        right_left = left.right

        left.right = node
        node.left = right_left

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        left.height = 1 + max(self.get_height(left.left), self.get_height(left.right))

        return left

    # Worst Time Complexity: O(log n)
    def search(self, target):
        curr = self.root

        while curr is not None and target != curr.value:
            if curr.value > target:
                curr = curr.left
            else:
                curr = curr.right

        return curr

    # Worst Time Complexity: O(log n)
    def insert(self, node, value):
        if not node:
            return AVLTreeNode(value)
        elif value < node.value:
            node.left = self.insert(node.left, value)
        else:
            node.right = self.insert(node.right, value)

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

        balance_factor = self.get_balance_factor(node)

        if balance_factor > 1 and value < node.left.value:
            return self.right_rotate(node)

        if balance_factor < -1 and value > node.right.value:
            return self.left_rotate(node)

        if balance_factor > 1 and value > node.left.value:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)

        if balance_factor < -1 and value < node.right.value:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)

        return node

    # Worst Time Complexity: O(log n)
    def delete(self, node, value):
        if not node:
            return node
        elif value < node.value:
            node.left = self.delete(node.left, value)
        elif value > node.value:
            node.right = self.delete(node.right, value)
        else:
            if not node.left:
                temp = node.right
                node = None
                return temp
            elif not node.right:
                temp = node.left
                node = None
                return temp

            temp = self.get_min_node(node.right)
            node.value = temp.value
            node.right = self.delete(node.right, temp.value)

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

        balance_factor = self.get_balance_factor(node)

        if balance_factor > 1 and self.get_balance_factor(node.left) >= 0:
            return self.right_rotate(node)

        if balance_factor < -1 and self.get_balance_factor(node.right) <= 0:
            return self.left_rotate(node)

        if balance_factor > 1 and self.get_balance_factor(node.left) < 0:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)

        if balance_factor < -1 and self.get_balance_factor(node.right) > 0:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)

        return node

    # Worst Time Complexity: O(log n)
    def add(self, value):
        self.root = self.insert(self.root, value)

    # Worst Time Complexity: O(log n)
    def remove(self, value):
        self.root = self.delete(self.root, value)
