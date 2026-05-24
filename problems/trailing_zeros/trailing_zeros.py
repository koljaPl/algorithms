import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())

    zeros = 0
    divider = 5

    while n >= divider:
        zeros += n // divider
        divider *= 5

    print(zeros)

main()

# Формула Лежандра:
#
# Формула Лежандра нужно для того, чтобы узнавать степень вхождения простого числа в факториал.
# Вычислить значение степени вхождения простого числа р в число n! можно за асимптотику О( log(p) n ).
# Сама формула выглядит так: v(n!)=[n / p * 1]+[n / p * 2]+[n / p * 3]+... Нетрудно доказать, что она верна.
