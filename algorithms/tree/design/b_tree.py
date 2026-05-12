# I started watching a video about B-trees. It's interesting, but I'm not quite sure yet how to implement them.

class BTreeNode:
    def __init__(self, leaf):
        self.leaf = leaf

        self.keys = []
        self.children = []

class BTree:
    def __init__(self, t):
        self.t = t
        self.root = BTreeNode(True)

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


    def insert(self, value):
        t = self.t
        root = self.root

        if len(root.keys) == (2 * t) - 1:
            new_root = BTreeNode(False)

            self.root = new_root

            new_root.children.insert(0, root)

            self.split_child(new_root, 0)
            self.insert_non_full(new_root, value)
        else:
            self.insert_non_full(root, value)

    def insert_non_full(self, node, value):
        t = self.t
        i = len(node.keys) - 1

        # find the correct spot in the leaf to insert the key
        if node.leaf:
            node.keys.append(None)

            while i >= 0 and value < node.keys[i]:
                node.keys[i + 1] = node.keys[i]
                i -= 1

            node.keys[i + 1] = value
        else:
            while i >= 0 and value < node.keys[i]:
                i -= 1
            i += 1

            # if child node is full, split it
            if len(node.children[i].keys) == (2 * t) - 1:
                self.split_child(node, i)

                if value > node.keys[i]:
                    i += 1

            self.insert_non_full(node.children[i], value)

    def delete(self, node, value):
        t = self.t
        i = 0

        while i < len(node.keys) and value > node.keys[i]:
            i += 1

        if node.leaf:
            if i < len(node.keys) and node.keys[i] == value:
                node.keys.pop(i)
            return

        if i < len(node.keys) and node.keys[i] == value:
            return self.delete_internal_node(node, value, i)
        elif len(node.children[i].keys) >= t:
            self.delete(node.children[i], value)
        else:
            if i != 0 and i + 2 < len(node.children):
                if len(node.children[i - 1].keys) >= t:
                    self.delete_sibling(node, i, i - 1)
                elif len(node.children[i + 1].keys) >= t:
                    self.delete_sibling(node, i, i + 1)
                else:
                    self.delete_merge(node, i, i + 1)
            elif i == 0:
                if len(node.children[i + 1].keys) >= t:
                    self.delete_sibling(node, i, i + 1)
                else:
                    self.delete_merge(node, i, i + 1)
            elif i + 1 == len(node.children):
                if len(node.children[i - 1].keys) >= t:
                    self.delete_sibling(node, i, i - 1)
                else:
                    self.delete_merge(node, i, i - 1)
            self.delete(node.children[i], value)

    def delete_internal_node(self, node, value, i):
        t = self.t

        if node.leaf:
            if node.keys[i] == value:
                node.keys.pop(i)
            return

        if len(node.children[i].keys) >= t:
            node.keys[i] = self.delete_predecessor(node.children[i])
            return
        elif len(node.children[i + 1].keys) >= t:
            node.keys[i] = self.delete_successor(node.children[i + 1])
            return
        else:
            self.delete_merge(node, i, i + 1)
            self.delete_internal_node(node.children[i], value, self.t - 1)

    def delete_predecessor(self, node):
        if node.leaf:
            return node.keys.pop()

        n = len(node.keys) - 1

        if len(node.children[n].keys) >= self.t:
            self.delete_sibling(node, n + 1, n)
        else:
            self.delete_merge(node, n, n + 1)

        return self.delete_predecessor(node.children[n])

    def delete_successor(self, node):
        if node.leaf:
            return node.keys.pop(0)

        if len(node.children[1].keys) >= self.t:
            self.delete_sibling(node, 0, 1)
        else:
            self.delete_merge(node, 0, 1)

        return self.delete_successor(node.children[0])

    def delete_merge(self, node, i, j):
        curr_node = node.children[i]

        if j > i:
            right_sibling_node = node.children[j]
            curr_node.keys.append(node.keys[i])

            for k in range(len(right_sibling_node.keys)):
                curr_node.keys.append(right_sibling_node.keys[k])

                if len(right_sibling_node.children) > 0:
                    curr_node.children.append(right_sibling_node.children[k])

            if len(right_sibling_node.children) > 0:
                curr_node.children.append(right_sibling_node.children.pop())

            new_node = curr_node

            node.keys.pop(i)
            node.children.pop(j)
        else:
            left_sibling_node = node.children[j]
            left_sibling_node.keys.append(node.keys[j])

            for k in range(len(curr_node.keys)):
                left_sibling_node.keys.append(curr_node.keys[k])

                if len(left_sibling_node.children) > 0:
                    left_sibling_node.children.append(curr_node.children[k])

            if len(left_sibling_node.children) > 0:
                left_sibling_node.children.append(curr_node.children.pop())

            new_node = left_sibling_node

            node.keys.pop(j)
            node.children.pop(i)

        if node == self.root and len(node.keys) == 0:
            self.root = new_node

    def delete_sibling(self, node, i, j):
        curr_node = node.children[i]

        if i < j:
            right_sibling_node = node.children[j]
            curr_node.keys.append(node.keys[i])
            node.keys[i] = right_sibling_node.keys[0]

            if len(right_sibling_node.children) > 0:
                curr_node.children.append(right_sibling_node.children[0])
                right_sibling_node.children.pop(0)

            right_sibling_node.keys.pop(0)
        else:
            left_sibling_node = node.children[j]

            curr_node.keys.insert(0, node.keys[i - 1])

            node.keys[i - 1] = left_sibling_node.keys.pop()

            if len(left_sibling_node.children) > 0:
                curr_node.children.insert(0, left_sibling_node.children.pop())