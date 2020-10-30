#include<bits/stdc++.h>
using namespace std;

int Partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=0;j<high;j++){

    }
}

void quickSort(int *arr, int low, int high){
    if(low<high){
        int q = Partition(arr,low,high);
        quickSort(arr,low,q-1);
        quickSort(arr,q+1,high);
    }
}

int main(){
    int arr[] = { 9, 4, 7, 10, 8, 5, 1, 3, 2, 6};

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
