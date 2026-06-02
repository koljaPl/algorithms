# Fenwick Tree (Binary Indexed Tree)
#
# Time complexity:
# Building a Fenwick tree:  O(n log n)
# Optimal construction:     O(n)
# Updating an element:      O(log n)
# Prefix sum:               O(log n)
# Sum over a range:         O(log n)
#
# Memory usage:             O(n)

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    # Add function (also known as update),
    # and ofcourse you can use it like -value for subtract from bit, but I think it's not that cool
    def add(self, i, value):
        while i <= self.n:
            self.bit[i] += value
            i += i & -i

    def subtract(self, i, value):
        while i <= self.n:
            self.bit[i] -= value
            i += i & -i

    def prefix_sum(self, i):
        prefix_sum = 0

        while i > 0:
            prefix_sum += self.bit[i]
            i -= i & -i

        return prefix_sum

    def range_sum(self, start, end):
        return self.prefix_sum(end) - self.prefix_sum(start - 1)

# How to use:
#
# # creating
# ft = FenwickTree(n
#
# for i in range(1, n + 1):
#     ft.add(i, a[i])
#
# # update
# delta = new_value - a[i]
# a[i] = new_value
# ft.add(i, delta)
#
# # query
# res = ft.range_sum(l, r)
# print(res)
#
# res = ft.prefix_sum(x)

# Intuition:
# Fenwick Tree это способ хранить суммы перекрывающихся диапазонов через битовые прыжки
# Fenwick Tree это структура, которая позволяет собирать и разбирать суммы через прыжки по младшему установленному биту числа
#
# Главная проблема:
# Быстро поддерживать массив, где нужно:
#
# менять один элемент
# быстро считать сумму на префиксе / отрезке
#
# Обычный массив:
# update: O(1)
# prefix sum: O(n) ❌
#
# Prefix sums массив:
# update: O(n) ❌
# query: O(1)
#
# Fenwick Tree — компромисс:
# update: O(log n)
# query: O(log n)

# Idea:
# Fenwick Tree хранит суммы блоков разного размера, причём эти блоки определяются через:
# i & -i
#
# Это выражение даёт:
# младший установленный бит числа i
# (LSB — least significant bit)

# Where to use:
# 1. Много запросов “изменить + посчитать сумму”
# 2. Частоты / подсчёт количества элементов
# 3. Инверсии (очень важная классика)
#           Сколько пар (i < j), где a[i] > a[j]
# 4. “Сколько элементов в диапазоне значений”
# 5. нельзя заранее обработать все запросы
