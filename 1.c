#include <stdio.h>
#include <time.h>
  const int size = 8;

  void makeArr(int *M){
    srand(time(NULL));
    int i;
    for(i=0;i<size;i++)
    M[i] = rand() % 51;
  }

  void printArr(int *M){
    int i;
    for(i=0;i<size;i++)
    printf("%d\n",M[i]);
  }

  int main(){
    int A[size],B[size];
    makeArr(A);
    printArr(A);
  }
