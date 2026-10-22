// Cài đặt Stack sử dụng List

#include <iostream>
#include <vector>

class StackList {
private:
    std::vector<int> data; // Sử dụng mảng động (std::vector) làm List lưu trữ các phần tử

public:
    // 1. isEmpty(): Trả về true nếu stack rỗng và false nếu ngược lại
    // Độ phức tạp thời gian: O(1)
    bool isEmpty() { 
        return data.empty(); 
    }

    // 2. push(int item): Chèn một phần tử vào đỉnh stack (cuối mảng)
    // Độ phức tạp thời gian: O(1) trung bình (Amortized O(1))
    void push(int item) { 
        data.push_back(item); 
    }

    // 3. pop(): Xóa phần tử ở đỉnh stack (cuối mảng) và trả về phần tử đó
    // Độ phức tạp thời gian: O(1)
    int pop() {
        if (isEmpty()) {
            return -1; // Trả về -1 nếu stack rỗng
        }
        int lastItem = data.back();
        data.pop_back();
        return lastItem;
    }

    // 4. size(): Trả về số lượng phần tử hiện có trong stack
    // Độ phức tạp thời gian: O(1)
    int size() { 
        return data.size(); 
    }

    // 5. top(): Trả về giá trị phần tử ở đỉnh stack (cuối mảng)
    // Độ phức tạp thời gian: O(1)
    int top() {
        if (isEmpty()) {
            return -1; // Trả về -1 nếu stack rỗng
        }
        return data.back();
    }
};
