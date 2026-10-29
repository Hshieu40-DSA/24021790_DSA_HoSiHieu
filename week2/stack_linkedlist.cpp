#include <iostream>

struct LinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head = nullptr;
    int size = 0;

    void insertHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int deleteHead() {
        if (isEmpty()) return -1;
        Node* temp = head;
        int val = temp->data;
        head = head->next;
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

// Cài đặt Stack bằng cách tái sử dụng LinkedList
struct Stack {
    LinkedList list;

    // 1. Kiểm tra rỗng - O(1)
    bool isEmpty() {
        return list.isEmpty();
    }

    // 2. Thêm phần tử vào đỉnh stack - O(1)
    void push(int data) {
        list.insertHead(data);
    }

    // 3. Lấy và xóa phần tử ở đỉnh stack - O(1)
    int pop() {
        return list.deleteHead();
    }

    // 4. Xem phần tử ở đỉnh stack mà không xóa - O(1)
    int top() {
        return list.getHeadData();
    }

    // 5. Lấy số lượng phần tử trong stack - O(1)
    int size() {
        return list.getSize();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.top() << std::endl; // 30
    std::cout << "Popped: " << s.pop() << std::endl;       // 30
    std::cout << "Top element: " << s.top() << std::endl; // 20
    std::cout << "Stack size: " << s.size() << std::endl; // 2

    return 0;
}
