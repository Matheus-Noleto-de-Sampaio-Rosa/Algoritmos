#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct no{
    int valor;
    struct no* esq;
    struct no* dir;
};

struct no* new(int valor){
    struct no* new = (struct no*) malloc(sizeof(struct no));
    new->valor = valor;
    new->esq = new->dir = NULL;
    return new;
}

struct no* busca(struct no* raiz, int valor){
    if(raiz->valor == valor) return raiz;
    else if(raiz->valor < valor) busca(raiz->dir, valor);
    else if(raiz->valor > valor) busca(raiz->esq, valor);
    else if(raiz == NULL) return NULL;
}

struct no* rem(struct no* n, int valor){
    if(n == NULL) return NULL;
    else{
        if(n->valor == valor){
            struct no* temp = n;
            if(n->esq != NULL) n = n->esq;
            else n = n->dir;
            free(temp);
            return n;
        }else{
            if(n->valor < valor) n->dir = rem(n->dir, valor);
            else n->esq = rem(n->esq, valor);
            return n;
        }
    }
}

struct no* add(struct no* raiz, int valor){
    if(raiz == NULL){
        return new(valor);
    }if(valor > raiz->valor){ 
        raiz->dir = add(raiz->dir, valor);
    }else if(valor < raiz->valor){
        raiz->esq = add(raiz->esq, valor);
    }
    
    return raiz;
}

void imp(struct no* raiz){
    if(raiz != NULL){
        imp(raiz->esq);
        printf("%i ", raiz->valor);
        imp(raiz->dir);
    }
}

int main(){
    srand(time(NULL));
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct no* r = NULL;
    for(int i = 0; i < 10; i++){
        r = add(r, v[i]);
    }
    imp(r);
    printf("\n");
    printf("%i\n", busca(r, 2)->valor);
    rem(r, 5);
    imp(r);
    printf("\n");
free(r);
return 0;
}