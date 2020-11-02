#include<bits/stdc++.h>
using namespace std;
void mergeArray(int low, int mid, int high, int *arr){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int left[n1], right[n2];

    for(int i=0;i<n1;i++){
        left[i] = arr[low+i];
    }
    for(int j=0;j<n2;j++){
        right[j] = arr[mid+1+j];
    }

    int i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
        }
        if(left[i]>right[j]){
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int low, int high, int *arr){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(low,mid,arr);
        mergeSort(mid+1,high,arr);

        mergeArray(low,mid,high,arr);
    }
}

int main(){
    int arr[] = {11,10,9,8,7,6,5,4,3,2,1,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(0,n-1,arr);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
