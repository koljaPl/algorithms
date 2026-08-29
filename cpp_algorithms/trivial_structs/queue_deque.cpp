#include <iostream>
#include <deque>
#include <queue>

using namespace std;

// Deque
int main_deque() {
    deque<int> dq;

    // append()
    dq.push_back(10);

    // appendleft()
    dq.push_front(20);

    // peek_left()
    cout << dq.front() << '\n';

    // peek_right()
    cout << dq.back() << '\n';

    // pop()
    dq.pop_back();

    // popleft()
    dq.pop_front();

    return 0;
}

int main_queue() {
    queue<int> q;

    // enqueue
    q.push(10);
    q.push(20);
    q.push(30);

    // peek
    cout << q.front() << '\n';   // 10

    // dequeue
    q.pop();

    cout << q.front() << '\n';   // 20

    return 0;
}

// Yeah python, that easy.
