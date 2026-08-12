# Sieve Of Eratosthenes:
# Time Complexity:
# O( n log log n )
#
# Space Complexity:
# Memory: O(n)

def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    prime = 2
    while prime * prime <= n:
        if is_prime[prime]:
            for multiple in range(prime * prime, n + 1, prime):
                is_prime[multiple] = False

        prime += 1

    primes = [i for i in range(n + 1) if is_prime[i]]

    return primes

def IOI_sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for p in range(2, int(n ** 0.5) + 1):
        if is_prime[p]:
            for multiple in range(p * p, n + 1, p):
                is_prime[multiple] = False

    return [i for i in range(n + 1) if is_prime[i]]

# Intuition / Idea:
# "Берём первое непрочёркнутое число и вычёркиваем все его кратные"
#
# Также важная оптимизация:
# Достаточно идти только до sqrt(n) так как если число составное a * b = n то хотя бы один множитель <= sqrt(n)

# Where to use:
# 1. В задачах генерация всех простых до N
# 2. Быстрая факторизация с помощью SPF (Smallest Prime Factor)
#    быстро разлагаем число на множители, часто в задачах на Codeforces
# 3. Количество простых <= N
