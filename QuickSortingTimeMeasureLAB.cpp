#include<bits/stdc++.h>
using namespace std;

#define SIZE 20000
int data[SIZE];

void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}

int TestFunction(){
    int c = 0;
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 10000; j++){
            if(i > j){
                c++;
            }
        }
    }
    return c;
}

//_________________________________ MY CODE _________________________________//

int Partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p-1;

    for (int j=p;j<=r-1;j++){
        if (arr[j] < x){
            i++;
            int temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
        }
    }
    int temp2 = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp2;

    return i+1;
}

void quickSort(int arr[], int p, int r){
    if (p < r){
        int q = Partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int ReversePartition(int arr[], int p, int r){
    int x = arr[r];
    int i = p-1;

    for (int j=p;j<=r-1;j++){
        if (arr[j] > x){
            i++;
            int temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
        }
    }
    int temp2 = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp2;

    return i+1;
}

void reverseQuickSort(int arr[], int p, int r){
    if (p < r){
        int q = ReversePartition(arr, p, r);
        reverseQuickSort(arr, p, q-1);
        reverseQuickSort(arr, q+1, r);
    }
}

int ternarySearch(int l, int r, int key, int a[])
{
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (a[mid1] == key) {
            return mid1;
        }
        if (a[mid2] == key) {
            return mid2;
        }
        if (key < a[mid1]) {
            return ternarySearch(l, mid1 - 1, key, a);
        }
        else if (key > a[mid2]) {
            return ternarySearch(mid2 + 1, r, key, a);
        }
        else {
            return ternarySearch(mid1 + 1, mid2 - 1, key, a);
        }
    }
    return -1;
}
int main(){
    clock_t start, end;;
    int i, l, r, p, key;
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");

    //Random array Ascending order sorting by Quick sort______________________________________

    start = clock();
    quickSort(data, 0, SIZE-1);
    end = clock();


    cout <<"Quick Sorted array:\n";
//    for (int i=0;i<SIZE;i++)
//        cout << data[i] <<"  ";
//    cout << endl;

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\nQuick Sort Function took %f seconds to execute \n", time_taken);


    //Sorted array again sort by Quick sort________________________________________________

    cout<<endl;

    start = clock();
    quickSort(data, 0, SIZE-1);
    end = clock();

    cout <<"Again Quick Sorted array: \n";

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\nAgain Quick Sort Function took %f seconds to execute \n", time_taken);




    //Now Descending order Sorting by Quick sort_______________________________________________

    cout<<endl;

    start = clock();
    reverseQuickSort(data, 0, SIZE-1);
    end = clock();


    cout <<"Reverse Quick Sorted array: \n";
//    for (int i=0;i<SIZE;i++)
//        cout << data[i] <<"  ";
//    cout << endl;

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\nReverse Quick Sort Function took %f seconds to execute \n", time_taken);



    //Ternary Seach code__________________________________________________________________

    cout<<endl;
    cout<<"Input a key for ternary search: ";cin>>key;
    int value = key;
    quickSort(data, 0, SIZE-1);

    start = clock();
    p = ternarySearch(0, SIZE-1, key, data);
    end = clock();

    if(p!=-1){
        cout<<endl<<"Key is found in: Index["<<p<<"]"<<endl;
    }
    else{
        cout<<endl<<"Key is not found!"<<endl;
    }

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\nTernary Seach Function took %f seconds to execute \n", time_taken);
}
