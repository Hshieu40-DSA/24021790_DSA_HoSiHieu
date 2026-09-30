#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<double> a(n); 
    double tong=0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        tong += a[i];
    }
    double average=tong/n;
    for (int j=0;j<n;j++) {
        if (a[j] >= average) {
            cout << a[j] << " ";
        }
    }
    return 0;
}

// Phân tích độ phức tạp:
// - Thời gian: O(n)
// - Bộ nhớ: O(n)

