#include <stdio.h>
#include <stdlib.h>

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

int parent(int i){
    return (i-1)/2;
}

void troca(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void max_heapify(int* v, int tamanho, int i){
    int l = left(i);
    int r = right(i);
    int maior;

    if(l < tamanho && v[l] > v[i]) maior = l;
    else maior = i;

    if(r < tamanho && v[r] > v[maior]) maior = r;

    if(maior != i){
        troca(&v[i], &v[maior]);
        max_heapify(v, tamanho, maior);
    }
}

void heapify(int* v, int tamanho){
    int barra = tamanho - tamanho/2;
    for(int i = barra; i > -1; i--)
        max_heapify(v, tamanho, i);
}

void heapsort(int* v, int tamanho){
    heapify(v, tamanho);
    for(int i = tamanho-1; i > -1; i--){
        troca(&v[0], &v[i]);
        max_heapify(v, i, 0);
    }
}

int main(){
    int v[10];
    for(int i = 0; i < 10; i++)
        v[i] = i + 1;

    heapsort(v, 10);

    for(int i = 0; i < 10; i++)
        printf("%i ", v[i]);

    printf("\n");
return 0;
}
