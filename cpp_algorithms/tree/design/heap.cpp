#include <bits/stdc++.h>
using namespace std;

// Heap - Min Heap and Max Heap
//
// Height:        O(log n)
//
// Insert:        O(log n)
// Pop:           O(log n)
// Top:           O(1)
// Search:        O(n)
//
// Heapify list:  O(n)

int getParent(int i) {
    return (i - 1) / 2;
}

int getLeft(int i) {
    return 2 * i + 1;
}

int getRight(int i) {
    return 2 * i + 2;
}


class MinHeap {
private:
    vector<int> heap;

    void siftUp(int i) {
        while (i > 0) {
            int parent = getParent(i);

            if (heap[parent] <= heap[i]) {
                break;
            }

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void siftDown(int i) {
        int n = heap.size();

        while (true) {
            int left = getLeft(i);
            int right = getRight(i);

            int smallest = i;

            if (left < n && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if (right < n && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest == i) {
                break;
            }

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        int minimum = heap[0];

        int last = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heap[0] = last;
            siftDown(0);
        }

        return minimum;
    }

    int top() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        return heap[0];
    }

    void heapify(const vector<int>& arr) {
        heap = arr;

        for (int i = (int)heap.size() / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    int size() const {
        return heap.size();
    }

    bool empty() const {
        return heap.empty();
    }

    void print() const {
        for (int x : heap) {
            cout << x << ' ';
        }
        cout << '\n';
    }
};


class MaxHeap {
private:
    vector<int> heap;

    void siftUp(int i) {
        while (i > 0) {
            int parent = getParent(i);

            if (heap[parent] >= heap[i]) {
                break;
            }

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void siftDown(int i) {
        int n = heap.size();

        while (true) {
            int left = getLeft(i);
            int right = getRight(i);

            int largest = i;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest == i) {
                break;
            }

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        int maximum = heap[0];

        int last = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heap[0] = last;
            siftDown(0);
        }

        return maximum;
    }

    int top() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        return heap[0];
    }

    void heapify(const vector<int>& arr) {
        heap = arr;

        for (int i = (int)heap.size() / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    int size() const {
        return heap.size();
    }

    bool empty() const {
        return heap.empty();
    }

    void print() const {
        for (int x : heap) {
            cout << x << ' ';
        }
        cout << '\n';
    }
};

// Intuition / Idea:
// "Сделать так, чтобы самый важный элемент ( обычно самый дешевый/дорогой ) всегда находился сверху"
// 
// Основная идея:
// Heap хранит элементы так, чтобы выполнялось правило:

// Для каждого узла:

// родитель <= дети
// ( для Min Heap )

// Например:

//           1
//         /   \
//        2     3
//       / \   / \
//      7  5 10  8

// Тут:

// 1 <= 2, 3
// 2 <= 7, 5
// 3 <= 10, 8

// Поэтому минимум всегда находится в корне.

// ---------------------------------------------------------------------------------------------------

// Where can we use it (Problems like Codeforces and AtCoder)?

// 1. Find minimum/maximum (specially many times or dynamically)
// 2. Top K (k largest or k smallest)
// 3. "Elements are always coming"
// 4. Priority Matters
// 5. Shortest Something (like path, in that thing we can add his Majesty the Dijkstra algorithm,
//                        the rising star A*, and, for example, best-first search)
// 6. Closest Something (like k the closest points)
// 7. Data Stream (stream, online, real-time)

// But the best way to use heap is dynamic minimum/maximum
