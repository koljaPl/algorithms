# Binary Search

array = [num for num in range(100)]

# Time Complexity:      O(log n)
# Space Complexity :    O(1)
# Number of Steps:      O(log)
def binary_search(array, target):
    left = 0
    right = len(array) - 1

    while left <= right:
        mid = (left + right) // 2
        # or mid = left + (right - left) // 2

        if array[mid] == target:
            return mid
        elif array[mid] > target:
            right = mid - 1
        else:
            left = mid + 1

    return -1


print("Answer: ", binary_search(array, 23))
