#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int N = 2;

typedef struct uroboros{
  char name[10];
  int level;
  int result;
} gamedev;

void enter_arr(gamedev * arr)
{
  for (int i = 0; i < N; i++)
  {
    printf("Введите имя и результат: ");
    scanf("%s%d",arr[i].name,&arr[i].result);
    //printf("Введите уровень: ");
    //scanf("%d", &arr[i].level);
  }
}


void Insert (gamedev * arr){
    int i,j, temp;
    for(i=1;i<N;i++){
      temp = arr[i].result;
      j=i-1;
      while(j>=0 && arr[j].result>temp){
        arr[j+1].result = arr[j].result;
        j--;
      }
      arr[j+1].result = temp;
    }
}

void output_arr(gamedev * arr){
    for (int i = 0; i < N; i++){
      printf("Команда %s заняла %d место\n",arr[i].name,arr[i].result);
    }
}

int main(void){
  gamedev clubs[N];
  enter_arr(clubs);
  Insert(clubs);
  output_arr(clubs);
}
