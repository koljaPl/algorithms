# KMP (Knuth–Morris–Pratt) Algorithm:
# Time Complexity:
# building:     O(m)
# searching:    O(n)
#
# Total:
# O( n + m ), where
# n — длина текста
# m — длина шаблона
#
# Space Complexity:
# Memory:       O(m)

def building_pi(string):
    n = len(string)
    pi = [0] * n

    for i in range(1, n):
        j = pi[i - 1]

        while j > 0 and string[i] != string[j]:
            j = pi[j - 1]

        if string[i] == string[j]:
            j += 1

        pi[i] = j

    return pi

def kmp_algorithm(text, pattern):
    pi = building_pi(pattern)

    j = 0
    res = []

    for i in range(len(text)):
        while j > 0 and text[i] != pattern[j]:
            j = pi[j - 1]

        if text[i] == pattern[j]:
            j += 1

        if j == len(pattern):
            res.append(i - len(pattern) + 1)
            j = pi[j - 1]

    return res

# How to use:
# text = "AABRAACADABRA"
# pattern = "ABRA"
#
# result_indices = kmp_algorithm(text_example, pattern_example)
#
# print(f"Найденные индексы начала вхождений: {result_indices}") # Вывод программы будет: [1, 9]

# Intuition / Idea:
# Если ты дошёл до несовпадения ты не начинаешь с нуля как в обычном линейном поиске по строкам,
# Ты говоришь:
# “Окей, у меня уже есть совпавший кусок — попробуем сдвинуть шаблон так, чтобы он максимально совпал сам с собой.”

# KMP — это не просто “алгоритм поиска”
# Это способ использовать внутреннюю структуру строки

# КМП состоит из 2 частей:
# Этап 1 - Построение:
# Построение π - функции (preprocessing) для шаблона pattern
#
# Этап 2 - Поиск в тексте:
#   1. Идём по тексту и поддерживаем:
#   2. сколько символов шаблона уже совпало
#   3. При несовпадении:
#           используем массив π, чтобы откатиться без потери информации

# Почему это быстро
# Каждый символ:
# текста обрабатывается максимум 1–2 раза
# шаблон тоже “двигается назад” не более O(n + m)
# Итог: O(n + m)

# Where to use:
# 1. Поиск подстроки
#       - найти все вхождения строки
# 2. Поиск периодичности строки
#       - минимальный период строки
#       - циклы в строке
# 3. String matching задачи на CF
#       - “find occurrences”
#       - “count substrings”
#       - “string borders”
# 4. Комбинации строк
#       - построение автоматов
#       - Aho–Corasick (как расширение KMP)
