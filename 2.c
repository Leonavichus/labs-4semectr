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

double Rec_step(float a,int b){
  if(b <= 0) 
    return 1.0;
  else
    return Rec_step(a,b-1)*a;
}

double rec_degree(double a,int b){
  double r;
  if(!b)
    return 1;
  if(!(b%2))
    return r=rec_degree(a,b/2), r*r;
  else 
    return a*rec_degree(a,b-1);
}

int NOD_rec(int a,int b){
  if(!(a%b))
    return b;
  else
    return NOD_rec(b,a%b);
}

void printd(int k){
  if(k<0){
    putchar('-');
    k= -k;
  }
  if(k/10)
    printd(k/10);
  putchar(k%10 +'0');
}

void Reverse(){
  int ch;
  if((ch=getch()) !='\r'){
    Reverse();
    putchar(ch);
  }
}

int sum(int *s,int n){
  if(n==1)
    return s[0];
  else
    return sum(s,n-1) + s[n-1];
}

int main() {
  int k=4,l=7,c=2,v=3,d=4,y=5;
  float j=3.4;
  double f=3.45;
  printf("n!=%f\n",Rec_Fact(k));
  printf("fib_l=%lu\n",fib(l));
  printf("Rec_step=%f\n",Rec_step(j,c));
  printf("rec_degree=%f\n",rec_degree(f,v));
  printf("NOD_rec=%d\n",NOD_rec(d,y));
  printd(l);
  Reverse();
  printf("sum=%d\n",sum(d,c));
  return 0;
}
