#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int valor;
    struct lista* prox;
}lista;

void add(int* v, int i){
    if(v->prox == NULL){
        lista* novo = (lista*) malloc(sizeof(lista));
        novo->valor = i;
        novo->prox = NULL;
    }else{
        add(v->prox, i);
    }
}