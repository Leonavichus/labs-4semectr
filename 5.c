#include <stdio.h>
#include <math.h>


typedef struct{
  int x,y;
//}Point;
}Point,*pPoint;

double dist(Point *A, Point *B){
  //return sqrt(pow((*A).x - (*B).x,2) + pow((*A).y - (*B).y,2));
  return sqrt(pow(A->x - B->x,2) + pow(A->y - B->y,2));
}

int main(void) {
  Point A={0,-3},B={0,1};
  //printf("d=%f", dist(&A,&B));
  pPoint pA = &A;
  pPoint pB = &B;
  printf("d=%f", dist(pA,pB));
}
