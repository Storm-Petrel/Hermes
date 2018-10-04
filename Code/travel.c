#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct viagem{
    bool on;
    time_t timestamp;
}viagem;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}