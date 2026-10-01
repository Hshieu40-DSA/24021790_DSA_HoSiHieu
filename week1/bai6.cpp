#include <iostream>
using namespace std;
void Delete(int &n, int k, int a[]){
    if (k<0 || k>=n){
        cout << "Vi tri xoa khong hop le";
        return;
    }
    for (int i=k;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
}
void Insert(int &n, int m, int y, int a[]){
    if (m<0 || m>n){
        cout << "Vi tri chen khong hop le";
        return;
    }
    for (int j=n;j>m;j--){
        a[j]=a[j-1];
    }
    a[m]=y;
    n++;
}
void printArray(int n, int a[]){
    for (int i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout << endl;
}
int main(){
    int n, a[10000];
    cout << "Nhap so nguyen n:" << endl;
    cin >> n;
    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    // Xoa phan tu o vi tri k
    int k;
    cout << "Nhap vi tri can xoa: " << endl;
    cin >> k;
    Delete(n,k,a);
    cout << "Mang sau khi xoa: " << endl;
    printArray(n,a);
    // Chen phan tu y vao vi tri m
    int m,y;
    cout << "Nhap vi tri m can chen:" << endl;;
    cin >> m;
    cout << "Nhap gia tri y can chen:" << endl;
    cin >> y;
    Insert(n,m,y,a);

    cout << "Mang sau khi chen: " << endl;
    printArray(n,a);
    return 0;
}
// Phân tích độ phức tap:
// - Thời gian: O(n)
// - Bộ nhớ: O(1)
