#include <stdio.h>
#include <stdlib.h>

typedef struct circulo
{
    float x, y, r;
    float d;
}circulo;

float areaCirculo(circulo *c){
    float p = 3.14;
    float area = 3.14 * (c->r * c->r);
    return area;
}

void coordenadas(circulo *c){
    printf("(%.2f)(%.2f) : ", c->x, c->y);
    printf("Raio: %.2f : ", c->r);
    printf("Area: %.2f\n", areaCirculo(c));
}




