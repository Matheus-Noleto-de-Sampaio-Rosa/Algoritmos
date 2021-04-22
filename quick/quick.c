#include <stdio.h>

void troca(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int quick(int v[], int tamanho){
    int m = tamanho/2;
    if(tamanho>1){    
        int i = 0;
        int j = tamanho - 1;

        while(i < m || j > m){
            if(v[i] > v[m]){
                troca(&v[i], &v[m]);
                i = 0;
            }else if(v[j] < v[m]){
                troca(&v[j], &v[m]);
                j = tamanho - 1 ;
         }else{
                i++;
                j--;
            }
        }
    }
return m-1;
}

void part(int v[], int esquerda, int direita, int tamanho){
    if(tamanho > 2){
        int il = tamanho/2, ir = tamanho - tamanho/2;
        int p = quick(v, tamanho);
        part(v, esquerda, p, il);
        part(v, p+1, direita, ir);
    }
}

int main(){
    int v[10] = {9, 10, 2, 4, 3, 1, 8, 6, 5, 7};
    part(v, 0, 9, 10);
    for(int i = 0; i < 10; i++)
        printf("%i ", v[i]);
    printf("\n");
}