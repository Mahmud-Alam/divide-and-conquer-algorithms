#include<bits/stdc++.h>
using namespace std;

void mergeSort(int low, int high, int *arr){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(low,mid,arr);
        mergeSort(mid+1,high,arr);

        mergeArray(low,mid,high,arr);
    }
}

int main(){
    int arr = {11,10,9,8,7,6,5,4,3,2,1,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(0,n-1,arr);

    for(int i=0;i<n;i++){
        cout<<arr[0]<<"  ";
    }
    cout<<endl;
}
