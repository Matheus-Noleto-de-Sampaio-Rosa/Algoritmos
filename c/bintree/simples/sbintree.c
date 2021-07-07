#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no{
    int valor;
    struct no* esq;
    struct no* dir;
};

struct no* add(struct no* pai, int valor){
    struct no* novo = malloc(sizeof(struct no));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->valor = valor;
    return novo;
}

void imp(struct no* raiz){
    if(raiz == NULL) return;
    else{
        imp(raiz->esq);
        printf("%i ", raiz->valor);
        imp(raiz->dir);
    }
}

int main(){
    struct no* r = add(r, 10);
    r->esq = add(r, 5);
    r->esq->esq = add(r->esq, 2);
    r->esq->dir = add(r->esq, 3);
    r->dir = add(r->dir, 15);
    r->dir->esq = add(r->dir, 12);
    r->dir->dir = add(r->dir, 18);
    imp(r);
    printf("\n");
free(r); 
return 0;
}