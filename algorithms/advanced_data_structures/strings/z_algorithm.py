# Z-Algorithm:
# Time Complexity:
# O(n)
#
# Space Complexity:
# O(n)

def z_function(s):
    n = len(s)
    z = [0] * n

    l = 0
    r = 0

    for i in range(1, n):
        if i < r:
            z[i] = min(r - i, z[i - l])

        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1

        if i + z[i] > r:
            l = i
            r = i + z[i]

    return z

# Usage:
def find_pattern(text, pattern):
    s = pattern + "#" + text
    z = z_function(s)

    result = []

    for i in range(len(pattern) + 1, len(s)):
        if z[i] == len(pattern):
            result.append(i - len(pattern) - 1)

    return result


print(find_pattern("abacaba", "aba"))
# [0, 4]
