#include<bits/stdc++.h>
using namespace std;

#define SIZE 100
int data[SIZE];

void RandomDataWrite(char *FileName){
    time_t t;
    FILE *fp = fopen(FileName,"w");

    //srand(time(NULL));
    srand((unsigned)time(&t));

    for(int i=0;i<SIZE;i++){
        fprintf(fp,"%d\n",rand()%INT_MAX+1);
    }
    fclose(fp);
}

void ReadFromFIle(char *FileName){
    FILE *fp = fopen(FileName,"r");
    for(int i=0;i<SIZE;i++){
        fscanf(fp,"%d",&data[i]);
    }
    fclose(fp);
}

void SortedDataWrite(char *FileName){
    FILE *fp = fopen(FileName,"w");
    for(int i=0;i<SIZE;i++){
        fprintf(fp,"%d\n",data[i]);
    }
    fclose(fp);
}

int Partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quickSort(int *arr, int low, int high){
    if(low<high){
        int q = Partition(arr,low,high);
        quickSort(arr,low,q-1);
        quickSort(arr,q+1,high);
    }
}

int main(){
    int sortedData[SIZE];
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFIle("RandomIntegers.txt");

    for(int i=0;i<SIZE;i++){
        cout<<data[i]<<"\t";
    }

    quickSort(data,0,SIZE-1);

    SortedDataWrite("SortedIntegers.txt");

    cout<<endl<<endl<<endl<<"Array sorted by Quick sort: "<<endl<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<data[i]<<"\t";
    }
    cout<<endl;
}

