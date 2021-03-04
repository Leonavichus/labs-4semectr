#include <stdio.h>
#include <time.h>

const int size = 8;

  void makeArr(int *A){
    srand(time(NULL));
    int i;
    for(i=0;i<size;i++)
    A[i] = rand() % 51;
  }

  void printArr(int *A){
    int i;
    for(i=0;i<size;i++)
    printf("%d\t",A[i]);
  }

  void copyArr(int *A, int *B){
    int i;
    for(i=0;i<size;i++)
      B[i]=A[i];
  }
  void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  void Bubble(int *arr){
    int i,j,c=0,p=0;
    for(i=0;i<size-1;i++)
      for(j=0;j<size-i-1;j++){c++;
        if(arr[j]>arr[j+1]){p++;
          swap(&arr[j], &arr[j + 1]);
        }
      }
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

  void Bubble_New(int *arr){
    int i,j = 0,m,c=0,p=0;
    do{
      m=j;
      for(i=size-1;i>m;i--){c++;
        if(arr[i-1]>arr[i]){
          j=i;p++;
          swap(&arr[j], &arr[j - 1]);
        }
      }
    } while(j-m);
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

  void Shaker(int *arr){
    int i,j,n1=0,n2=size-1,c=0,p=0;
    do{
      for(i=n2;i > n1;i--) {c++;
        if(arr[i-1]>arr[i]){p++;
          swap(&arr[i -1], &arr[i]);
          j=i;
        }
      }
    n1=j;
    for(i=n1;i<=n2;i++){c++;
      if(arr[i-1]>arr[i]){
        swap(&arr[i-1], &arr[i]);
        j=i;p++;
      }
    }
    n2=j-1;
    } while(n1<n2);
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

  void InsertSort(int *arr){
    int i,j,temp,c=0;
    double p=0;
    for(i=1;i<size;i++){
      if(arr[i]<arr[i-1]){
        temp=arr[i];p+=1./3;
      for(j=i-1;j>=0 && arr[j]>temp;j--,c++){
        arr[j+1]=arr[j];
      }
      arr[j+1]=temp;p+=1./3;
      }
    }
    printf("compar=%d,reshuffle=%lf\n",c,p);
  }

  void SelectionSort(int *arr){
    int i,j,im,temp,c=0,p=0;
    for(i=0;i<size-1;i++){
      im=i;
      for(j=i+1;j<size;j++){c++;
        if(arr[j]<arr[im])
        im=j;}
        c++;
        if(i!=im){
          p++;
          swap(&arr[im], &arr[i]);
        }
      }
    printf("compar=%d,reshuffle=%d\n",c,p);
    }
  
	void Shella(int *arr){
		int i,j,temp,step = size/2,c=0,p=0;
		while(step>0){
			for(i=0;i<(size - step);i++){c++;
			j=i;
			while(j>=0 && arr[j]>arr[j+step]){
				c++;p++;
				temp=arr[j];
				arr[j]=arr[j+step];
				arr[j+step]=temp;
				j--;
			}
			}
			step /=2;
		}
		printf("compar=%d,reshuffle=%d\n",c,p);
	}

  int main(){
    int A[size],B[size];
    makeArr(A);
    printArr(A);
    copyArr(A,B);
    printf("\n");
    printArr(B);
    printf("\n Bubble:\n");
    Bubble(B);
    printArr(B);
    copyArr(A,B);
    printf("\n Bubble_New:\n");
    Bubble_New(B);
    printArr(B);
    copyArr(A,B);
    printf("\n Shaker:\n");
    Shaker(B);
    printArr(B);
    copyArr(A,B);
    printf("\n InsertSort:\n");
    InsertSort(B);
    printArr(B);
    copyArr(A,B);
    printf("\n SelectionSort:\n");
    SelectionSort(B);
    printArr(B);
    copyArr(A,B);
	  printf("\n Shella:\n");
    Shella(B);
    printArr(B);
    copyArr(A,B);
  }
