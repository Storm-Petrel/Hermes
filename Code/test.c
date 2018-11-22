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

int main(void){
    car *c;
    c = malloc(sizeof(car));
    c->posAtual.lat = -8.062431;
    c->posAtual.lon = -34.969744;
    c->ativa.cerca[0].lat = -8.021154;
    c->ativa.cerca[0].lon = -34.933909;
    c->ativa.cerca[1].lat = -8.027868;
    c->ativa.cerca[1].lon = -34.852109;
    c->ativa.cerca[2].lat = -8.122738;
    c->ativa.cerca[2].lon = -34.874526;
    c->ativa.cerca[3].lat = -8.052431;
    c->ativa.cerca[3].lon = -34.959744;
    c->ativa.timestamp = 0;
    c->posAtual.latrad = degrees2radians(c->posAtual.lat);
    c->posAtual.lonrad = degrees2radians(c->posAtual.lon);
    for(int i=0; i<polyCorners; i++){
        c->ativa.cerca[i].latrad = degrees2radians(c->ativa.cerca[i].lat);
        c->ativa.cerca[i].lonrad = degrees2radians(c->ativa.cerca[i].lon);
    }

    c->cercas[0] = c->ativa;

    bool h = pointInGeofence(c);

    printf(h ? "true\n" : "false\n");

    char link[1024];
    char Key[] = "AIzaSyDAPnKQJwXhgqTLznH3JthGhVnrLBuu6p0";
    position posAtual = getCenterOfGeofence(c);
    snprintf(link, sizeof(link), "https://maps.googleapis.com/maps/api/staticmap?center=%f,%f&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&markers=size:mid%%7Ccolor:0xff0000%%7Clabel:%%7C%f,%f&path=color%%3ared|weight:1|fillcolor%%3ablank|%f,%f|%f,%f|%f,%f|%f,%f|%f,%f&key=%s", posAtual.lat, posAtual.lon, c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon, c->ativa.cerca[2].lat, c->ativa.cerca[2].lon, c->ativa.cerca[3].lat, c->ativa.cerca[3].lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, Key);
    printf("%s\n", link);

    double i = temporaryFence(c);

    printf("%lf\n", i);

    bool j = pointInGeofence(c);

    printf(j ? "true\n" : "false\n");

    char link2[1024];
    posAtual = getCenterOfGeofence(c);
    snprintf(link2, sizeof(link2), "https://maps.googleapis.com/maps/api/staticmap?center=%f,%f&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&markers=size:mid%%7Ccolor:0xff0000%%7Clabel:%%7C%f,%f&path=color%%3ared|weight:1|fillcolor%%3ablank|%f,%f|%f,%f|%f,%f|%f,%f|%f,%f&key=%s", posAtual.lat, posAtual.lon, c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon, c->ativa.cerca[2].lat, c->ativa.cerca[2].lon, c->ativa.cerca[3].lat, c->ativa.cerca[3].lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, Key);
    printf("%s\n", link2);

    while(c->ativa.timestamp != 0){
      if(time(NULL) - c->ativa.timestamp >= 100){
        for(int i = 0; i < max_cercas; i++){
          if(c->ativa.nome == c->cercas[i].nome) c->ativa = c->cercas[i]; 
        }
      }
    }

    bool l = pointInGeofence(c);

    printf(l ? "true\n" : "false\n");

    char link3[1024];
    posAtual = getCenterOfGeofence(c);
    snprintf(link3, sizeof(link3), "https://maps.googleapis.com/maps/api/staticmap?center=%f,%f&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&markers=size:mid%%7Ccolor:0xff0000%%7Clabel:%%7C%f,%f&path=color%%3ared|weight:1|fillcolor%%3ablank|%f,%f|%f,%f|%f,%f|%f,%f|%f,%f&key=%s", posAtual.lat, posAtual.lon, c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon, c->ativa.cerca[2].lat, c->ativa.cerca[2].lon, c->ativa.cerca[3].lat, c->ativa.cerca[3].lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, Key);
    printf("%s\n", link3);

    return 0;
}