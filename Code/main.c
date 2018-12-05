#include <string.h>
#include "temporaryfence.c"
#define MAXS 200000

car *head, *tail, *temp;

void add(car *temp);
void getpass(car *temp);
void alertCars(car *temp);
void updatePos(car *temp);

int main(void) {
    char command[60];
    snprintf(command, sizeof(command), "cd  C:\\Users\\Tiago\\Desktop\\Hermes");
    system(command);
    system("python ./downloadDatabase.py");
    
    char *line = NULL;
    int read = 0;
    size_t n = 0;
    car **cars = NULL;
    char *sp = NULL;
    char *p = NULL;
    int field = 0;
    int cnt = 0;
    int it = 0;

    FILE *fp;
    fp = fopen ("db.csv", "r");
    if (!fp) {
        fprintf (stderr, "failed to open file for reading\n");
        return 1;
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
				if (field == 3) cars[cnt]->ativa.cerca[0].lat = atof(sp);
				if (field == 4) cars[cnt]->ativa.cerca[0].lon = atof(sp);
				if (field == 5) cars[cnt]->ativa.cerca[1].lat = atof(sp);
				if (field == 6) cars[cnt]->ativa.cerca[1].lon = atof(sp);
				if (field == 7) cars[cnt]->ativa.cerca[2].lat = atof(sp);
				if (field == 8) cars[cnt]->ativa.cerca[2].lon = atof(sp);
				if (field == 9) cars[cnt]->ativa.cerca[3].lat = atof(sp);
				if (field == 10) cars[cnt]->ativa.cerca[3].lon = atof(sp);
                if (field == 11) cars[cnt]->ativa.timestamp = atoi(sp);
				if (field == 12) cars[cnt]->viagem.on = atoi(sp);										
                if (field == 13) cars[cnt]->viagem.timestamp = atoi(sp);
                if (field == 14) cars[cnt]->cercas[0].nome = strdup(sp);
                if (field == 15) cars[cnt]->cercas[0].cerca[0].lat = atof(sp);
                if (field == 16) cars[cnt]->cercas[0].cerca[0].lon = atof(sp);
                if (field == 17) cars[cnt]->cercas[0].cerca[1].lat = atof(sp);
                if (field == 18) cars[cnt]->cercas[0].cerca[1].lon = atof(sp);
                if (field == 19) cars[cnt]->cercas[0].cerca[2].lat = atof(sp);
                if (field == 20) cars[cnt]->cercas[0].cerca[2].lon = atof(sp);
                if (field == 21) cars[cnt]->cercas[0].cerca[3].lat = atof(sp);
                if (field == 22) cars[cnt]->cercas[0].cerca[3].lon = atof(sp);
                if (field == 23) cars[cnt]->cercas[1].nome = strdup(sp);
                if (field == 24) cars[cnt]->cercas[1].cerca[0].lat = atof(sp);
                if (field == 25) cars[cnt]->cercas[1].cerca[0].lon = atof(sp);
                if (field == 26) cars[cnt]->cercas[1].cerca[1].lat = atof(sp);
                if (field == 27) cars[cnt]->cercas[1].cerca[1].lon = atof(sp);
                if (field == 28) cars[cnt]->cercas[1].cerca[2].lat = atof(sp);
                if (field == 29) cars[cnt]->cercas[1].cerca[2].lon = atof(sp);
                if (field == 30) cars[cnt]->cercas[1].cerca[3].lat = atof(sp);
                if (field == 31) cars[cnt]->cercas[1].cerca[3].lon = atof(sp);
                if (field == 32) cars[cnt]->alerta = atoi(sp);
                *p = ','; 
                sp = p + 1;
                field++;
            }
            p++; 
        }
        //printf("debug\n");
        cars[cnt]->senha = strdup(sp);
		temp = (car *) malloc(sizeof(car));
		temp = cars[cnt];
        temp->soundAlert = 0;
        temp->posAtual.latrad = degrees2radians(temp->posAtual.lat);
        temp->posAtual.lonrad = degrees2radians(temp->posAtual.lon);
        for(int i=0; i<polyCorners; i++){
            temp->ativa.cerca[i].latrad = degrees2radians(temp->ativa.cerca[i].lat);
            temp->ativa.cerca[i].lonrad = degrees2radians(temp->ativa.cerca[i].lon);
        }
        temp->cercas[0] = temp->ativa;
    	temp->proximo=(car *)0;
		add(temp);
        cnt++;
    }

    fclose (fp);
    if (line)
        free (line);
	
    while(1){
        updatePos(head);
	    alertCars(head);
        getpass(head);
    }
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
    return 0;
}

