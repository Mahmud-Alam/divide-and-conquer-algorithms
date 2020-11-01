#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {9,5,1,3,7,6,4,2,8,10,1,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(0,n-1,arr);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
