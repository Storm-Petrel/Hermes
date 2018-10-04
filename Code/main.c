#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "car.c"

int main()
{
    car *c;

    c = malloc(sizeof(car));

    scanf("%s", c->placa);


	c->geofence[0].lat = -8.021154; 
	c->geofence[0].lon = -34.933909;
	c->geofence[1].lat = -8.027868;
	c->geofence[1].lon = -34.852109;
	c->geofence[2].lat = -8.122738;
	c->geofence[2].lon = -34.874526;
	c->geofence[3].lat = -8.052431;
	c->geofence[3].lon = -34.959744;

    c->viagem.on = false;
	
    for(int i=0; i<polyCorners; i++){
        c->geofence[i].latrad = degrees2radians(c->geofence[i].lat);
        c->geofence[i].lonrad = degrees2radians(c->geofence[i].lon);
    }

    //em casa
    c->posAtual.lat = -8.035045; //Inside
	c->posAtual.lon = -34.905552;
    c->posAtual.latrad = degrees2radians(c->posAtual.lat);
    c->posAtual.lonrad = degrees2radians(c->posAtual.lon);
    alert(c);


    //No C.E.S.A.R. School
	c->posAtual.lat = -8.059615; //Inside 
    c->posAtual.lon = -34.872698;
    c->posAtual.latrad = degrees2radians(c->posAtual.lat);
    c->posAtual.lonrad = degrees2radians(c->posAtual.lon);
    switchTravelButton(c);
    alert(c);

    //Na av.Olinda em direção a Olinda com botão viagem ativado
    c->posAtual.lat = -8.015660;
    c->posAtual.lon = -34.846332;
    c->posAtual.latrad = degrees2radians(c->posAtual.lat);
    c->posAtual.lonrad = degrees2radians(c->posAtual.lon);
    alert(c);

    //Na av.Olinda em direção a Olinda com botão viagem desativado
    c->posAtual.lat = -8.015660;
    c->posAtual.lon = -34.846332;
    c->posAtual.latrad = degrees2radians(c->posAtual.lat);
    c->posAtual.lonrad = degrees2radians(c->posAtual.lon);
    switchTravelButton(c);
    alert(c);

    //No C.E.S.A.R. School com botão viagem ativo
	c->posAtual.lat = -8.059615; //Inside 
    c->posAtual.lon = -34.872698;
    c->posAtual.latrad = degrees2radians(c->posAtual.lat);
    c->posAtual.lonrad = degrees2radians(c->posAtual.lon);
    switchTravelButton(c);
    alert(c);

    delay(5000);

    //No C.E.S.A.R. School com botão viagem ainda ativo após o tempo limite
	c->posAtual.lat = -8.059615; //Inside 
    c->posAtual.lon = -34.872698;
    c->posAtual.latrad = degrees2radians(c->posAtual.lat);
    c->posAtual.lonrad = degrees2radians(c->posAtual.lon);
    alert(c);
}