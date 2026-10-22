// Cài đặt Queue sử dụng Linked List
#include <iostream>

class QueueLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* frontNode = nullptr; // Con trỏ quản lý phần tử ở đầu Queue
    Node* rearNode = nullptr;  // Con trỏ quản lý phần tử ở cuối Queue
    int count = 0;             // Lưu số lượng phần tử hiện tại

public:
    // 1. isEmpty(): Trả về true nếu Queue rỗng và false nếu ngược lại
    // Độ phức tạp: O(1)
    bool isEmpty() { 
        return frontNode == nullptr; 
    }

    // 2. enqueue(int item): Thêm phần tử vào cuối hàng đợi (Rear)
    // Độ phức tạp: O(1)
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontNode = rearNode = newNode; // Nếu queue rỗng, cả front và rear đều trỏ vào nút mới
        } else {
            rearNode->next = newNode;       // Nối nút mới vào sau nút rear cũ
            rearNode = newNode;             // Cập nhật rear trỏ sang nút mới
        }
        count++;
    }

    // 3. dequeue(): Xóa và trả về phần tử ở đầu hàng đợi (Front)
    // Độ phức tạp: O(1)
    int dequeue() {
        if (isEmpty()) {
            return -1; // Trả về -1 nếu Queue rỗng
        }
        Node* temp = frontNode;
        int dequeuedValue = temp->data;
        frontNode = frontNode->next;        // Chuyển front sang nút kế tiếp
        
        if (frontNode == nullptr) {
            rearNode = nullptr;             // Nếu sau khi xóa mà Queue rỗng thì reset rear về nullptr
        }
        
        delete temp;                        // Giải phóng bộ nhớ của nút vừa xóa
        count--;
        return dequeuedValue;
    }

    // 4. size(): Trả về số lượng phần tử trong hàng đợi
    // Độ phức tạp: O(1)
    int size() { 
        return count; 
    }

    // 5. front(): Trả về giá trị phần tử ở đầu hàng đợi mà không xóa
    // Độ phức tạp: O(1)
    int front() {
        if (isEmpty()) {
            return -1; // Trả về -1 nếu Queue rỗng
        }
        return frontNode->data;
    }
};
