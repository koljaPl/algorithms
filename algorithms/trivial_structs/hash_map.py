# Hash Map
# Time Complexity:
# put():        Avg: O(1) ; Worst: O(n)
# get():        Avg: O(1) ; Worst: O(n)
# remove():     Avg: O(1) ; Worst: O(n)
#
# Space Complexity:
# Memory:       O(n)

class HashMap:
    def __init__(self, size=1024):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def put(self, key, value):
        index = self._hash(key)
        bucket = self.table[index]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket[i] = (key, value)
                return

        bucket.append((key, value))

    def get(self, key):
        index = self._hash(key)
        bucket = self.table[index]

        for k, v in bucket:
            if k == key:
                if k == key:
                    return v

        raise KeyError(key)

    def remove(self, key):
        index = self._hash(key)
        bucket = self.table[index]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket.pop(i)
                return

        raise KeyError(key)

    def contains(self, key):
        index = self._hash(key)
        bucket = self.table[index]

        for k, v in bucket:
            if k == key:
                return True

        return False

# How to use it:
# mp = HashMap()
#
# mp.put("apple", 10)
# mp.put("banana", 20)
#
# print(mp.get("apple"))     # 10
#
# mp.put("apple", 15)
#
# print(mp.get("apple"))     # 15
#
# mp.remove("banana")
#
# print(mp.contains("banana"))  # False
