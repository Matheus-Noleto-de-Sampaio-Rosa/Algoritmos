#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quick(int* v, int l, int r){
    if(l<r){
        int pivot = v[r];
        int i = l - 1;
        for(int j = l; j <= r; j++){
            if(v[j] < pivot){
            i++;
            swap(&v[i], &v[j]);
         }
        }
        i++;
        swap(&v[i], &v[r]);
        quick(v, l, i-1);
        quick(v, i+1, r);
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
    int tam = 10;
    int* v = (int*) malloc(tam*sizeof(int));
    def(v, tam);
    imp(v, tam);
    quick(v, 0, 9);
    imp(v, tam);
free(v);
return 0;
}
                   