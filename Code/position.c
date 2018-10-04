#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef struct position{
  double lat;
  double lon;
  double latrad;
  double lonrad;
}position;

double degrees2radians(double degrees){
    return degrees*M_PI/180;
}
double radians2degrees(double radians){
    return radians*M_PI/180;
}