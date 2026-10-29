#include <iostream>
#include <vector>

struct List {
    std::vector<int> data;

    void insertTail(int val) {
        data.push_back(val);
    }

    int deleteHead() {
        if (isEmpty()) return -1;
        int val = data.front();
        data.erase(data.begin());
        return val;
    }

    bool isEmpty() {
        return data.empty();
    }

    int getHeadData() {
        if (isEmpty()) return -1;
        return data.front();
    }

    int getSize() {
        return data.size();
    }
};

// Cài đặt Queue bằng cách tái sử dụng List
struct Queue {
    List list;

    // 1. isEmpty(): Trả về true nếu Queue rỗng và false nếu ngược lại - O(1)
    bool isEmpty() {
        return list.isEmpty();
    }

    // 2. enqueue(int item): Thêm phần tử vào cuối hàng đợi - O(1) trung bình
    void enqueue(int data) {
        list.insertTail(data);
    }

    // 3. dequeue(): Xóa phần tử ở đầu hàng đợi và trả về giá trị - O(N)
    int dequeue() {
        return list.deleteHead();
    }

    // 4. size(): Trả về số lượng phần tử hiện có trong Queue - O(1)
    int size() {
        return list.getSize();
    }

    // 5. front(): Trả về giá trị phần tử ở đầu hàng đợi - O(1)
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
