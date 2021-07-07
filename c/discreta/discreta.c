#include <stdio.h>

int main(){
    int v[6] = {1, 3, 5, 9, 11, 13};
    int cont = 0;
    int x = 0;
    int t = 5;
    int seg = 5;
    while(cont < 6 && x < 40){
        seg= seg * t;
        seg = seg%14;
        for(int i = 0; i < 6; i++){
            if(seg == v[i]){
                printf("+1 %i %i\n", seg, v[i]);
                v[i] = -1;
                cont++;
            }
        }
        x++;
    }
    if(cont == 6) printf("gerador\n");
    else printf("Tenta outro ae\n");
return 0;
}