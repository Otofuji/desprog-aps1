#include <math.h>

#include "geometry.h"

double distance(double ax, double ay, double bx, double by) {
  double dist = 0.0;
  dist += fabs(bx-ax); //https://stackoverflow.com/questions/20956352/how-to-get-absolute-value-from-double-c-language
  dist += fabs(by-ay);
  return dist;
}

int verify(point p, point a, point b) {
  int    il = 0;
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
  double xd = px - xp;
  double md = (py-ay)/(xd-ax);
  
  
  

  if (  (fabs((distance(ax, ay, px, py) + distance(bx, by, px, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  ((fabs(mr-mp) <= zero) && ((fabs(ax-px) > zero) && (fabs(ay-py) >  zero)) && ((fabs(bx-px) >  zero) && (fabs(by-py) >  zero))  ))  {return 2;} //https://stackoverflow.com/questions/17692922/check-is-a-point-x-y-is-between-two-points-drawn-on-a-straight-line
  if (  (fabs((distance(ax, ay, px, py) + distance(bx, by, px, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  (              (   (fabs(ax-px) <= zero)      && (fabs(ay-py) <= zero))   || ((fabs(bx-px) <= zero) && (fabs(by-py) <= zero))  ))  {return 2;}
  if (  (fabs((distance(ax, ay, px, py) + distance(bx, by, px, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  (              (                  (fabs(ax-bx)<=zero)                   ) || (               (fabs(ay-by)<=zero)            )  ))  {return 2;}
  


  if (  (fabs((distance(ax, ay, xd, py) + distance(bx, by, xd, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  ((fabs(mr-md) <= zero) && ((fabs(ax-xd) > zero) && (fabs(ay-py) >  zero)) && ((fabs(bx-xd) >  zero) && (fabs(by-py) >  zero))  ))  {il = 1;}
  if (  (fabs((distance(ax, ay, xd, py) + distance(bx, by, xd, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  (              (    (fabs(ax-xd)<=zero)       && (fabs(ay-py)<=zero))     || ((fabs(bx-xd) <= zero) && (fabs(by-py) <= zero))  ))  {il = 1;}
  if (  (fabs((distance(ax, ay, xd, py) + distance(bx, by, xd, py)) - (distance(ax, ay, bx, by))) <= zero)  &&  (              (                  (fabs(ax-bx)<=zero)                   ) || (               (fabs(ay-by)<=zero)            )  ))  {il = 1;}
  
  if ((ay < by)  &&  ((ay < py) && (py > by))    &&      ((px <= xd) && (fabs(ax-bx) > zero))   &&   (il == 1)) {return 1;}
  if ((by < by)  &&  ((by < py) && (py > ay))    &&      ((px <= xd) && (fabs(ax-bx) > zero))   &&   (il == 1)) {return 1;}
  if ((fabs(ax - bx) <= zero) && (((ay < by) && (fabs(ax-bx) > zero)) || ((by < ay) && (fabs(ax-bx) > zero))))  {return 1;}

  return 0;
}

int inside(point p, point poly[], int n) {
  return 0;
}
