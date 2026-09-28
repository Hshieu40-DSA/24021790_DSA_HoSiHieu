#include <iostream>
using namespace std;
void sortTangDan(int n, int a[]){
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }    
}

int main(){
    int n;
    cin >> n;
    int a[10000];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sortTangDan(n,a);
    for (int j=0;j<n;j++){
        cout << a[j] << " ";
    }
    cout << endl;
    return 0;
}
Phân tích độ phức tạp:
- Thời gian (Time): O(N^2)
- Bộ nhớ (Memory): O(MAX)
