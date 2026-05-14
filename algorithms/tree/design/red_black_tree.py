# Red-Black Tree's:
# Height:     O( 2 log2 (n + 1) )
#
# Time Complexity:
# Search:     O(log n)
# Insert:     O(log n)
# Remove:     O(log n)
# Rotations:  O(1)
# Transplant: O(1)
#
# Space Complexity:
# Memory:     O(n)

BLACK = True
RED = False

class RedBlackNode:
    def __init__(self, value):
        self.value = value
        self.parent = None
        self.color = RED
        self.left = None
        self.right = None

    def print_color(self):
        if self.color == BLACK:
            return '(b)'
        return '(r)'


class RedBlackTree:
    def __init__(self):
        self.NIL = RedBlackNode(99999)
        self.NIL.color = BLACK
        self.NIL.left = None
        self.NIL.right = None
        self.root = self.NIL

    # O(1)
    def left_rotate(self, node):
        right_node = node.right
        node.right = right_node.left

        if right_node.left != self.NIL:
            right_node.left.parent = node

        right_node.parent = node.parent

        if node.parent is None:
            self.root = right_node
        elif node == node.parent.left:
            node.parent.left = right_node
        else:
            node.parent.right = right_node

        right_node.left = node
        node.parent = right_node


    # O(1)
    def right_rotate(self, node):
        left_node = node.left
        node.left = left_node.right

        if left_node.right != self.NIL:
            left_node.right.parent = node

        left_node.parent = node.parent

        if node.parent is None:
            self.root = left_node
        elif node == node.parent.right:
            node.parent.right = left_node
        else:
            node.parent.left = left_node

        left_node.right = node
        node.parent = left_node

    # O(log n) total
    def insert(self, value):
        new_node = RedBlackNode(value)
        new_node.left = self.NIL
        new_node.right = self.NIL

        right_node = None
        node = self.root

        while node != self.NIL:
            right_node = node

            if new_node.value < node.value:
                node = node.left
            else:
                node = node.right

        new_node.parent = right_node

        if right_node == None:
            self.root = new_node
        elif new_node.value < right_node.value:
            right_node.left = new_node
        else:
            right_node.right = new_node

        self.insert_fixup(new_node)

    # O(log n)
    def insert_fixup(self, node):
        while node.parent and node.parent.color == RED:
            if node.parent == node.parent.parent.left:
                right_node = node.parent.parent.right

                if right_node.color == RED:
                    node.parent.color = BLACK
                    right_node.color = BLACK
                    node.parent.parent.color = RED

                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)

                    node.parent.color = BLACK
                    node.parent.parent.color = RED

                    self.right_rotate(node.parent.parent)
            else:
                right_node = node.parent.parent.left

                if right_node.color == RED:
                    node.parent.color = BLACK
                    right_node.color = BLACK
                    node.parent.parent.color = RED

                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)

                    node.parent.color = BLACK
                    node.parent.parent.color = RED

                    self.left_rotate(node.parent.parent)

            if node == self.root:
                break

        self.root.color = BLACK

    # O(log n) total
    def delete(self, value):
        node = self.search(value)

        if node == self.NIL:
            return "Key not found!"

        dummy_node = node
        dummy_node_orig_color = dummy_node.color

        # case 1
        if node.left == self.NIL:
            node = node.right
            self.transplant(node, node.right)

        # case 2
        elif node.right == self.NIL:
            node = node.left
            self.transplant(node, node.left)

        # case 3
        else:
            dummy_node = self.minimum(node.right)
            dummy_node_orig_color = dummy_node.color
            node = dummy_node.right

            if dummy_node.parent == node:
                node.parent = dummy_node
            else:
                self.transplant(dummy_node, dummy_node.right)
                dummy_node.right = node.right
                dummy_node.right.parent = dummy_node

            self.transplant(node, dummy_node)
            dummy_node.left = node.left
            dummy_node.left.parent = dummy_node
            dummy_node.color = node.color

        if dummy_node_orig_color == BLACK:
            self.delete_fixup(node)

    # O(log n)
    def delete_fixup(self, node):
        while node != self.root and node.color == BLACK:
            if node == node.parent.left:
                parent_right = node.parent.right

                # type 1
                if parent_right.color == RED:
                    parent_right.color = BLACK
                    node.parent.color = RED
                    self.left_rotate(node.parent)
                    parent_right = node.parent.right

                # type 2
                if parent_right.left.color == BLACK and parent_right.right.color == BLACK:
                    parent_right.color = RED
                    node = node.parent
                else:
                    # type 3
                    if parent_right.right.color == BLACK:
                        parent_right.left.color = BLACK
                        parent_right.color = RED
                        self.right_rotate(parent_right)
                        parent_right = node.parent.right

                    # type 4
                    parent_right.color = node.parent.color
                    node.parent.color = BLACK
                    parent_right.right.color = BLACK
                    self.left_rotate(node.parent)
                    node = self.root
            else:
                parent_right = node.parent.left

                # type 1
                if parent_right.color == RED:
                    parent_right.color = BLACK
                    node.parent.color = RED
                    self.right_rotate(node.p)
                    parent_right = node.parent.left

                # type 2
                if parent_right.right.color == BLACK and parent_right.left.color == BLACK:
                    parent_right.color = RED
                    node = node.parent
                else:
                    # type 3
                    if parent_right.left.color == BLACK:
                        parent_right.right.color = BLACK
                        parent_right.color = RED
                        self.left_rotate(parent_right)
                        parent_right = node.parent.left

                    # type 4
                    parent_right.color = node.parent.color
                    node.parent.color = BLACK
                    parent_right.left.color = BLACK
                    self.right_rotate(node.parent)
                    node = self.root

        node.color = BLACK

    # O(1)
    def transplant(self, u, v):
        if u.parent == None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v

        v.parent = u.parent

        # O(h) = O(log n) for RB trees
    def minimum(self, node):
        while node.left != self.NIL:
            node = node.left

        return node

    # O(h) = O(log n) for RB trees
    def search(self, value):
        node = self.root

        while node != self.NIL and value != node.value:
            if value < node.value:
                node = node.left
            else:
                node = node.right

        return node