from collections import defaultdict

# Trie (Prefix Tree) Data Structure:
#
# Time Complexity:
# insert()          O(L)
# search()          O(L)
# starts_with()     O(L)
# delete()          O(L)
# count_prefix()    O(L)
# Where L is length of word (or prefix)
#
# Acces to nodes letters:
# TrieNode:                     amortized O(1)
# TrieNodeMemoryOptimized:      Real O(1) (isn't it cool, huh?)
#
# Space Complexity:
# Memory:
# Worst Case:
# O(N * L * R)
# Where:
# N is the number of keys/strings
# L is the average or maximum length of a string
# R is the alphabet size
#
# but, it's more true:
#
# Space: O(total characters inserted)
# Worst-case: O(N * L)
#
# or we also can say:
# O( total number of nodes * R )
# or even
# O( sum of lengths of all inserted strings * R )

class TrieNode:
    def __init__(self):
        self.children = {} # You can also use something like defaultdict(dict) for better boilerplate
        self.is_word = False
        self.prefix_count = 0

# Slightly better in terms of memory
# But you’ll have to add everything as numbers ( ord() )
# and only a-z lowercase letters
# and also requires mapping: char -> index (ord(c) - ord('a'))
class TrieNodeMemoryOptimized:
    def __init__(self):
        self.children = [None] * 26
        self.is_word = False
        self.prefix_count = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    # O(L)
    def insert(self, word):
        node = self.root

        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()

            node = node.children[char]
            node.prefix_count += 1

        node.is_word = True

    # O(L)
    def search(self, word):
        node = self.root

        for char in word:
            if char not in node.children:
                return False

            node = node.children[char]

        return node.is_word

    # O(L)
    def starts_with(self, prefix):
        node = self.root

        for char in prefix:
            if char not in node.children:
                return False

            node = node.children[char]

        return True

    # O(L)
    # This does NOT remove nodes, only unmarks word existence
    def remove_word_flag(self, word):
        # We also can name it delete, but it's not very true
        node = self.root

        for char in word:
            if char not in node.children:
                return False
                # return "No Word Found"

            node = node.children[char]

        node.is_word = False
        return True
        # return "Successfully Deleted"

    # O(L)
    def count_prefix(self, prefix):
        # prefix_count excludes or includes word ending at node depending on definition
        node = self.root

        for char in prefix:
            if char not in node.children:
                return 0

            node = node.children[char]

        return node.prefix_count

# Intuition / Idea:
# Trie = дерево префиксов, где строки “склеиваются” по общим началам, и поиск становится очень быстрым по длине слова.
#
# Trie — это дерево, где:
# каждая вершина = символ
# путь от корня до узла = префикс строки
# слово заканчивается в узле, где стоит “флаг окончания”

# Usage:
# trie = Trie()
#
# trie.insert("cat")
# trie.insert("car")
# trie.insert("care")
#
# print(trie.search("cat"))       # True
# print(trie.search("ca"))        # False
#
# print(trie.starts_with("ca"))   # True
# print(trie.starts_with("dog"))  # False

# Where to use in problems:
# 1. Word Dictionary
# 2. Maximum XOR (Binary Trie)
# 3. Prefix counting
#          - сколько слов начинается с prefix
# 4. Unique Prefix
#          - Найти минимальный уникальный префикс каждого слова.
# 5. Lexicographical traversal
