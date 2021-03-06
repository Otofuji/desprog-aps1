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

int inside(point p, point poly[], int n) {
  int sm = 0;
  int sd;

  for(int i = 0; i < n; i++){ 
    if (i == n-1) {sd = verify(p, poly[i], poly[0]);}
    else {sd = verify(p, poly[i], poly[i+1]);}
    if (sd == 2) {return 1; break;}

    sm += sd;
  }
  
  if(sm % 2 == 1) {return 1;}

  return 0;  
}
