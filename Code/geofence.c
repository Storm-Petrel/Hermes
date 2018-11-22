
#include <time.h>
#include "position.c"

#define polyCorners 4

typedef struct geofence{
    char *nome;
    position cerca[polyCorners];
    time_t timestamp;
}geofence;