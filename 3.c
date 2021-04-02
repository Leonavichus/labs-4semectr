#include <stdio.h>
#include <math.h>

struct Point{
  int x;
  int y;
};

struct Point1{
  int x,y;
}A1,B1;

struct Poin3{
  int x,y;
}A2={0,-3},B2={0,1};

typedef struct{
  int x,y;
}Point2;

int main(void) {
  double d;
  struct Point A={0,-3},B={0,1};
  d = sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
  printf("d=%f\n",d);
  double d1;
  A1.x=0;A1.y=-3;B1.x=0;B1.y=1;
  d1 = sqrt(pow(A1.x-B1.x,2)+pow(A1.y-B1.y,2));
  printf("d1=%f\n",d1);
  double d2;
  d2 = sqrt(pow(A2.x-B2.x,2)+pow(A2.y-B2.y,2));
  printf("d2=%f\n",d2);
  double d3;
  Point2 A3={0,-3},B3={0,1};
  d3 = sqrt(pow(A3.x-B3.x,2)+pow(A3.y-B3.y,2));
  printf("d3=%f\n",d3);
}
