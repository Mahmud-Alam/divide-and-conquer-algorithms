#include<bits/stdc++.h>
using namespace std;

void mergeArray(int low, int mid, int high, int *arr){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int left[n1],right[n2];

}

void mergeSort(int low,int high, int *arr){
    if(low<high){
        int mid = (high+low)/2;

        mergeSort(low,mid,arr);
        mergeSort(mid+1,high,arr);

        mergeArray(low,mid,high,arr);
    }
}

int main(){
    int arr[] = {9,5,1,3,7,6,4,2,8,10,1,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(0,n-1,arr);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
