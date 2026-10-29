// Cài đặt Queue sử dụng List

#include <iostream>
#include <vector>

class QueueList {
private:
    std::vector<int> data; // Mảng động (List) lưu trữ các phần tử Queue

public:
    // 1. isEmpty(): Trả về true nếu Queue rỗng
    // Độ phức tạp: O(1)
    bool isEmpty() { 
        return data.empty(); 
    }

    // 2. enqueue(int item): Thêm phần tử vào cuối hàng đợi
    // Độ phức tạp: O(1) Amortized
    void enqueue(int item) { 
        data.push_back(item); 
    }

    // 3. dequeue(): Xóa phần tử ở đầu hàng đợi và trả về giá trị
    // Độ phức tạp: O(N) (do phải dịch chuyển N-1 phần tử về trước)
    int dequeue() {
        if (isEmpty()) return -1;
        int firstItem = data.front();
        data.erase(data.begin()); // Xóa phần tử ở vị trí 0
        return firstItem;
    }

    // 4. size(): Trả về số phần tử hiện tại trong Queue
    // Độ phức tạp: O(1)
    int size() { 
        return data.size(); 
    }

    // 5. front(): Trả về phần tử ở đầu hàng đợi
    // Độ phức tạp: O(1)
    int front() {
        if (isEmpty()) return -1;
        return data.front();
    }
};
