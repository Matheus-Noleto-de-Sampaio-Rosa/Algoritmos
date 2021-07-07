#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista{
    int valor;
    struct lista* ant;
    struct lista* prox;
};

struct lista* buscartail(struct lista* head){
    if(head->prox == NULL){
        return head;
    }else{
        buscartail(head->prox);
    }
}

struct lista* buscavalor(struct lista* head, int val){
    while(head->valor != val){
        head = head->prox;
    }
    if(head->valor == val) return head;
}

//primeiro
void add(struct lista** head, int val){
    struct lista* novo = (struct lista*) malloc(sizeof(struct lista));
    novo->valor = val;
    novo->prox = NULL;
    novo->ant = *head;
}

//segundo
void rem(struct lista* head, int val){
    struct lista* temp = (struct lista*) malloc(sizeof(struct lista));
    temp = buscavalor(head, val);
    temp->prox->ant = temp->ant;
    temp->ant->prox = temp->prox;
    free(temp);
}

//quarto
void impnormal(struct lista* head){
    while(head != NULL){
        head = head->ant;
    }
    while(head!=NULL){
        printf("%i", head->valor);
        head->prox;
    }
    printf("\n");
}
//quinto
void impinvertido(struct lista* head){
    struct lista* x = (struct lista*) malloc(sizeof(struct lista));
    x = buscartail(head);
    while(x != NULL){
        printf("%i ", x->valor);
        x = x->ant;
    }
    printf("\n");
    free(x);
}

int main(){
    srand(time(NULL));
    struct lista* primeiro = NULL;
    int x;
    scanf("%i", &x);
    add(&primeiro, x);
    impinvertido(primeiro);
    impnormal(primeiro);
    add(&primeiro, 12);
    impinvertido(primeiro);
    impnormal(primeiro);
free(primeiro);
return 0;
}