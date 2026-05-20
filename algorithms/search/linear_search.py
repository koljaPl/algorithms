# Linear Search

array = [2, 8, 5, 3, 9, 4, 1]
print("Before: ", array)

# Time Complexity:      θ(n)
# Space Complexity :    O(1)
def linear_search(array, target):

    for index in range(len(array)):
        if array[index] == target:
            return index

    return -1


print("Answer: ", linear_search(array, 4))

