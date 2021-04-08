#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int N = 5;

typedef struct uroboros{
  char name[10];
  int level;
  int result;
} gamedev;


void enter_arr(gamedev * arr)
{
  for (int i = 0; i < N; i++)
  {
    printf("Введите имя %d команды и результат: ", i+1);
    scanf("%s%d",arr[i].name,&arr[i].result);
    //printf("Введите уровень: ");
    //scanf("%d", &arr[i].level);
  }
}

void output_arr(gamedev * arr){
    for (int i = 0; i < N; i++){
      printf("%d. Команда %s заняла %d место\n",i + 1,arr[i].name,arr[i].result);
    }
}

void Select (gamedev * arr){
    char temp2[100];
    int i,j,im,temp;
    for(i=0;i<N-1;i++){
      im=i;
      for(j=i+1;j<N;j++){
        if(arr[j].result<arr[im].result)
        im=j;}
        if(i!=im){
          temp = arr[im].result;
          arr[im].result = arr[i].result;
          arr[i].result = temp;
          strcpy(temp2,arr[i].name);
          strcpy(arr[i].name,arr[im].name);
          strcpy(arr[im].name,temp2);
    }
  }
}

int main(void){
  gamedev clubs[N];
  enter_arr(clubs);
  Select(clubs);
  output_arr(clubs);
}
