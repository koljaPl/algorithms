# I started watching a video about B-trees. It's interesting, but I'm not quite sure yet how to implement them.

class BTreeNode:
    def __init__(self, leaf):
        self.leaf = leaf

        self.keys = []
        self.children = []

class BTree:
    def __init__(self, t):
        self.t = t
        self.root = BTreeNode(t)

    def search(self, key, node=None):
        node = self.root if node is None else node

        i = 0
        while i < len(node.keys) and key > node.keys[i]:
            i += 1
        if i < len(node.keys) and key == node.keys[i]:
            return (node, i)
        elif node.leaf:
            return None
        else:
            return self.search(key, node.children[i])


    def split_child(self, node, i):
        t = self.t

        # full child of node
        i_node = node.children[i]

        # create a new node and add it to i_node's list of children
        new_node = BTreeNode(i_node.leaf)
        node.children.insert(i + 1, new_node)

        # insert the median of the full child i_node into node
        node.keys.insert(i, i_node.keys[t - 1])

        # split apart i_node's keys into i_node & new_node
        new_node.keys = i_node.keys[t: (2 * t) - 1]
        i_node.keys = i_node.keys[0: t - 1]

        # if i_node is not a leaf, we reassign i_node's children to i_node & new_node
        if not i_node.leaf:
            new_node.children = i_node.children[t: 2 * t]
            i_node.children = i_node.children[0: t]  # video incorrectly has t-1


    def insert(self, k):


    def insert_non_full(self, x, k):


    def delete(self, x, k):


    def delete_internal_node(self, x, k, i):


    def delete_predecessor(self, x):


    def delete_successor(self, x):


    def delete_merge(self, x, i, j):


    def delete_sibling(self, x, i, j):