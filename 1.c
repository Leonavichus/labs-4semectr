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
    printf("%d\t",M[i]);
  }

  void copyArr(int *M, int *K){
    int i;
    for(i=0;i<size;i++)
      K[i]=M[i];
  }
  
  void Bubble(int (*swap)(void),int *M){
    int i,j,q;
    for(i=0;i<size-1;i++)
      for(j=size-1;j>i;j--){
        if(M[j-1]>M[j]){
          swap();
        }
      }
  }
  
  void swap(int *M,int i,int j,int q){
          q=M[j];
          M[j]=M[j-1];
          M[j-1]=q;
  }

  int main(){
    int i,j,q;
    int A[size],B[size];
    makeArr(A);
    printArr(A);
    copyArr(A,B);
    printf("\n");
    printArr(B);
    printf("\n");
    Bubble(swap,B);
    printArr(B);
    copyArr(A,B);
  }
