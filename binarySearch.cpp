#include<bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, int key, int *arr){
    if(high>=low){
        int mid = (low+high)/2;

        if(arr[mid]==key) return mid;

        if(arr[mid]>key) return binarySearch(low,mid-1,key,arr);

        else if(arr[mid]<key) return binarySearch(mid+1,high,key,arr);
    }
    return -1;
}

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};

    int n = sizeof(arr)/sizeof(arr[0]);

    int key; cout<<"Input a search key: ";cin>>key;

    int index = binarySearch(0,n-1,key,arr);

    if(index!=-1){
        cout<<endl<<key<<" is found in index: "<<index<<endl;
    }
    else{
        cout<<endl<<"Key is not found!"<<endl;
    }

}
