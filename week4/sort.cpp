#include <iostream>
#include <algorithm>
using namespace std;

//1. Sắp xếp lựa chọn(Selection Sort): O(N^2)
void selectionSort(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int min_index=i;
        // Tim vi tri min
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        if (min_index != i){
            swap(arr[min_index], arr[i]); 
        }
    }
}

// 2.Sắp xếp nổi bọt(Bubble Sort): O(N^2)
void bubbleSort(int arr[], int n){
    // Giữ nguyên form khai báo biến của bạn
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// 3.Sắp xếp chèn(Insertion Sort): O(N^2)
void insertionSort(int arr[], int n){
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

// 4.Sắp xếp hợp(Merge Sort): O(NlogN)
void merge(int arr[], int l, int mid, int r){ 
    int *b, *c; 
    b=new int[mid-l+1]; 
    c=new int[r-mid];
    for (int i=l;i<=r;i++){
        if (i<=mid) b[i-l]=arr[i]; 
        else c[i-mid-1]=arr[i]; 
    }
    int i=0, j=0, k=l; 
    while (i<mid-l+1 && j< r-mid){
        if (b[i]<c[j]) arr[k]=b[i++]; 
        else arr[k]=c[j++]; 
        k++;
    }
    while(i<mid-l+1){
        arr[k++]=b[i++];
    }
    while (j<r-mid){ 
        arr[k++]=c[j++];
    }
    delete[] b; delete[] c; // Giải phóng bộ nhớ động để tránh rò rỉ (Memory Leak)
}

void Sort(int arr[], int l, int r){ 
    if (r<=l) return;
    int mid=(l+r)/2;
    Sort(arr, l, mid); 
    Sort(arr, mid+1, r); 
    merge(arr, l, mid, r); 
}


// 5.Sắp xếp nhanh(Quick Sort): O(NlogN)
int partition(int arr[], int low, int high){ // Đưa hàm partition lên trước, thêm kiểu dữ liệu int cho hàm và biến
    int pivot=arr[high];
    int i=low-1;
    for (int j=low;j<=high-1;j++){ 
        if (arr[j]<pivot){
            i=i+1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){ 
    if (low<high){
        int pivotIndex=partition(arr, low, high); 
        // ĐƯA 2 LỆNH DƯỚI VÀO TRONG BLOCK IF: Để tránh việc đệ quy vô hạn khi low >= high
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}
