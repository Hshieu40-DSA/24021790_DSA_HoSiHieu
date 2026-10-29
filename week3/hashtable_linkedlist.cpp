#include <iostream>
#include <string>
using namespace std;

// Cấu trúc Node cho Danh sách liên kết
struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, string v) : key(k), value(v), next(nullptr) {}
};

class HashTableCustom {
private:
    int capacity;
    Node** table; // Mảng các con trỏ trỏ đến Node đầu tiên của mỗi Bucket

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTableCustom(int cap = 7) {
        capacity = cap;
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }

    // Hủy bộ nhớ động
    ~HashTableCustom() {
        for (int i = 0; i < capacity; i++) {
            Node* head = table[i];
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // 1. Thêm / Cập nhật
    void insert(int key, string value) {
        int index = hashFunction(key);
        Node* head = table[index];

        // Kiểm tra xem key đã tồn tại chưa để cập nhật
        while (head != nullptr) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        // Chèn Node mới vào đầu danh sách (O(1))
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // 2. Tìm kiếm
    string search(int key) {
        int index = hashFunction(key);
        Node* head = table[index];
        while (head != nullptr) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return "Khong tim thay";
    }

    // 3. Xóa
    void remove(int key) {
        int index = hashFunction(key);
        Node* head = table[index];
        Node* prev = nullptr;

        while (head != nullptr) {
            if (head->key == key) {
                if (prev == nullptr) {
                    table[index] = head->next; // Xóa Node đầu
                } else {
                    prev->next = head->next; // Xóa Node giữa hoặc cuối
                }
                delete head;
                cout << "Da xoa key: " << key << endl;
                return;
            }
            prev = head;
            head = head->next;
        }
        cout << "Key khong ton tai!\n";
    }

    // Hiển thị Bảng băm
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "[" << temp->key << ": " << temp->value << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};
