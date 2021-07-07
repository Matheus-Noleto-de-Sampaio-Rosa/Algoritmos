#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* v, int tamanho){
if(tamanho > 1){
    int te = tamanho/2, td = tamanho-tamanho/2;
    int ve[te], vd[td];
    
    for(int i = 0; i < te; i++)
        ve[i] = v[i];
    
    for(int j = 0; j < td; j++)
        vd[j] = v[te+j];
    
    merge(ve, te);
    merge(vd, td);

    int e = 0, d = 0, k = 0;

    while(e < te && d < td){
        if(ve[e]<= vd[d]){
            v[k] = ve[e];
            e++;
            k++;
        }else{
            v[k] = vd[d];
            d++;
            k++;
        }
    }

    while(e < te){
        v[k] = ve[e];
        e++;
        k++;
    }

    while(d < td){
        v[k] = vd[d];
        d++;
        k++;
    }
}
}

void imp(int* v, int tamanho){
    for(int i = 0; i < tamanho; i++)
        printf("%i ", *(v+i));
    printf("\n");
}

int main(){
    srand(time(NULL));
    int tam = 10;
    int* v = (int*) malloc(tam*sizeof(int));

    for(int i = 0; i < tam; i++)
        *(v+i) = rand()%101;
    imp(v, tam);
    merge(v, tam);
    imp(v, tam);
    free(v);
return 0;
}

5
2 3
1 1 1 2
     1  1