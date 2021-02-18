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
void swap(int *a,int k){
    int q;
    q=a[k];
    a[k]=a[k-1];
    a[k-1]=q;
}
  
  void Bubble(int *M){
    int i,j;
    for(i=0;i<size-1;i++)
      for(j=size-1;j>i;j--){
        if(M[j-1]>M[j]){
          swap(M,j);
        }
      }
  }
  
  int main(){
    int A[size],B[size];
    makeArr(A);
    printArr(A);
    copyArr(A,B);
    printf("\n");
    printArr(B);
    printf("\n");
    Bubble(B);
    printArr(B);
    copyArr(A,B);
  }
