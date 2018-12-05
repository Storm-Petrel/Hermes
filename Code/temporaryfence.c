#include "car.c"
#include <math.h>


double distance(double x1, double y1, double x2, double y2)
{
    double square_difference_x = (x2 - x1) * (x2 - x1);
    double square_difference_y = (y2 - y1) * (y2 - y1);
    double sum = square_difference_x + square_difference_y;
    double value = sqrt(sum);
    return value;
}


double temporaryFence(car *c){
  double i = MIN(MIN(distance(c->posAtual.lat,c->posAtual.lon,c->ativa.cerca[0].lat,c->ativa.cerca[0].lon),distance(c->posAtual.lat,c->posAtual.lon,c->ativa.cerca[1].lat,c->ativa.cerca[1].lon)),MIN(distance(c->posAtual.lat,c->posAtual.lon,c->ativa.cerca[2].lat,c->ativa.cerca[2].lon),distance(c->posAtual.lat,c->posAtual.lon,c->ativa.cerca[3].lat,c->ativa.cerca[3].lon)));
  if (i == distance(c->posAtual.lat,c->posAtual.lon,c->ativa.cerca[0].lat,c->ativa.cerca[0].lon)){

    double j = MIN(distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon), distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[3].lat, c->ativa.cerca[3].lon));
    
    if(j == distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon)){
      if(c->ativa.cerca[0].lat <= c->posAtual.lat) c->ativa.cerca[0].lat = c->posAtual.lat + 0.01;
      if(c->ativa.cerca[0].lon >= c->posAtual.lon) c->ativa.cerca[0].lon = c->posAtual.lon - 0.01;
      if(c->ativa.cerca[1].lat <= c->posAtual.lat) c->ativa.cerca[1].lat = c->posAtual.lat + 0.01;
    }else{
      if(c->ativa.cerca[3].lon >= c->posAtual.lon) c->ativa.cerca[3].lon = c->posAtual.lon - 0.01;
      if(c->ativa.cerca[0].lat <= c->posAtual.lat) c->ativa.cerca[0].lat = c->posAtual.lat + 0.01;
      if(c->ativa.cerca[0].lon >= c->posAtual.lon) c->ativa.cerca[0].lon = c->posAtual.lon - 0.01;
    }
    c->ativa.timestamp = time(NULL);
    return 1;
  }else if(i == distance(c->posAtual.lat,c->posAtual.lon,c->ativa.cerca[1].lat,c->ativa.cerca[1].lon)){

    double j = MIN(distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon), distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[2].lat, c->ativa.cerca[2].lon));
    
    if(j == distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon)){
      if(c->ativa.cerca[1].lat <= c->posAtual.lat) c->ativa.cerca[1].lat = c->posAtual.lat + 0.01;
      if(c->ativa.cerca[1].lon <= c->posAtual.lon) c->ativa.cerca[1].lon = c->posAtual.lon + 0.01;
      if(c->ativa.cerca[0].lat <= c->posAtual.lat) c->ativa.cerca[0].lat = c->posAtual.lat + 0.01;
    }else{
      if(c->ativa.cerca[2].lon <= c->posAtual.lon) c->ativa.cerca[2].lon = c->posAtual.lon + 0.01;
      if(c->ativa.cerca[1].lat <= c->posAtual.lat) c->ativa.cerca[1].lat = c->posAtual.lat + 0.01;
      if(c->ativa.cerca[1].lon <= c->posAtual.lon) c->ativa.cerca[1].lon = c->posAtual.lon + 0.01;
    }
    c->ativa.timestamp = time(NULL);
    return 2;
  }else if(i == distance(c->posAtual.lat,c->posAtual.lon,c->ativa.cerca[2].lat,c->ativa.cerca[2].lon)){

    double j = MIN(distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon), distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[3].lat, c->ativa.cerca[3].lon));
    
    if(j == distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon)){
      if(c->ativa.cerca[2].lat >= c->posAtual.lat) c->ativa.cerca[2].lat = c->posAtual.lat - 0.01;
      if(c->ativa.cerca[2].lon <= c->posAtual.lon) c->ativa.cerca[2].lon = c->posAtual.lon + 0.01;
      if(c->ativa.cerca[1].lon <= c->posAtual.lon) c->ativa.cerca[1].lon = c->posAtual.lon + 0.01;
    }else{
      if(c->ativa.cerca[3].lat >= c->posAtual.lat) c->ativa.cerca[3].lat = c->posAtual.lat - 0.01;
      if(c->ativa.cerca[2].lat >= c->posAtual.lat) c->ativa.cerca[2].lat = c->posAtual.lat - 0.01;
      if(c->ativa.cerca[2].lon <= c->posAtual.lon) c->ativa.cerca[2].lon = c->posAtual.lon + 0.01;
    }
    c->ativa.timestamp = time(NULL);
    return 3;
  }else{

    double j = MIN(distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon), distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[2].lat, c->ativa.cerca[2].lon));
    
    if(j == distance(c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon)){
      if(c->ativa.cerca[3].lat >= c->posAtual.lat) c->ativa.cerca[3].lat = c->posAtual.lat - 0.01;
      if(c->ativa.cerca[3].lon >= c->posAtual.lon) c->ativa.cerca[3].lon = c->posAtual.lon - 0.01;
      if(c->ativa.cerca[0].lon >= c->posAtual.lon) c->ativa.cerca[0].lon = c->posAtual.lon - 0.01;
    }else{
      if(c->ativa.cerca[2].lat >= c->posAtual.lat) c->ativa.cerca[2].lat = c->posAtual.lat - 0.01;
      if(c->ativa.cerca[3].lat >= c->posAtual.lat) c->ativa.cerca[3].lat = c->posAtual.lat - 0.01;
      if(c->ativa.cerca[3].lon >= c->posAtual.lon) c->ativa.cerca[3].lon = c->posAtual.lon - 0.01;
    }
    c->ativa.timestamp = time(NULL);
    return 4;
  }
}