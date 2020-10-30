#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int l, int r, int key, int *arr){

}

int main(){
    int key, n, arr[] = {1,2,3,4,5,6,7,8,9,11,15,21,36,65,98};

    n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Input Search key: ";cin>>key;

    int value = ternarySearch(0, n-1, key, arr);
}
