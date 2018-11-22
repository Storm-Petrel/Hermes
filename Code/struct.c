#include "car.c"
#include <string.h>
#define MAXS 200000

void add(car *head, car *tail, car *c);
void print_list();
void alertCars(car *temp);
void updatePos(car *temp);

void downloadDatabase(car *head, car *tail) {

    char *line = NULL;          /* pointer to use with getline ()   */
    int read = 0;           /* characters read by getline ()    */
    size_t n = 0;               /* number of bytes to allocate      */
    car **cars = NULL;  /* ptr to array of stuct student    */
    char *sp = NULL;            /* start pointer for parsing line   */
    char *p = NULL;             /* end pointer to use parsing line  */
    int field = 0;              /* counter for field in line         */
    int cnt = 0;                /* counter for number allocated     */
    int it = 0;                 /* simple iterator variable         */

    FILE *fp;
    fp = fopen ("cars.csv", "r");
    if (!fp) {
        fprintf (stderr, "failed to open file for reading\n");
        return;
    }

    cars = calloc (MAXS, sizeof (*cars));

    while ((read = getline(&line, &n, fp)) != -1) {

        sp = p = line;
        field = 0;

        cars[cnt] = malloc (sizeof (**cars));

        while (*p)
        {
            if (*p == ',')
            {
                *p = 0;

                if (field == 0) cars[cnt]->placa = strdup(sp);
                if (field == 1) cars[cnt]->posAtual.lat = atof(sp);
                if (field == 2) cars[cnt]->posAtual.lon  = atof(sp);
				if (field == 3) cars[cnt]->geofence[0].lat = atof(sp);
				if (field == 4) cars[cnt]->geofence[0].lon = atof(sp);
				if (field == 5) cars[cnt]->geofence[1].lat = atof(sp);
				if (field == 6) cars[cnt]->geofence[1].lon = atof(sp);
				if (field == 7) cars[cnt]->geofence[2].lat = atof(sp);
				if (field == 8) cars[cnt]->geofence[2].lon = atof(sp);
				if (field == 9) cars[cnt]->geofence[3].lat = atof(sp);
				if (field == 10) cars[cnt]->geofence[3].lon = atof(sp);
				if (field == 11) cars[cnt]->viagem.on = atoi(sp);										

                *p = ','; 
                sp = p + 1;
                field++;
            }
            p++; 
        }
        cars[cnt]->viagem.timestamp = atoi(sp);
		add(head, tail, cars[cnt]);
        cnt++;
        return;
    }

    fclose (fp);
    if (line)
        free (line);
	
    //updatePos(head);
	//alertCars(head);
    printf ("\nThere are %d Cars in database!\n\n", cnt);

    it = 0;
    while (cars[it])
    {
        if (cars[it]->placa)
            free (cars[it]->placa);
        free (cars[it]);
        it++;
    }
    if (cars) free (cars);

    return;
}

void add(car *head, car * tail, car *c)
{       
        car *temp;
        temp = (car *) malloc(sizeof(car));
		temp = c;
        printf("%s\n", temp->placa);
        temp->posAtual.latrad = degrees2radians(temp->posAtual.lat);
        temp->posAtual.lonrad = degrees2radians(temp->posAtual.lon);
        for(int i=0; i<polyCorners; i++){
            temp->geofence[i].latrad = degrees2radians(temp->geofence[i].lat);
            temp->geofence[i].lonrad = degrees2radians(temp->geofence[i].lon);
        }
    	temp->proximo=(car *)0;
        head=NULL;
    if(head==NULL)
    {
        strcpy(head->placa, temp->placa);
        tail=head;
        printf("entrou\n");
        temp = NULL;
        free(temp);
        return;
    }
    else
    {
        tail->proximo=temp;
        tail=temp; 
        printf("nope\n");
        temp = NULL;
        free(temp);
        return;
    }
}

void print_list(car *head)
{
    printf("\n\n");
    car *temp;
    temp = malloc(sizeof(car));
    for(temp=head; temp!=(car *)0; temp=temp->proximo)
    {
        printf("[%s]->",(temp->placa));

    }
    temp = NULL;
    free(temp);
    printf("[NULL]\n\n");
}

void alertCars(car *head){
    car *temp;
    temp = malloc(sizeof(car));
    for(temp=head; temp!=(car *)0; temp=temp->proximo)
    {
        //printf("\n");
        alert(temp);
    }
    temp = NULL;
    free(temp);
}

void updatePos(car *head){
    char *line2 = NULL;          /* pointer to use with getline ()   */
    int read2 = 0;           /* characters read by getline ()    */
    size_t n2 = 0;               /* number of bytes to allocate      */
    car **cars2 = NULL;  /* ptr to array of stuct student    */
    char *sp2 = NULL;            /* start pointer for parsing line   */
    char *p2 = NULL;             /* end pointer to use parsing line  */
    int field2 = 0;              /* counter for field in line         */
    int cnt2 = 0;                /* counter for number allocated     */
    int it2 = 0;                 /* simple iterator variable         */

    FILE *file;
    file = fopen ("UpdatePos.csv", "r");
    if (!file) {
        fprintf (stderr, "failed to open file for reading\n");
        return;
    }

    cars2 = calloc (MAXS, sizeof (*cars2));

    while ((read2 = getline (&line2, &n2, file)) != -1) {

        sp2 = p2 = line2;
        field2 = 0;

        cars2[cnt2] = malloc (sizeof (**cars2));

        while (*p2)
        {
            if (*p2 == ',')
            {
                *p2 = 0;

                if (field2 == 0) cars2[cnt2]->placa = strdup(sp2);
                if (field2 == 1) cars2[cnt2]->posAtual.lat = atof(sp2);									

                *p2 = ','; 
                sp2 = p2 + 1;
                field2++;
            }
            p2++; 
        }
        cars2[cnt2]->posAtual.lon = atof(sp2);
        cnt2++;
    }
    fclose (file);
    car *temp;
    temp = malloc(sizeof(car));
    temp = head;

    int i = 0;
    for(temp=head; temp!=(car *)0; temp=temp->proximo)
    {
        temp->posAtual.lat = cars2[i]->posAtual.lat;
        temp->posAtual.lon = cars2[i]->posAtual.lon;
        temp->posAtual.latrad = degrees2radians(temp->posAtual.lat);
        temp->posAtual.lonrad = degrees2radians(temp->posAtual.lon);
        temp = temp->proximo;
        i++;
    }

    if (line2)
        free (line2);

    it2 = 0;
    while (cars2[it2])
    {
        if (cars2[it2]->placa)
            free (cars2[it2]->placa);
        free (cars2[it2]);
        it2++;
    }
    if (cars2) free (cars2);

    return;
}
