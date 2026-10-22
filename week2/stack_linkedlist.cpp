// Cài đặt Stack sử dụng Linked List

#include <iostream>

class StackLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head = nullptr; // Quản lý phần tử đỉnh (top)
    int count = 0;        // Lưu kích thước stack

public:
    // 1. isEmpty(): Trả về true nếu stack rỗng
    // Độ phức tạp: O(1)
    bool isEmpty() {
        return head == nullptr;
    }

    // 2. push(int item): Chèn một phần tử vào stack
    // Độ phức tạp: O(1)
    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        count++;
    }

    // 3. pop(): Xóa phần tử ở đỉnh stack và trả về phần tử đó
    // Độ phức tạp: O(1)
    int pop() {
        if (isEmpty()) {
            return -1; // Trả về -1 nếu stack rỗng
        }
        Node* temp = head;
        int poppedValue = temp->data;
        head = head->next;
        delete temp;
        count--;
        return poppedValue;
    }

    // 4. size(): Trả về kích thước của stack
    // Độ phức tạp: O(1)
    int size() {
        return count;
    }

    // 5. top(): Trả về giá trị phần tử ở đỉnh stack
    // Độ phức tạp: O(1)
    int top() {
        if (isEmpty()) {
            return -1; // Trả về -1 nếu stack rỗng
        }
        return head->data;
    }
};
