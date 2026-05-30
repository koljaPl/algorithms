# Suffix Tree:
# Time Complexity:
# building: O(N)
# search for a substring of length: O(m)
#
# Space Complexity:
# Memory:   O(N)

class SuffixTreeNode:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.children = {}
        self.suffix_link = None
        self.suffix_index = -1

class SuffixTree:
    def __init__(self, text):
        self.text = text
        self.root = SuffixTreeNode(-1, -1)
        self.active_node = self.root
        self.active_edge = -1
        self.active_length = 0
        self.remaining_suffix_count = 0
        self.leaf_end = [-1]  # Глобальный конец для всех листьев
        self.root.suffix_link = self.root
        self.size = len(text)

        self.build_suffix_tree()

    def edge_length(self, node):
        if node == self.root:
            return 0

        return node.end[0] - node.start + 1

    def walk_down(self, curr_node):
        length = self.edge_length(curr_node)

        if self.active_length >= length:
            self.active_edge += length
            self.active_length -= length
            self.active_node = curr_node

            return True

        return False

    def extend_suffix_tree(self, pos):
        self.leaf_end[0] = pos  # O(1)
        self.remaining_suffix_count += 1
        last_new_node = None

        while self.remaining_suffix_count > 0:
            if self.active_length == 0:
                self.active_edge = pos

            char = self.text[self.active_edge]

            if char not in self.active_node.children:
                self.active_node.children[char] = SuffixTreeNode(pos, self.leaf_end)
                if last_new_node is not None:
                    last_new_node.suffix_link = self.active_node
                    last_new_node = None
            else:
                next_node = self.active_node.children[char]
                if self.walk_down(next_node):
                    continue

                if self.text[next_node.start + self.active_length] == self.text[pos]:
                    if last_new_node is not None and self.active_node != self.root:
                        last_new_node.suffix_link = self.active_node
                        last_new_node = None
                    self.active_length += 1
                    break

                split_end = [next_node.start + self.active_length - 1]
                split_node = SuffixTreeNode(next_node.start, split_end)
                self.active_node.children[char] = split_node

                split_node.children[self.text[pos]] = SuffixTreeNode(pos, self.leaf_end)
                next_node.start += self.active_length
                split_node.children[self.text[next_node.start]] = next_node

                if last_new_node is not None:
                    last_new_node.suffix_link = split_node
                last_new_node = split_node

            self.remaining_suffix_count -= 1

            if self.active_node == self.root and self.active_length > 0:
                self.active_length -= 1
                self.active_edge = pos - self.remaining_suffix_count + 1
            elif self.active_node != self.root:
                self.active_node = self.active_node.suffix_link

    def set_suffix_index_by_dfs(self, node, label_height):
        if node == self.root:
            pass
        else:
            if not node.children:
                node.suffix_index = self.size - label_height
                return

        for child in node.children.values():
            self.set_suffix_index_by_dfs(child, label_height + self.edge_length(child))

    def build_suffix_tree(self):
        for phase in range(self.size):
            self.extend_suffix_tree(phase)

        self.set_suffix_index_by_dfs(self.root, 0)

# Where to use it:
# 1. Pattern Matching
# 2. Поиск всех индексов вхождений
# 3. Самая длинная повторяющаяся подстрока
# 4. Наибольшая общая подстрока двух строк (LCS)

# How to use it:
# 1. Pattern Matching
# def is_substring(tree, pattern):
#     node = tree.root
#     p_idx = 0
#
#     while p_idx < len(pattern):
#         char = pattern[p_idx]
#         if char not in node.children:
#             return False
#
#         child = node.children[char]
#
#         edge_len = child.end[0] - child.start + 1
#         for i in range(edge_len):
#             if p_idx == len(pattern):
#                 return True
#
#             if tree.text[child.start + i] != pattern[p_idx]:
#                 return False
#             p_idx += 1
#
#         node = child
#
#     return True
#
# 2. Самая длинная повторяющаяся подстрока
# def longest_repeated_substring(node, current_depth, max_depth, max_start_index):
#     if not node.children:
#         return max_depth, max_start_index
#
#     if current_depth > max_depth and current_depth > 0:
#         max_depth = current_depth
#         max_start_index = list(node.children.values())[0].start - current_depth
#
#     for child in node.children.values():
#         edge_length = child.end[0] - child.start + 1
#         max_depth, max_start_index = longest_repeated_substring(
#             child, current_depth + edge_length, max_depth, max_start_index
#         )
#
#     return max_depth, max_start_index
#
#

# Идея как у Suffix Array, но Tree.
# Скорее всего ты это не будишь использовать, намного более часто ты будешь использовать:
# Prefix Function (KMP)
# Z-Function
# Trie
# Hashing
# Suffix Array
# Suffix Automaton
