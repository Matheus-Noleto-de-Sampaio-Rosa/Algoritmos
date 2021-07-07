#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxheap(int* v, int tamanho, int ponto){
    int l = left(ponto), r = right(ponto), maior;
    if(l < tamanho && v[l] > v[ponto]) maior = l;
    else maior = ponto;

    if(r < tamanho && v[r] > v[maior]) maior = r;

    if(maior != ponto){
        swap(&v[ponto], &v[maior]);
        maxheap(v, tamanho, maior);
    }
}

void heapify(int* v, int tamanho){
    int barra = tamanho - tamanho/2;
    for(int i = barra; i > -1; i--){
        maxheap(v, tamanho, i);
    }
}

void imp(int* v, int tamanho){
    for(int i = 0; i < tamanho; i++)
        printf("%i ", v[i]);
    printf("\n");
}

void def(int* v, int tamanho){
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++)
        v[i] = rand()%101;
}

int main(){
    int tamanho = 5;
    int* v = (int*) malloc(tamanho*sizeof(int));
    def(v, tamanho);
    imp(v, tamanho);
    heapify(v, tamanho);
    imp(v, tamanho);
free(v);
return 0;
}