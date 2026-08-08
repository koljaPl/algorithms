# Suffix Automaton:
# Time Complexity:
# building():                           O(n)
# check for substring:                  O(length)
# LCS of two strings:                   O(n + m)
# counting occurrences of a pattern:    O(n)
#
# Space Complexity:
# Memory: O(n)

class SuffixAutomaton:
    class State:
        __slots__ = ("next", "link", "length")

        def __init__(self):
            self.next = {}
            self.link = -1
            self.length = 0

    def __init__(self):
        self.states = [self.State()]
        self.last = 0

    def extend(self, c):
        curr = len(self.states)

        self.states.append(self.State())
        self.states[curr].length = self.states[self.last].length + 1

        p = self.last

        while p != -1 and c not in self.states[p].next:
            self.states[p].next[c] = curr
            p = self.states[p].link

        if p == -1:
            self.states[curr].link = 0
        else:
            q = self.states[p].next[c]

            if self.states[p].length + 1 == self.states[q].length:
                self.states[curr].link = q
            else:
                clone = len(self.states)

                self.states.append(self.State())

                self.states[clone].length = self.states[p].length + 1
                self.states[clone].next = self.states[q].next.copy()
                self.states[clone].link = self.states[q].link

                while p != -1 and self.states[p].next[c] == q:
                    self.states[p].next[c] = clone
                    p = self.states[p].link

                self.states[q].link = self.states[curr].link = clone

        self.last = curr

    def build(self, s):
        for c in s:
            self.extend(c)

# How to use:
# sa = SuffixAutomaton()
# sa.build("ababa")

# Проверка подстроки:
# def contains(sa, t):
#     v = 0
#     for c in t:
#         if c not in sa.states[v].next:
#             return False
#         v = sa.states[v].next[c]
#     return True
#
# Количество подстрок:
# def count_substrings(sa):
#     res = 0
#     for v in range(1, len(sa.states)):
#         res += sa.states[v].length - sa.states[sa.states[v].link].length
#     return res

# Intuition / Idea:
# Suffix Automaton - это минимальный DFA, распознающий все подстроки строки
# Или ещё проще:
# "умная карта всех возможных путей по строке"
#
# Представь строку s = "ababa"
#
# Suffix Automaton строит структуру, которая умеет:
#
# отвечать, встречается ли подстрока в s
# находить количество различных подстрок
# находить самую длинную повторяющуюся подстроку
# находить LCS двух строк (очень важно)
# делать это за линейное время
# Главная идея:
#
# SA хранит все подстроки строки, но в сжатом виде.
#
# Если наивно:
#
# все подстроки → O(n**2)
# SA → O(n)

# Что такое состояние (state) в SA
# Каждое состояние хранит:
# len  — максимальная длина строки в этом состоянии
# link — suffix link (как "переход к меньшему суффиксу")
# next — переходы по символам
# Состояние = класс всех подстрок, которые заканчиваются одинаково "по структуре".

# Suffix Link — ключевая магия
# Suffix link ведёт от состояния, которое представляет длинные подстроки, к состоянию с их "наибольшим суффиксом".
# Это как:
# "срезать первый символ из всех подстрок этого состояния"

# Как строится SA
# Мы добавляем символы по одному.
# Для каждого нового символа:
# создаём новое состояние
# обновляем переходы
# если нужно -> клонируем состояние
#
# Если два разных пути приводят к одному состоянию, но их длины различаются - мы создаём clone.

# Алгоритм построения:
#
# Для каждого символа c:
#
# создаём новое состояние cur
# идём по suffix links назад и добавляем переходы c
# если такого перехода нет -> ставим
# если есть конфликт:
# либо просто link
# либо clone

# Where to use (problems):
# Когда видишь:
#       "substring"
#       "number of distinct substrings"
#       "longest repeated substring"
#       "LCS of two strings"
#       "count occurrences of patterns"
#
#       -> почти всегда SA подходит
