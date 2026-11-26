#include <iostream>
#include <string>

using namespace std;

class SymbolTableLinkedList {
private:
    struct Node {
        string key;
        int value;
        Node* next;

        Node(string k, int v, Node* n = nullptr) : key(k), value(v), next(n) {}
    };

    Node* head = nullptr;
    int n = 0; // số phần tử hiện có

public:
    // Giải phóng bộ nhớ khi kết thúc
    ~SymbolTableLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int size() const { return n; }
    bool isEmpty() const { return n == 0; }

    bool contains(string key) const {
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            if (curr->key == key) return true;
        }
        return false;
    }

    void put(string key, int value) {
        // 1. Nếu key đã tồn tại -> cập nhật value
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
        }
        // 2. Nếu chưa tồn tại -> chèn vào đầu danh sách
        head = new Node(key, value, head);
        n++;
    }

    int get(string key) const {
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            if (curr->key == key) return curr->value;
        }
        return -1; 
    }

    void remove(string key) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    head = curr->next; // Xóa nút đầu
                } else {
                    prev->next = curr->next; // Bỏ qua nút curr
                }
                delete curr;
                n--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void print() const {
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            cout << curr->key << ": " << curr->value << "\n";
        }
    }
};
