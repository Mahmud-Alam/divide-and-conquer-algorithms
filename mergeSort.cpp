#include<bits/stdc++.h>
using namespace std;

void mergeArray(int low, int mid, int high, int *arr){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int left[n1],right[n2];

    for(int i=0;i<n1;i++)
        left[i] = arr[low+i];
    for(int i=0;i<n2;i++)
        right[i] = arr[mid+1+i];
    int i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
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
    int arr[] = {12,9,5,16,1,3,7,15,14,12,11,13,15,17,19,6,4,2,8,18,10,20,1,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(0,n-1,arr);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
