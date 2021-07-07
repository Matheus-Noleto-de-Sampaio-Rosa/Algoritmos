#include <stdio.h>
#include <stdlib.h>

typedef struct fi{
    int valor;
    struct fi *prox;
}fila;

fila *push(fila *q, int v){
    fila *temp = (fila *) malloc(sizeof(fila));
    temp->valor = v;
    temp->prox = q;
    q = temp;

    return q;
}

fila *retira_n_eficiente(fila* q){
    if(q->prox != NULL) q->prox = retira_n_eficiente(q->prox);
    else return NULL;
}

fila *retira_eficiente(fila *q){
    while(q->prox->prox != NULL){
        q = q->prox;
    }
    free(q->prox);
    q->prox = NULL;
    return q;
}

void imp_eficiente(fila *q){
    while(q){
        printf("%i ", q->valor);
        q = q->prox;
    }
    printf("\n");
    return;   
}

void imp_n_eficiente(fila *q){
    if(q){
        printf("%i ", q->valor);
        imp_n_eficiente(q->prox);
    }
    else{
        printf("\n");
        return;
    }
}

int main(){
    fila *q = push(q, 3);
    q = push(q, 19);
    q = push(q, 21);
    retira_eficiente(q);
    imp_eficiente(q);
    free(q);
    return 0;
}