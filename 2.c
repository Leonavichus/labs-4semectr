#include <stdio.h>

double Rec_Fact(int n){
  if (n <= 1)
    return 1.0;
  else 
    return Rec_Fact(n-1)*n;
}

unsigned long fib(int n){
  if(n==0 || n==1)
    return 1;
  else
    return fib(n-1)+fib(n-2);
}

double Rec_step(int a,int b){
  if(b <= 0) 
    return 1.0;
  else
    return Rec_step(a,b-1)*a;
}

int main() {
  int k = 4,l=7,a=3,b=4;
  printf("n!=%f\n",Rec_Fact(k));
  printf("fib_l=%lu\n",fib(l));
  printf("fib_l=%f\n",Rec_step(a,b));
  return 0;
}
