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

  void Bubble_New(int *M){
    int i,j = 0,m;
    do{
      m=j;
      for(i=size-1;i>m;i--){
        if(M[i-1]>M[i]){
          j=i;
          swap(M,j);
        }
      }
    } while(j-m);
  }

  void Shaker(int *M){
    int i,t,n1=0,n2=size-1,j;
    do{
      for(i=n2;i > n1;i--) {
        if(M[i-1]>M[i]){
          t=M[i-1];
          M[i-1]=M[i];
          M[i]=t;
          j=i;
        }
      }
    n1=j;
    for(i=n1;i<=n2;i++){
      if(M[i-1]>M[i]){
        t=M[i-1];
        M[i-1]=M[i];
        M[i]=t;
        j=i;
      }
    }
    n2=j-1;
    } while(n1<n2);
  }

  void InsertSort(int *M){
    int i,j,temp;
    for(i=1;i<size;i++){
      if(M[i]<M[i-1]){
        temp=M[i];
      for(j=i-1;j>=0 && M[j]>temp;j--){
        M[j+1]=M[j];
      }
      M[j+1]=temp;
      }
    }
  }

  void  SelectionSort(int *M){
    int i,j,im,temp;
    for(i=0;i<size-1;i++){
      im=i;
      for(j=i+1;j<size;j++){
        if(M[j]<M[im])
        im=j;}
        if(i!=im){
          temp=M[i];
          M[i]=M[im];
          M[im]=temp;
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
    printf("\n");
    Bubble_New(B);
    printArr(B);
    copyArr(A,B);
    printf("\n");
    Shaker(B);
    printArr(B);
    copyArr(A,B);
    printf("\n");
    InsertSort(B);
    printArr(B);
    copyArr(A,B);
    printf("\n");
    SelectionSort(B);
    printArr(B);
    copyArr(A,B);
  }
