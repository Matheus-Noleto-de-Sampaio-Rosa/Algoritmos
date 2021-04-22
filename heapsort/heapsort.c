#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

void swp(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxheap(int* v, int tamanho, int i){
    int l = left(i);
    int r = right(i);
    int maior = i;

    if(l < tamanho && v[l] > v[maior]) maior = l;
    if(r < tamanho && v[r] > v[maior]) maior = r;

    if(maior != i){
        swp(&v[i], &v[maior]);
        maxheap(v, tamanho, maior);
    }
}

void bheap(int* v, int tamanho){
    for(int i = tamanho/2 - 1; i >= 0; i--)
        maxheap(v, tamanho, i);
}

void sortify(int* v, int tamanho){
    bheap(v, tamanho);
    for(int i = tamanho - 1; i > 0; i--){
        swp(&v[0], &v[i]);
        maxheap(v, i, 0);
    }
}


int main(){
    srand(time(NULL));
    int* v = malloc(5*sizeof(int));
    for(int i = 0; i < 5; i++){
        *(v+i) = rand()%101;
        printf("%i ", *(v+i));
    }

    printf("\n");

    sortify(v, 5);

    for(int i = 0; i < 5; i++)
        printf("%i ", *(v+i));

    printf("\n");
return 0;
}