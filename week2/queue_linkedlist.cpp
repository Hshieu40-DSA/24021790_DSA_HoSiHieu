#include <iostream>

struct LinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    void insertTail(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int deleteHead() {
        if (isEmpty()) return -1;
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        size--;
        return val;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getHeadData() {
        if (isEmpty()) return -1;
        return head->data;
    }

    int getSize() {
        return size;
    }
};

// Cài đặt Queue bằng cách tái sử dụng LinkedList
struct Queue {
    LinkedList list;

    // 1. isEmpty(): Trả về true nếu Queue rỗng và false nếu ngược lại - O(1)
    bool isEmpty() {
        return list.isEmpty();
    }

    // 2. enqueue(int item): Thêm phần tử vào cuối hàng đợi (Rear) - O(1)
    void enqueue(int data) {
        list.insertTail(data);
    }

    // 3. dequeue(): Xóa và trả về phần tử ở đầu hàng đợi (Front) - O(1)
    int dequeue() {
        return list.deleteHead();
    }

    // 4. size(): Trả về số lượng phần tử trong hàng đợi - O(1)
    int size() {
        return list.getSize();
    }

    // 5. front(): Trả về giá trị phần tử ở đầu hàng đợi mà không xóa - O(1)
    int front() {
        return list.getHeadData();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.front() << std::endl; // 10
    std::cout << "Dequeued: " << q.dequeue() << std::endl;   // 10
    std::cout << "Front element: " << q.front() << std::endl; // 20
    std::cout << "Queue size: " << q.size() << std::endl;     // 2

    return 0;
}
