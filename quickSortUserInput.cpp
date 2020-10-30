#include<bits/stdc++.h>
using namespace std;

void quickSort(int *arr, int low, int high){
    if(low<high){
        int q = Partition(arr, low, high);
        quickSort(arr,low,q-1);
        quickSort(arr,q+1,high);
    }
}

int main(){
    int arr[100],value,i=0;
    cout<<"Input values(type 1024 to stop): ";
    while(1){
        cin>>value;
        if(value==1024) break;
        else{
            arr[i] = value;
            i++;
        }
    }
    quickSort(arr,0,i-1);
    cout<<endl;
    for(int j=0;j<i;j++){
        cout<<arr[j]<<"\t";
    }
    cout<<endl;
}