void add(car *temp)
{
    if(head==(car *)0)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->proximo=temp;
        tail=temp; 
    } 
}

void alertCars(car *temp){
    for(temp=head; temp!=(car *)0; temp=temp->proximo)
    {
        //printf("\n");
        alert(temp);
    }    
}

void updatePos(car *head){
    char command[60];
    snprintf(command, sizeof(command), "cd  C:\\Users\\Tiago\\Desktop\\Hermes");
    system(command);
    system("python ./DownloadPos.py");
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
    file = fopen ("pos.csv", "r");
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
                if (field2 == 2) cars2[cnt2]->posAtual.lon = atof(sp2);
                if (field2 == 3) cars2[cnt2]->ativa.cerca[0].lat = atof(sp2);
                if (field2 == 4) cars2[cnt2]->ativa.cerca[0].lon = atof(sp2);
                if (field2 == 5) cars2[cnt2]->ativa.cerca[1].lat = atof(sp2);
                if (field2 == 6) cars2[cnt2]->ativa.cerca[1].lon = atof(sp2);						
                if (field2 == 7) cars2[cnt2]->ativa.cerca[2].lat = atof(sp2);
                if (field2 == 8) cars2[cnt2]->ativa.cerca[2].lon = atof(sp2);
                if (field2 == 9) cars2[cnt2]->ativa.cerca[3].lat = atof(sp2);
                if (field2 == 10) cars2[cnt2]->ativa.cerca[3].lon = atof(sp2);
                if (field2 == 11) cars2[cnt2]->ativa.timestamp = atoi(sp2);
                if (field2 == 12) cars2[cnt2]->viagem.on = atoi(sp2);

                *p2 = ','; 
                sp2 = p2 + 1;
                field2++;
            }
            p2++; 
        }
        cars2[cnt2]->viagem.timestamp = atoi(sp2);
        cnt2++;
    }
    fclose (file);
    temp = head;

    int i = 0;
    for(temp=head; temp!=(car *)0; temp=temp->proximo)
    {
        temp->posAtual.lat = cars2[i]->posAtual.lat;
        temp->posAtual.lon = cars2[i]->posAtual.lon;
        temp->posAtual.latrad = degrees2radians(temp->posAtual.lat);
        temp->posAtual.lonrad = degrees2radians(temp->posAtual.lon);
        temp->ativa.timestamp = cars2[i]->ativa.timestamp;
        temp->viagem.on = cars2[i]->viagem.on;
        temp->viagem.timestamp = cars2[i]->viagem.timestamp;
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

void getpass(car *temp){
    char command[60];
    snprintf(command, sizeof(command), "cd  C:\\Users\\Tiago\\Desktop\\Hermes");
    system(command);
    system("python ./DownloadAlert.py");

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
    file = fopen ("alerta.csv", "r");
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
                if (field2 == 1) cars2[cnt2]->senha = strdup(sp2);

                *p2 = ','; 
                sp2 = p2 + 1;
                field2++;
            }
            p2++; 
        }
        cars2[cnt2]->alerta = atoi(sp2);
        cnt2++;
    }
    fclose (file);
    temp = head;

    int i = 0;
    for(temp=head; temp!=(car *)0; temp=temp->proximo)
    {
        if(temp->alerta != cars2[i]->alerta && temp->soundAlert == 1) temp->alerta = cars2[i]->alerta;
        if (strcmp(temp->senha,cars2[i]->senha)!=0) temp->senha = cars2[i]->senha;
        i++;
    }

    if (line2)
        free (line2);


    for(temp=head; temp!=(car *)0; temp=temp->proximo)
    {   
        if(temp->alerta == 1 && strcmp(temp->senha,"correta") == 0){
            temporaryFence(temp);
            temp->soundAlert = 0;
            temp->alerta = 0;
            temp->senha = "aguardando";
            char command[60];
            snprintf(command, sizeof(command), "cd  C:\\Users\\Tiago\\Desktop\\Hermes");
            system(command);
            snprintf(command, sizeof(command), "python ./updatepass.py %s",temp->placa);
            system(command);
        }
    }
}