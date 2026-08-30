#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Stack
//
// Time Complexity:
// push():      O(1) amortized
// pop():       O(1)
// peek():      O(1)
// is_empty():  O(1)
// size():      O(1)
//
// Space Complexity:
// O(n)

class Stack {
private:
    vector<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    int pop() {
        if (data.empty()) {
            throw out_of_range("pop from empty stack");
        }

        int value = data.back();
        data.pop_back();

        return value;
    }

    int peek() const {
        if (data.empty()) {
            throw out_of_range("peek from empty stack");
        }

        return data.back();
    }

    bool is_empty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }
};
