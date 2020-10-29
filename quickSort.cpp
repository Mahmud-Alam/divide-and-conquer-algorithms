#include<bits/stdc++.h>
using namespace std;



int main(){
    int arr[] = { 9, 4, 7, 10, 8, 5, 1, 3, 2, 6};

    quickSort(arr,1,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
