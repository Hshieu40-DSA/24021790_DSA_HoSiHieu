#include <iostream>
#include <cmath>
using namespace std;
int timUCLN(int x, int y){
    while (y != 0) {
        int du=x%y;
        x=y;
        y=du;
    }
    return abs(x);
}
void rutGonPhanSo(int &a, int &b){
    if (b==0){
        return;
    }
    int ucln=timUCLN(a, b); 
    
    a/=ucln;
    b/=ucln;
    if (b<0) {
        a=-a;
        b=-b;
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    if (b==0){
        cout << "Mau so khong hop le" << endl;
        return 1;
    }
    cout << "Phan so ban dau: " << a << "/" << b << endl;
    rutGonPhanSo(a, b);
    cout << "Phan so sau khi rut gon: " << a << "/" << b << endl;
    return 0;
}
// Phân tích độ phức tạp:
// - Thời gian: O(log(min(|a|,|b|)))
// - Bộ nhớ : O(1)

