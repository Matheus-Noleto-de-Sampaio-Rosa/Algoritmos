#include <stdio.h>

void merge(int *v, int tamanho){
   int il = tamanho/2, ir = tamanho - tamanho/2;
   int left[il], right[ir];
   if(tamanho > 1){
        for(int e = 0; e < il; e++)
            left[e] = *(v+e);
        for(int d = 0; d < ir; d++)
            right[d] = *(v+d+il);
    
        merge(left, il);
        merge(right, ir);

        int i = 0, j = 0, k = 0;

        while(i < il && j < ir){
            if(left[i] > right[j]){
                *(v+k) = right[j];
                j++;
            }else{
                *(v+k) = left[i];
                i++;
            }
            k++;
        }

        while(i < il){
            *(v+k) = left[i];
            i++;
            k++;
        }

        while(j < ir){
            *(v+k) = right[j];
            j++;
            k++;
        }
   }

}

int main(){
    int v[10] = {10, 3, 2, 8, 4, 5, 7, 1, 6, 9};
    merge(v, 10);
    for(int i = 0; i < 10; i++)
        printf("%i ", v[i]);
    printf("\n");

return 0;
}