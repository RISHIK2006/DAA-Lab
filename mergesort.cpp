#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int s, int mid, int e,int n) {
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int A[n1], B[n2];
    for(int i = 0; i < n1; i++) {
        A[i] = arr[s + i];
    }
    for(int i = 0; i < n2; i++) {
        B[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = s;
    while(i < n1 && j < n2) {
        if(A[i] < B[j]) {
            arr[k] = A[i];
            i++;
        } else {
            arr[k] = B[j];
            j++;
        }
        k++;
    } 
    while(i < n1) {
        arr[k] = A[i];
        k++;
        i++;
    }
    while(j < n2) {
        arr[k] = B[j];
        k++;
        j++;
    }
}

void mergesort(int arr[], int l, int r,int n) {
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergesort(arr, l, mid,n);
    mergesort(arr, mid + 1, r,n);
    merge(arr, l, mid, r,n);
    display(arr,n);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Passes of merge sort:" << endl;
    mergesort(arr, 0, n - 1,n);
    cout << "\nArray after applying merge sort:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

