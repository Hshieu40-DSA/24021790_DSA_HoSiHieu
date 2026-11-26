#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class SymbolTableArray {
private:
    string keys[MAX];
    int values[MAX];
    int n = 0; // số phần tử hiện có

public:
    int size() const { return n; }
    bool isEmpty() const { return n == 0; }

    bool contains(string key) const {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) return true;
        }
        return false;
    }

    void put(string key, int value) {
        // 1. Nếu key đã tồn tại thì cập nhật giá trị
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }
        
        // 2. Kiểm tra đầy mảng trước khi thêm mới
        if (n >= MAX) {
            cout << "Bang da day, khong the them!\n";
            return;
        }

        // 3. Thêm vào cuối mảng
        keys[n] = key;
        values[n] = value;
        n++;
    }

    int get(string key) const {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) return values[i];
        }
        return -1; 
    }

    void remove(string key) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                keys[i] = keys[n - 1]; // Lấy phần tử cuối lấp vào chỗ trống
                values[i] = values[n - 1];
                n--;
                return;
            }
        }
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            cout << keys[i] << ": " << values[i] << "\n";
        }
    }
};
