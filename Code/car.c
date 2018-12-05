#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "geofence.c"
#include "travel.c"

#define max_cercas 5
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct car{
    char *placa;
    position posAtual;
    geofence ativa;
    geofence cercas[max_cercas];
    viagem viagem;
    struct car *proximo;
    bool alerta;
    char *senha;
    bool soundAlert;
}car;

bool pointInGeofence(car *c) {
  int counter = 0;
  int i;
  double xinters;
  position p, p1,p2;
  p = c->posAtual;
  p1 = c->ativa.cerca[0];
  for (i=1;i<=polyCorners;i++) {
    p2 = c->ativa.cerca[i % polyCorners];
    if (p.lat > MIN(p1.lat,p2.lat)) {
      if (p.lat <= MAX(p1.lat,p2.lat)) {
        if (p.lon <= MAX(p1.lon,p2.lon)) {
          if (p1.lat != p2.lat) {
            xinters = (p.lat-p1.lat)*(p2.lon-p1.lon)/(p2.lat-p1.lat)+p1.lon;
            if (p1.lon == p2.lon || p.lon <= xinters)
              counter++;
          }
        }
      }
    }
    p1 = p2;
  }

  if (counter % 2 == 0)
    return false;
  else
    return true;
}

position getCenterOfGeofence(car *carro){
    position center;
	double X=0;
	double Y=0;
	double Z=0;
    double lat1, lon1, Lon, Hyp, Lat;

	for(int i = 0; i < polyCorners; i++){
		lat1= carro->ativa.cerca[i].lat;
		lon1= carro->ativa.cerca[i].lon;
		lat1 = lat1 * M_PI/180;
		lon1 = lon1 * M_PI/180;
		X += cos(lat1) * cos(lon1);
		Y += cos(lat1) * sin(lon1);
		Z += sin(lat1);
	}
	Lon = atan2(Y, X);
	Hyp = sqrt(X * X + Y * Y);
	Lat = atan2(Z, Hyp);
	center.lat = Lat * 180/M_PI;
	center.lon = Lon * 180/M_PI;
	return center;
}

void runScript(){
    char command[60];
    snprintf(command, sizeof(command), "cd  C:\\Users\\Tiago\\Desktop\\Hermes");
    system(command);
    system("python ./script.py");
    system("del alert.txt");
    return;
}

void switchTravelButton(car *c){
    if(c->viagem.on == false){
        c->viagem.on = true;
        c->viagem.timestamp = time(NULL);
    }else{
        c->viagem.on = false;
    }
}

bool checkTimestamp(car *c){
    if(time(NULL) - c->viagem.timestamp >= 300){
        return false;
    }else{
        return true;
    }
}

void alert(car *c){
    if (pointInGeofence(c) != true && c->viagem.on != true && c->soundAlert != true){
        c->soundAlert=true;
        FILE *fp = NULL;
        fp = fopen("alert.txt" ,"a");
        char link[1024];
        char Key[] = "AIzaSyDAPnKQJwXhgqTLznH3JthGhVnrLBuu6p0";
        char button[1024];
        snprintf(button, sizeof(button), "Clique <a href=\"https://stormpetrel.mybluemix.net/putdata?_id=%s\">aqui</a> para ir ao site de alerta", c->placa);
        position posAtual = getCenterOfGeofence(c);
        snprintf(link, sizeof(link), "https://maps.googleapis.com/maps/api/staticmap?center=%f,%f&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&markers=size:mid%%7Ccolor:0xff0000%%7Clabel:%%7C%f,%f&path=color%%3ared|weight:1|fillcolor%%3ablank|%f,%f|%f,%f|%f,%f|%f,%f|%f,%f&key=%s", posAtual.lat, posAtual.lon, c->posAtual.lat, c->posAtual.lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, c->ativa.cerca[1].lat, c->ativa.cerca[1].lon, c->ativa.cerca[2].lat, c->ativa.cerca[2].lon, c->ativa.cerca[3].lat, c->ativa.cerca[3].lon, c->ativa.cerca[0].lat, c->ativa.cerca[0].lon, Key);
        fprintf(fp, "<html>\n<body>\n<p>\nVeiculo saiu da GeoFence! Atividade é estranha?\n</p>\n<div style=\"text-align:center;\">\n<img src=\"%s\" width=\"640\" height=\"640\" border=\"0\" alt=\"geofence\">\n<br>\n<span style=\"font-size:smaller;\">\nLocalização atual e Geofence do veículo de placa %s\n</span>\n</div>\n<p>\nSe a atividade for estranha %s\n</p>\n</body>\n</html>", link, c->placa, button);
        fclose(fp);
        runScript();
        return;
    }else{
        //printf("Safe!\n");
        if(c->viagem.on == true && pointInGeofence(c) == true  && (time(NULL) - checkTimestamp(c)) != true){
            int desativar;
            printf("Voce esta dentro da sua geofence, digite 1 se deseja desativar o modo viagem\n");
            scanf("%d", &desativar);
            if(desativar == 1){
                c->viagem.on = false;
                c->viagem.timestamp = 0;
                printf("Modo viagem desativado\n");
            }
            c->viagem.timestamp = time(NULL);
        }
        return;
    }
}