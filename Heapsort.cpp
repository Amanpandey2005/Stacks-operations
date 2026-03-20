#include<iostream>
using namespace std;

void maxheapify(int arr[], int n , int index){
    int left = 2*index + 1;
    int right = 2*index + 2;
    int largestindex = index;

    if(left < n && arr[left] > arr[largestindex]){
        largestindex = left;
    }
    if(right < n && arr[right] > arr[largestindex]){
        largestindex = right;
    }
    if(largestindex != index){
        swap(arr[index],arr[largestindex]);
        maxheapify(arr,n,largestindex);
    }
}

void Buildmaxheap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        maxheapify(arr,n,i);
    }
}

void sortarray(int arr[], int n){
    Buildmaxheap(arr,n);
    for(int i = n-1; i > 0; i--){
        swap(arr[0],arr[i]);
        maxheapify(arr,i,0);
    }
}

void printheap(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    Buildmaxheap(arr,10);
    sortarray(arr,10);
    printheap(arr,10);
}