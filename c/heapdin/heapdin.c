#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no{
    int valor;
    struct no* esq;
    struct no* dir;
};

struct no* add(int val){
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    novo->valor = val;
    novo->esq = NULL;
    novo->dir = NULL;
    return (novo);
}

int main(){
    struct no* primeiro = add(10);
    printf("%i\n", primeiro->valor);
    primeiro->esq = add(20);
    printf("%i\n", primeiro->esq->valor);
    primeiro->dir = add(30);
    printf("%i\n", primeiro->dir->valor);
free(primeiro);
return 0;
}