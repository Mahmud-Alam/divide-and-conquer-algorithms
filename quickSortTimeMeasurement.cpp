#include<bits/stdc++.h>
using namespace std;

#define SIZE 10
int data[SIZE];

void RandomDataWrite(char *FileName){
    FILE *fp = fopen(FileName,"w");
    srand(time(NULL));

    for(int i=0;i<SIZE;i++){
        fprintf(fp,"%d\n",rand()%INT_MAX+1);
    }
    fclose(fp);
}

int main(){
    RandomDataWrite("RandomIntegers.txt");
}
