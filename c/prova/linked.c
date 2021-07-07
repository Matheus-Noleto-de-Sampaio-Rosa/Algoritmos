#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista{
    int valor;
    struct lista* prox;
};

struct lista* buscatail(struct lista* v){
    if(v->prox == NULL) return v;
    else buscatail(v->prox);
}

void add(struct lista* v, int val){
    struct lista* novo = (struct lista*) malloc(sizeof(struct lista));
    v = buscatail(v);
    novo->valor = val;
    novo->prox = NULL;
    v->prox = novo;
}

struct lista* rem(struct lista** v){
    (*v) = (*v)->prox;
}

void imp(struct lista* v){
    while(v != NULL){
        printf("%i ", v->valor);
        v = v->prox;
    }
    printf("\n");
}

int main(){
    struct lista* primeiro = (struct lista*) malloc(sizeof(struct lista));
    primeiro->valor = 10;
    add(primeiro, 20);
    add(primeiro, 30);
    imp(primeiro);
    rem(&primeiro);
    imp(primeiro);
    rem(&primeiro);
    imp(primeiro);
    add(primeiro, 10);
    imp(primeiro);
free(primeiro);
}