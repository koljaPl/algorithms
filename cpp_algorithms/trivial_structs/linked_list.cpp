#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Linked List
//
// Time Complexity:
// append():     O(1)
// prepend():    O(1)
// delete():     O(n)
// find():       O(n)
// get_size():   O(1)
//
// Space Complexity:
// Memory:       O(n)

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // O(1)
    void append(int data) {
        Node* node = new Node(data);

        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        size++;
    }

    // O(1)
    void prepend(int data) {
        Node* node = new Node(data);

        if (head == nullptr) {
            head = tail = node;
        } else {
            node->next = head;
            head = node;
        }

        size++;
    }

    // O(n)
    void delete_node(int data) {
        if (head == nullptr)
            return;

        if (head->data == data) {
            Node* temp = head;

            head = head->next;
            delete temp;

            size--;

            if (head == nullptr)
                tail = nullptr;

            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr != nullptr) {
            if (curr->data == data) {
                prev->next = curr->next;

                if (curr == tail)
                    tail = prev;

                delete curr;
                size--;

                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    // O(n)
    Node* find(int data) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == data)
                return curr;

            curr = curr->next;
        }

        return nullptr;
    }

    // O(1)
    int get_size() {
        return size;
    }

    ~LinkedList() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
