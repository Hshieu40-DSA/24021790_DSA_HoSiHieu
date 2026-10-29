#include <iostream>
#include <vector>

struct List {
    std::vector<int> data;

    void insertTail(int val) {
        data.push_back(val);
    }

    int deleteTail() {
        if (isEmpty()) return -1;
        int val = data.back();
        data.pop_back();
        return val;
    }

    bool isEmpty() {
        return data.empty();
    }

    int getTailData() {
        if (isEmpty()) return -1;
        return data.back();
    }

    int getSize() {
        return data.size();
    }
};

// Cài đặt Stack bằng cách tái sử dụng List
struct Stack {
    List list;

    // 1. isEmpty(): Trả về true nếu stack rỗng và false nếu ngược lại - O(1)
    bool isEmpty() {
        return list.isEmpty();
    }

    // 2. push(int item): Chèn một phần tử vào đỉnh stack (cuối list) - O(1) trung bình
    void push(int data) {
        list.insertTail(data);
    }

    // 3. pop(): Xóa phần tử ở đỉnh stack (cuối list) và trả về phần tử đó - O(1)
    int pop() {
        return list.deleteTail();
    }

    // 4. size(): Trả về số lượng phần tử hiện có trong stack - O(1)
    int size() {
        return list.getSize();
    }

    // 5. top(): Trả về giá trị phần tử ở đỉnh stack (cuối list) - O(1)
    int top() {
        return list.getTailData();
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
    std::cout << "Stack size: " << s.size() << std::endl;   // 2
     return 0;
}
