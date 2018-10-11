#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "position.c"
#include "travel.c"

#define polyCorners 4
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct car{
    char *placa;
    position posAtual;
    position geofence[polyCorners];
    viagem viagem;
    struct car *proximo;
}car;

bool pointInGeofence(car *c) {
    int   i, j=polyCorners-1 ;
    bool  oddNodes=0;

    for(i=0; i<polyCorners; i++) {
        if(((c->geofence[i].latrad< c->posAtual.latrad && c->geofence[j].latrad>=c->posAtual.latrad) 
        || (c->geofence[j].latrad< c->posAtual.latrad && c->geofence[i].latrad>=c->posAtual.latrad))  
        &&  (c->geofence[i].lonrad<=c->posAtual.lonrad || c->geofence[j].lonrad<=c->posAtual.lonrad)) {
        oddNodes^=(c->geofence[i].lonrad+(c->posAtual.latrad-c->geofence[i].latrad) / 
            (c->geofence[j].latrad-c->geofence[i].latrad)*(c->geofence[j].lonrad-c->geofence[i].lonrad)<c->posAtual.lonrad); 
        }
        j=i; 
    }

    return oddNodes; 
}

position getCenterOfGeofence(car *carro){
    position center;
	double X=0;
	double Y=0;
	double Z=0;
    double lat1, lon1, Lon, Hyp, Lat;

	for(int i = 0; i < polyCorners; i++){
		lat1= carro->geofence[i].lat;
		lon1= carro->geofence[i].lon;
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
    printf("O carro de placa %s está: ", c->placa);
    if (pointInGeofence(c) != true && c->viagem.on != true){
        printf("Alerta!\n");

        FILE *fp = NULL;
        fp = fopen("alert.txt" ,"a");
        char link[1024];
        char Key[] = "AIzaSyDAPnKQJwXhgqTLznH3JthGhVnrLBuu6p0";
        position posAtual = getCenterOfGeofence(c);
        snprintf(link, sizeof(link), "https://maps.googleapis.com/maps/api/staticmap?center=%f,%f&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&markers=size:mid%%7Ccolor:0xff0000%%7Clabel:%%7C%f,%f&path=color%%3ared|weight:1|fillcolor%%3ablank|%f,%f|%f,%f|%f,%f|%f,%f|%f,%f&key=%s", posAtual.lat, posAtual.lon, c->posAtual.lat, c->posAtual.lon, c->geofence[0].lat, c->geofence[0].lon, c->geofence[1].lat, c->geofence[1].lon, c->geofence[2].lat, c->geofence[2].lon, c->geofence[3].lat, c->geofence[3].lon, c->geofence[0].lat, c->geofence[0].lon, Key);
        fprintf(fp, "<html>\n<body>\n<p>\nVeiculo saiu da GeoFence! Atividade é estranha?\n</p>\n<div style=\"text-align:center;\">\n<img src=\"%s\" width=\"640\" height=\"640\" border=\"0\" alt=\"geofence\">\n<br>\n<span style=\"font-size:smaller;\">\nLocalização atual e Geofence do veículo de placa %s\n</span>\n</div>\n<p>\nSe a atividade for estranha clique 1 se não clique 2\n</p>\n</body>\n</html>", link, c->placa);
        fclose(fp);
        //runScript();
        return;
    }else{
        printf("Safe!\n");
        if(pointInGeofence(c) == true && c->viagem.on == true && time(NULL) - checkTimestamp(c) != true){
            int desativar;
            printf("Voce esta dentro da sua geofence, digite 1 se deseja desativar o modo viagem\n");
            scanf("%d", &desativar);
            if(desativar == 1){
                c->viagem.on = false;
                printf("Modo viagem desativado\n");
            }
            c->viagem.timestamp = time(NULL);
        }
        return;
    }
}