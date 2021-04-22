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
    *y =  temp;
}

void minheap(int* v, int tamanho, int i){
    int l = left(i);
    int r = right(i);
    int menor;

    if(l < tamanho && v[l] < v[i]) menor = l;
    else menor = i;
    if(r < tamanho && v[r] < v[menor]) menor = r;

    if(menor != i){
        swap(&v[i], &v[menor]);
        minheap(v, tamanho, menor);
    }
}

void heapify(int* v, int tamanho){
    for(int i = tamanho/2; i > -1; i--)
        minheap(v, tamanho, i);
}


int main(){
    srand(time(NULL));
    int* x = malloc(5*sizeof(int));
    for(int i = 0; i < 5; i++)
        *(x+i) = rand()%101;
    for(int i = 0; i < 5; i++)
        printf("%i ", *(x+i));

    printf("\n");

    heapify(x, 5);

    for(int i = 0; i < 5; i++)
        printf("%i ", *(x+i));

    printf("\n");
return 0;
}