#include <math.h>

#include "geometry.h"

double distance(double ax, double ay, double bx, double by) {
  double dist = 0;
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

  if (  (distance(ax, ay, px, py) + distance(bx, by, px, py) == distance(ax, ay, bx, by))  &&  ((mr == mp) && ((ax != px) && (ay != py)) && ((bx != px) && (by != py))  ))  {return 2;} //https://stackoverflow.com/questions/17692922/check-is-a-point-x-y-is-between-two-points-drawn-on-a-straight-line
  if (  (distance(ax, ay, px, py) + distance(bx, by, px, py) == distance(ax, ay, bx, by))  &&  (              ((ax == px) && (ay == py)) || ((bx == px) && (by == py))  ))  {return 2;}
  if (  (distance(ax, ay, px, py) + distance(bx, by, px, py) == distance(ax, ay, bx, by))  &&  (              (       (ax == bx)       ) || (       (ay == by)       )  ))  {return 2;}

  if ((ay - by <= zero)  &&  ((ay < py) && (py <= by))    &&    (ax - bx <= zero)  &&  (px <= ax)) {return 1;}
  if ((ay - by <= zero)  &&  ((ay < py) && (py <= by))    &&    (bx - ax <= zero)  &&  (px <= bx)) {return 1;}
  if ((by - ay <= zero)  &&  ((by < py) && (py <= ay))    &&    (bx - ax <= zero)  &&  (px <= bx)) {return 1;}
  if ((by - ay <= zero)  &&  ((by < py) && (py <= ay))    &&    (ax - bx <= zero)  &&  (px <= ax)) {return 1;}

  return 0;
}

int inside(point p, point poly[], int n) {
  return 0;
}
