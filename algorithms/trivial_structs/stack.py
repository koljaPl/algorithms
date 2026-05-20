# Stack
# Time Complexity:
# push():       O(1) amortized
# pop():        O(1)
# peek():       O(1)
# is_empty():   O(1)
# len():        O(1)
#
# Space Complexity:
# Memory: O(n)

class Stack:
    def __init__(self):
        self.data = []

    def push(self, data):
        self.data.append(data)

    def pop(self):
        if not self.data:
            raise IndexError("pop from empty stack")

        return self.data.pop()

    def peek(self):
        if not self.data:
            raise IndexError("peek from empty stack")

        return self.data[-1]

    def is_empty(self):
        return len(self.data) == 0

    def __len__(self):
        return len(self.data)