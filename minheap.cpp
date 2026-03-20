#include<iostream>
using namespace std;

void maxheapify(int arr[], int n , int index){
    int left = 2*index + 1;
    int right = 2*index + 2;
    int largest = index;

    if(left < n && arr[left] < arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] < arr[largest]){
        largest = right;
    }
    if(largest != index){
        swap(arr[index],arr[largest]);
        maxheapify(arr,n,largest);
    }
}

void Buildmaxheap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        maxheapify(arr,n,i);
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
    printheap(arr,10);
}