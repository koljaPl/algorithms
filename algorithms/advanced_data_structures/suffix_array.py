# Suffix Array:
# Time Complexity:
# build_suffix_array():             O( n log n )
# build_longest_common_prefix():    O( n log n ) + O( n )
#
# compare():                        Worst: O( m ); AVG: O(m log n)
# search() / find():                O( m log n )
# count occurrences:                O( m log n )
#
# Space Complexity:
# Suffix Array:     O( n )
# Rank Array:       O( n )
# LCP Array:        O( n )
#
# Total:
# Memory:           O( n )

class SuffixArray:
    def __init__(self, s):
        self.s = s
        self.n = len(s)
        self.sa = self.build_suffix_array()
        self.lcp = self.build_longest_common_prefix()

    def build_suffix_array(self):
        s = self.s
        n = self.n

        # initial ranking by characters
        rank = [ord(c) for c in s]
        sa = list(range(n))

        k = 1
        while k < n:
            sa.sort(key=lambda i: (rank[i], rank[i + k] if i + k < n else -1))

            new_rank = [0] * n
            new_rank[sa[0]] = 0

            for i in range(1, n):
                prev = sa[i - 1]
                curr = sa[i]

                prev_key = (rank[prev], rank[prev + k] if prev + k < n else -1)
                curr_key = (rank[curr], rank[curr + k] if curr + k < n else -1)

                new_rank[curr] = new_rank[prev] + (curr_key != prev_key)

            rank = new_rank
            k <<= 1

        return sa

    def build_longest_common_prefix(self):
        s = self.s
        n = self.n
        sa = self.sa

        rank = [0] * n
        for i, v in enumerate(sa):
            rank[v] = i

        lcp = [0] * (n - 1)
        h = 0

        for i in range(n):
            if rank[i] == 0:
                continue

            j = sa[rank[i] - 1]

            while i + h < n and j + h < n and s[i + h] == s[j + h]:
                h += 1

            lcp[rank[i] - 1] = h

            if h:
                h -= 1

        return lcp

# How to use:

def compare(s, i, pattern):
    # comparing s[i:] and pattern
    n = len(s)
    m = len(pattern)

    for k in range(m):
        if i + k >= n:
            return -1
        if s[i + k] != pattern[k]:
            return -1 if s[i + k] < pattern[k] else 1

    return 0

def find(s, sa, pattern):
    n = len(sa)

    l, r = 0, n - 1

    while l <= r:
        mid = (l + r) // 2
        i = sa[mid]

        if compare(s, i, pattern) >= 0:
            r = mid - 1
        else:
            l = mid + 1

    start = l

    l, r = 0, n - 1

    while l <= r:
        mid = (l + r) // 2
        i = sa[mid]

        if compare(s, i, pattern) <= 0:
            l = mid + 1
        else:
            r = mid - 1

    end = r

    return max(0, end - start + 1)

# sa = SuffixArray(s)
#
# # поиск подстроки
# count = find(s, sa.sa, pattern)
#
# # LCP
# lcp = sa.lcp
#
# for i in sa.sa:
#     print(s[i:])
#
# Поиск подстроки:
# def lower_bound(s, sa, pattern):
#     n = len(sa)
#     l, r = 0, n
#
#     while l < r:
#         m = (l + r) // 2
#         i = sa[m]
#
#         if s[i:i+len(pattern)] < pattern:
#             l = m + 1
#         else:
#             r = m
#
#     return l
#
# def upper_bound(s, sa, pattern):
#     n = len(sa)
#     l, r = 0, n
#
#     while l < r:
#         m = (l + r) // 2
#         i = sa[m]
#
#         if s[i:i+len(pattern)] <= pattern:
#             l = m + 1
#         else:
#             r = m
#
#     return l
#
# If it exist:
# def exists(s, sa, pattern):
#     n = len(s)
#     idx = lower_bound(s, sa, pattern)
#
#     if idx == len(sa):
#         return False
#
#     i = sa[idx]
#     return s[i:i+len(pattern)] == pattern
#
# Сколько раз встречается pattern:
# def count_occurrences(s, sa, pattern):
#     l = lower_bound(s, sa, pattern)
#     r = upper_bound(s, sa, pattern)
#     return r - l
#
# s = "banana"
# sa = SuffixArray(s).sa
#
# print(count_occurrences(s, sa, "ana"))
#
# def find_positions(s, sa, pattern):
#     l = lower_bound(s, sa, pattern)
#     r = upper_bound(s, sa, pattern)
#
#     return sorted(sa[l:r])
#

# Intuition / Idea:
# Suffix Array (SA) — это массив индексов всех суффиксов строки, отсортированных лексикографически.
# Suffix array — это многократная сортировка "двухполовинных ключей" где каждый шаг
# (s[i..i+k], s[i+k..i+2k]) и мы постепенно "учим" структуру строки всё глубже.
#
# " Мы сортируем не строки, а их 'ранги' "
#
# Suffix Array превращает строку в структуру, где:
#
# все суффиксы отсортированы
# значит, все подстроки “группируются”
# можно делать бинарный поиск по Suffix Array     <-- Самое главное
#
# Этапы:
# Шаг 1: сортируем по 1 символу
#   Каждый суффикс — это строка, но сначала смотрим только на первый символ.
# Шаг 2: удваиваем длину сравнения
#   Сравниваем пары:
#       (rank[i], rank[i + k])
#       где k = 1, 2, 4, 8, ...
#
# Это называется Prefix doubling algorithm
#
# После построения SA ты можешь:
# 1. Проверка подстроки
#           Проверить, есть ли pattern в s за O( |pattern| log n ) (через бинарный поиск по suffix array)
# 2. Количество вхождений
#           Сколько раз встречается подстрока → тоже через два бинарных поиска
# 3. LCP (Longest Common Prefix)
#       Можно построить LCP array и решать:
#           1. повторяющиеся подстроки
#           2. разные задачи на дубликаты
#           3. плагиат-детекторы
#           4. compression

# Where to use (problems):
# 1. Поиск подстроки
#       много запросов
#       большой текст
# 2. Кол-во различных подстрок
#       answer = n * ( n + 1 ) / 2 - sum(LCP)
# 3. Longest repeated substring
#       максимум LCP
# 4. Две строки
#       найти общие подстроки
#       longest common substring
# 5. Offline string queries
#       (очень часто с hashing + SA)
# 6. number of distinct substrings
# 7. longest repeated substring
# 8. substring queries offline
# 9. string matching + multiple patterns
# 10. suffix problems в bioinformatics
