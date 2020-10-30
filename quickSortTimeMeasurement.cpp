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

int main(){
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFIle("RandomIntegers.txt");
    for(int i=0;i<SIZE;i++){
        cout<<data[i]<<"\t";
    }
    cout<<endl;
}
