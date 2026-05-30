from collections import deque

# Aho-Corasick Algorithm:
# Time Complexity:
# build():  O( Σ ∣s∣ * alphabet length ) (if easier, then the sum of the lengths)
#               - O( Σ ∣s∣ ) for constant alphabet
# add():    O( length of word )
# search(): O( ∣text∣ + matches )
#
# Space Complexity:
# Memory:   O( m * | Σ | ), where m is the sum of the lengths
#                           of all keywords in the dictionary,
# or we also can say O( total number of trie nodes * alphabet )

class AhoCorasick:
    ALPHABET = 26
    FIRST = ord('a')

    class Node:
        __slots__ = (
            "next",
            "link",
            "out",
        )

        def __init__(self):
            self.next = [-1] * AhoCorasick.ALPHABET
            self.link = 0
            self.out = []

    def __init__(self):
        self.nodes = [self.Node()]

    def build(self) -> None:
        q = deque()

        # Инициализация детей корня
        for c in range(self.ALPHABET):
            u = self.nodes[0].next[c]

            if u != -1:
                self.nodes[u].link = 0
                q.append(u)
            else:
                self.nodes[0].next[c] = 0

        # BFS
        while q:
            v = q.popleft()

            for c in range(self.ALPHABET):
                u = self.nodes[v].next[c]

                if u != -1:
                    # suffix link
                    link = self.nodes[v].link
                    self.nodes[u].link = self.nodes[self.nodes[v].link].next[c]

                    # наследуем output
                    self.nodes[u].out += self.nodes[self.nodes[u].link].out

                    # or...
                    # self.nodes[u].out.extend(
                    #     self.nodes[self.nodes[u].link].out
                    # )

                    q.append(u)

                else:
                    # automaton transition
                    self.nodes[v].next[c] = (
                        self.nodes[self.nodes[v].link].next[c]
                    )


    def add_word(self, word: str, word_id: int) -> None:
        v = 0

        for ch in word:
            c = ord(ch) - self.FIRST

            if self.nodes[v].next[c] == -1:
                self.nodes[v].next[c] = len(self.nodes)
                self.nodes.append(self.Node())

            v = self.nodes[v].next[c]

        self.nodes[v].out.append(word_id)

    def search(self, text: str):
        v = 0

        matches = []

        for i, ch in enumerate(text):
            c = ord(ch) - self.FIRST

            v = self.nodes[v].next[c]

            for word_id in self.nodes[v].out:
                matches.append((i, word_id))

        return matches

# Intuition / Idea:
# " Ахо-Корасик — это trie, который умеет умно откатываться как KMP и поэтому ищет много строк одновременно за линейное время "
# " Этот алгоритм решает задачу «Дан набор строк (паттернов). Нужно быстро искать все их вхождения в тексте.» "

# How to use it?
# patterns = [
#     "he",
#     "she",
#     "hers",
#     "his"
# ]
#
# ac = AhoCorasick()
#
# for i, pattern in enumerate(patterns):
#     ac.add_word(pattern, i)
#
# ac.build()
#
# text = "ahishers"
#
# matches = ac.search(text)
#
# for pos, pattern_id in matches:
#     word = patterns[pattern_id]
#
#     end_pos = pos
#     start_pos = pos - len(word) + 1
#
#     print(
#         f"Found '{word}' "
#         f"at [{start_pos}, {end_pos}]"
#     )

# Where to use:
# 1. Найти все паттерны
# 2. Forbidden strings:
#       Например:
#           " найти количество строк длины n,
#           которые НЕ содержат плохих подстрок "
#
#       - Тогда:
#           строим AC automaton
#           DP по состояниям автомата
# 3. Shortest string containing all patterns
# 4. Lexicographically smallest valid string
# 5. DP по автомату
# 6. Count occurrences of each pattern
#
# Также в олимпиадных задачах:
#
# Когда есть:
#
# много шаблонов
# один большой текст
# нужно искать все одновременно
#
# Типичные формулировки:
#
# найти количество вхождений
# проверить существование
# найти минимальную строку
# DP по автомату
# BFS по автомату
# forbidden strings
# mask DP + AC automaton
