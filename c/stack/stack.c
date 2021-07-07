#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int valor;
    struct list *prox;
}lista;

lista *push(lista *l, int v){
    lista *temp = (lista *) malloc(sizeof(lista));
    temp->valor = v;
    temp->prox = l;
    l = temp;

    return temp;
}

lista *pop(lista *l){
    lista *temp = l->prox;
    free(l);

    return temp;
}

void imp(lista *l){
    while(l){
        printf("%i ", l->valor);
        l = l->prox;
    }
    printf("\n");
}

int main(){
    lista *l = push(l, 5);
    l = push(l, 10);
    l = push(l, 69);
    l = push(l, 3102);
    l = pop(l);
    l = pop(l);
    imp(l);
    free(l);
    return 0;
}