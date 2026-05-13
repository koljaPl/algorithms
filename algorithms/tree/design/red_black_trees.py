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


    # O(1)
    def right_rotate(self, node):


    # O(log n) total
    def insert(self, value):


    # O(log n)
    def insert_fixup(self, node):


    # O(log n) total
    def delete(self, value):


    # O(log n)
    def delete_fixup(self, node):


    # O(1)
    def transplant(self, u, v):


    # O(h) = O(log n) for RB trees
    def minimum(self, node):


    # O(h) = O(log n) for RB trees
    def search(self, value):
        