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

void svap(int *a,int k){
    int q;
    q=a[k-1];
    a[k-1]=a[k];
    a[k]=q;
}
  
  void Bubble(int *M){
    int i,j,c=0,p=0;
    for(i=0;i<size-1;i++)
      for(j=size-1;j>i;j--){c++;
        if(M[j-1]>M[j]){p++;
          swap(M,j);
        }
      }
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

  void Bubble_New(int *M){
    int i,j = 0,m,c=0,p=0;
    do{
      m=j;
      for(i=size-1;i>m;i--){c++;
        if(M[i-1]>M[i]){
          j=i;p++;
          swap(M,j);
        }
      }
    } while(j-m);
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

  void Shaker(int *M){
    int i,t,n1=0,n2=size-1,j,c=0,p=0;
    do{
      for(i=n2;i > n1;i--) {c++;
        if(M[i-1]>M[i]){p++;
          svap(M,i);
          j=i;
        }
      }
    n1=j;
    for(i=n1;i<=n2;i++){c++;
      if(M[i-1]>M[i]){
        svap(M,i);
        j=i;p++;
      }
    }
    n2=j-1;
    } while(n1<n2);
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

  void InsertSort(int *M){
    int i,j,temp,c=0;
    double p=0;
    for(i=1;i<size;i++){
      if(M[i]<M[i-1]){
        temp=M[i];p+=1./3;
      for(j=i-1;j>=0 && M[j]>temp;j--,c++){
        M[j+1]=M[j];
      }
      M[j+1]=temp;p+=1./3;
      }
    }
    printf("compar=%d,reshuffle=%lf\n",c,p);
  }

  void  SelectionSort(int *M){
    int i,j,im,temp,c=0,p=0;
    for(i=0;i<size-1;i++){
      im=i;
      for(j=i+1;j<size;j++){c++;
        if(M[j]<M[im])
        im=j;}
        c++;
        if(i!=im){
          p++;
          temp=M[i];
          M[i]=M[im];
          M[im]=temp;
        }
      }
    printf("compar=%d,reshuffle=%d\n",c,p);
    }
  
	void Shella(int *M){
		int i,j,temp,step = size/2,c=0,p=0;
		while(step>0){
			for(i=0;i<(size - step);i++){c++;
			j=i;
			while(j>=0 && M[j]>M[j+step]){
				c++;p++;
				temp=M[j];
				M[j]=M[j+step];
				M[j+step]=temp;
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
