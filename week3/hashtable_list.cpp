#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
class HashTable {
private:
    int SIZE;
    // Mảng các LinkedList: Mỗi ô của vector chứa một list các số nguyên
    vector<list<int>> table; 

    // Hàm băm đơn giản bằng phép chia lấy dư
    int hashFunction(int key) {
        return abs(key) % SIZE; 
    }
public:
    // Khởi tạo bảng băm với kích thước cho trước
    HashTable(int size) {
        this->SIZE = size;
        table.resize(size);
    }
    // 1. Thêm một phần tử vào bảng băm
    void insertKey(int key) {
        int index = hashFunction(key);
        // Kiểm tra xem key đã tồn tại trong danh sách chưa để tránh trùng lặp
        for (int x : table[index]) {
            if (x == key) return; 
        }
        table[index].push_back(key); // Chèn vào cuối LinkedList tại ô 'index'
    }
    // 2. Tìm kiếm một phần tử
    bool searchKey(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) return true; // Tìm thấy
        }
        return false; // Không tìm thấy
    }
    // 3. Xóa một phần tử
    void deleteKey(int key) {
        int index = hashFunction(key);
        // Hàm remove của std::list sẽ tự động tìm và xóa tất cả phần tử bằng 'key'
        table[index].remove(key); 
    }
    // Hàm in bảng băm ra màn hình để kiểm tra
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";
            for (int x : table[i]) {
                cout << x << " -> ";
            }
            cout << "NULL\n";
        }
    }
};
int main() {
    HashTable ht(7); // Tạo bảng băm có 7 phần tử

    ht.insertKey(15); // 15 % 7 = 1 (vào bucket 1)
    ht.insertKey(11); // 11 % 7 = 4 (vào bucket 4)
    ht.insertKey(22); // 22 % 7 = 1 (va chạm, nối tiếp vào sau số 15 ở bucket 1)
    ht.insertKey(38); // 38 % 7 = 3 (vào bucket 3)
  
    cout << "--- Bang bam ban dau ---\n";
    ht.display();

    cout << "\nTim kiem so 22: " << (ht.searchKey(22) ? "Thay" : "Khong thay") << endl;
    cout << "\nXoa so 15...\n";
    ht.deleteKey(15);

    cout << "--- Bang bam sau khi xoa ---\n";
    ht.display();
    return 0;
}
