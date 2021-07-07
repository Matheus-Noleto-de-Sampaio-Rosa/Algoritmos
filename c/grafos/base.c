#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int tipopeso;

typedef struct adja{
    int vertice;
    tipopeso peso;
    struct adja *prox;
}adjacencia;

typedef struct vert{
    adjacencia *cab;
}vertice;

typedef struct graf{
    int vertices;
    int arestas;
    vertice *adj;
}grafo;

grafo* criagrafo(int n){
    grafo *g = (grafo *) malloc(sizeof(grafo*));
    g->vertices = n;
    g->arestas = 0;
    g->adj = (vertice*) malloc(sizeof(n * sizeof(grafo)));
    for(int i = 0; i < n; i++){
        g->adj[i].cab = NULL;
    }
return g;
}

int main(){
    grafo *g = criagrafo(5);
    printf("PFT\n");
return 0;
}