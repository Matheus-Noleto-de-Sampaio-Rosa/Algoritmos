#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscar(int* lista, int tamanho, int l, int valor){
    if(lista[l] == valor){
        return l;
    }else{
        if(l >= tamanho) return -1;
        else buscar(lista, tamanho, ++l, valor);
    }
}

void adicionar(int* lista, int* tamanho, int valor){
    lista = realloc(lista, (*tamanho+1) * sizeof(int));
    lista[*tamanho] = valor;
    ++*tamanho;
}

int remover(int* lista, int* tamanho, int valor){
   int x = buscar(lista, *tamanho, 0, valor);
   for(int i = x; i < *tamanho; i++)
        lista[i] = lista[i+1];
   --*tamanho;
   lista = realloc(lista, (*tamanho) * sizeof(int));
}

void imp(int* v, int tamanho){
    for(int i = 0; i < tamanho; i++)
        printf("%i ", v[i]);
    printf("\n");
}

int main(){
    srand(time(NULL));
    int tamanho = 20;
    int* v = (int*) malloc(tamanho*sizeof(int));
    for(int i = 0; i < 20; i++){
        *(v+i) = rand()%101;
    }

    imp(v, tamanho);

    adicionar(v, &tamanho, 900);

    imp(v, tamanho);

    remover(v, &tamanho, 900);

    imp(v, tamanho);
}