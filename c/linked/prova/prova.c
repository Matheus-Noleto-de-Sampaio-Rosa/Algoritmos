#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaracao da struct lista.
struct lista{
    int valor;
    struct lista* prox;
    struct lista* ant;
};

//funcao que auxilia trocar dois ponteiros de espaco de memoria
void trocalista(struct lista** x, struct lista** y){
    struct lista* temp = (struct lista*) malloc(sizeof(struct lista));
    temp = *x;
    *x = *y;
    *y = *x;
}

//funcao de busca de um valor escolhido
struct lista* busca(struct lista* v, int val){
    if(v->prox == NULL) return NULL;
    else if(v->valor == val) return v;
    else busca(v->prox, val);
}

//funcao que adiciona valores ao inicio da lista
void add(struct lista** v, int val){
    if(*v == NULL){
        (*v)->valor = val;
        (*v)->prox = NULL;
        (*v)->ant = NULL;
    }else{
        struct lista* novo = (struct lista*) malloc(sizeof(struct lista));
        novo->valor = val;
        novo->prox = *v;
        novo->ant = NULL;
        (*v)->ant = novo;
        trocalista(&(*v), &novo);
    }
}

//funcao de remocao do item selecionado na lista
int rem(struct lista* v, int val){
    struct lista* temp = (struct lista*) malloc(sizeof(struct lista));    
    temp = busca(v , val);
    if(temp == NULL){
        printf("Nao encontrado! Insira outro numero\n");
        return 0;
    } 
    temp->prox->ant = temp->ant;
    temp->ant->prox = temp->prox;
free(temp);
}

//funcao de printar normalmente
void impnormal(struct lista* v){
    while(v->prox!=NULL){
        printf("%i ", v->valor);
        v = v->prox;
    }
    printf("\n");
}

//funcao de printar pelo inverso
void impinverso(struct lista* v){
    while(v->prox->prox != NULL){
        v = v->prox;
    }
    while(v != NULL){
        printf("%i ", v->valor);
        v = v->ant;
    }
    printf("\n");
}

int main(){
    struct lista* primeiro = (struct lista*) malloc(sizeof(struct lista));
    primeiro->ant = NULL;
    printf("passou\n");
    add(&primeiro, 10);
    impnormal(primeiro);
    impinverso(primeiro);
    add(&primeiro, 20);
    impnormal(primeiro);
    impinverso(primeiro);
    add(&primeiro, 30);
    impnormal(primeiro);
    impinverso(primeiro);
    add(&primeiro, 70);
    impnormal(primeiro);
    impinverso(primeiro);
    rem(primeiro, 20);
    impnormal(primeiro);
    impinverso(primeiro);
    rem(primeiro, 90);
free(primeiro);
return 0;
}

/*

complexidade da adicao de elementos:
    O(1)
Complexidade de remocao de um valor:
    O(n)
Complexidade de busca de um elemento:
    O(n)
Complexidade de impressao normal:
    O(n)
Complexidade de impressao inversa:
    O(2n)

*/