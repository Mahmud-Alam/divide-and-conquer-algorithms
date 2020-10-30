#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int l, int r, int key, int *arr){
    if(r>=l){
        int mid1 = l+(r-1)/3;
        int mid2 = r-(r-1)/3;

        if(arr[mid1]==key) return mid1;
        if(arr[mid2]==key) return mid2;

        if(key<arr[mid1])
            return ternarySearch(l,mid-1,key,arr);
        else if(key>arr[mid2])
            return ternarySearch(mid2+1,r,key,arr);
        else return ternarySearch(mid1+1,mid2-1,key,arr)
    }
    return -1;
}

int main(){
    int key, n, arr[] = {1,2,3,4,5,6,7,8,9,11,15,21,36,65,98};

    n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Input Search key: ";cin>>key;

    int index = ternarySearch(0, n-1, key, arr);

    if(index!=-1){
        cout<<endl<<key<<" is found in Index: "<<index<<endl;
    }
    else{
        cout<<endl<<"Key is not found!"<<endl;
    }
}
