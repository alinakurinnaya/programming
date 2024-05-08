#include <iostream>
#include <atomic>
#include <vector>
#include <thread>

using namespace std;

template <typename T>
class LockFreeStack {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data) : data(data), next(nullptr) {}
    };

    atomic<Node*> head;

public:
    LockFreeStack() : head(nullptr) {}

    void push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = head.load();
        while (!head.compare_exchange_weak(newNode->next, newNode));
    }

    bool pop(T& data) {
        Node* oldHead = head.load();
        while (oldHead && !head.compare_exchange_weak(oldHead, oldHead->next));

        if (oldHead) {
            data = oldHead->data;
            delete oldHead;
            return true;
        }

        return false;
    }
};

int main() {
    LockFreeStack<int> stack;

    vector<thread> threads;

    for (int i = 0; i < 10; i++) {
        threads.emplace_back([&stack]() {
            for (int j = 0; j < 10; j++) {
                stack.push(j);
            }
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    int data;
    while (stack.pop(data)) {
        cout << data << " ";
    }
    cout << endl;

    return 0;
}
