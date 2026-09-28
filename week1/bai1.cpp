#include <iostream>
using namespace std;
int main(){
    int n, a[10000];
    cin >> n;
    int sum=0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    cout << sum << endl;
    return 0;
}
Phân tích độ phức tạp:
- Thời gian(Time): O(N)
- Bộ nhớ (Memory): O(N)
