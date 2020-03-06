#include <math.h>

#include "geometry.h"

double distance(double ax, double ay, double bx, double by) {
  double dist = 0.0;
  dist += fabs(bx-ax); //https://stackoverflow.com/questions/20956352/how-to-get-absolute-value-from-double-c-language
  dist += fabs(by-ay);
  return dist;
}

int verify(point p, point a, point b) {
  double zero = 0.000001;
  double ax = (double)a.x;
  double ay = (double)a.y;
  double bx = (double)b.x;
  double by = (double)b.y;
  double px = (double)p.x;
  double py = (double)p.y;
  double mr = (by-ay)/(bx-ax);
  double mp = (py-ay)/(px-ax);
  double xp = (py-ay)/mr;
  double xd = ax + xp;  

  if (  (fabs((distance(ax, ay, px, py) + distance(bx, by, px, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  ((fabs(mr-mp) <= zero) && ((fabs(ax-px) > zero) && (fabs(ay-py) >  zero)) && ((fabs(bx-px) >  zero) && (fabs(by-py) >  zero))  ))  {return 2;} //https://stackoverflow.com/questions/17692922/check-is-a-point-x-y-is-between-two-points-drawn-on-a-straight-line
  if (  (fabs((distance(ax, ay, px, py) + distance(bx, by, px, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  (              (   (fabs(ax-px) <= zero)      && (fabs(ay-py) <= zero))   || ((fabs(bx-px) <= zero) && (fabs(by-py) <= zero))  ))  {return 2;}
  if (  (fabs((distance(ax, ay, px, py) + distance(bx, by, px, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  (              (                  (fabs(ax-bx)<=zero)                   ) || (               (fabs(ay-by)<=zero)            )  ))  {return 2;}
  
  if (((ay < by)  &&  ((py > ay) && (py <= by)))    &&    ((px <= xd) && (fabs(ax-bx) > zero))) {return 1;}
  if (((by < ay)  &&  ((py > by) && (py <= ay)))    &&    ((px <= xd) && (fabs(ax-bx) > zero))) {return 1;}
  if ((fabs(ax - bx) <= zero) && (px <= ax) && (((ay < by) && py <= by && py > ay) || ((by < ay) && by < py && ay >= py)))  {return 1;}
  if ((fabs(ax - bx) <= zero) && (px <= ax) && (((by < ay) && py <= ay && py > by) || ((ay < by) && ay < py && by >= py)))  {return 1;}

  return 0;
}

int isline(point p, point poly[], int n){
  int chck = 0;
  if (n == 1) {return chck;}
  if ((verify(p, poly[n-2], poly[n-1]) == 2)) {return 1;}
  return chck || isline(p, poly, n-1); 
}

int iscross(point p, point poly[], int n){
  int chck = 0;
  if (n == 1) {return chck;}
  if ((verify(p, poly[n-2], poly[n-1]) == 1)) {chck = 1;}
  return chck + iscross(p, poly, n-1); 
}

int inside(point p, point poly[], int n) {
  if (isline(p, poly, n) == 1) {return 1;}
  if ((iscross(p, poly, n) != 0) && ((iscross(p, poly, n) % 2) == 1)) {return 1;}
  return 0;
  
  //int check = 0;
  //if (n==0) {return check;}
  //if ((verify(p, poly[n], poly[n+1]) == 2) {n = 0; check = 1; return 1;}
  //check += verify(p, poly[n], poly[n+1]);
  //return (check != 0 && check % 2) && inside(p, poly, n-1);




  //if (verify(p, poly[n], poly[n+1]) == 2) {n = 0; check = 1; return check;}
  //if (n == 0 && (check % 2 == 1)) {return check + 1;}
  //if (n == 0 && (check % 2 == 0)) {return 0;}
  //if (verify(p, poly[n], poly[n+1]) == 1) {check++;}
  //return 0 + inside(p, poly, n-1);
  
}
