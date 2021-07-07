#include <stdio.h>
#include <stdlib.h>
#define false 0;
#define true 1;

typedef int bool;

typedef struct queue{
    int valor;
    struct queue *prox;
}kyu;

typedef struct No{
    int vertice;
    bool v;
    struct No *prox;
}no;

typedef struct vert{
    no *cab;
}vertice;

typedef struct graf{
    int n_vertices;
    int n_arestas;
    vertice *nos;
}grafo;

kyu *cria_fila(int v){
   kyu *novo = (kyu *) malloc(sizeof(kyu));

   novo->valor =  v;
   novo->prox = NULL;
   
   return novo;
}

void push(kyu* k, int v){
    struct *kyu novo = k;
    
    kyu->prox = v;
    v = kyu;
}

grafo *cria_grafo(int n){
    grafo *g = (grafo *) malloc(sizeof(grafo));
    
    g->n_vertices = n;
    g->n_arestas = 0;
    g->nos = (vertice *) malloc(sizeof(n * sizeof(vertice)));
    for(int i = 0; i < g->n_vertices; i++){
        g->nos[i].cab = NULL;
    }

    return g;
}

no *cria_no(int vf){
    no* n = (no *) malloc(sizeof(no));

    no->vertice = vf;
    no->v = false;
    no->prox = NULL;

    return n;
}

void *cria_aresta(grafo *g, int vi, int vf){
    if(!g) return;
    if((vf < 0) || (vf >= g->n_vertices)) return;
    if((vi < 0) || (vi >= g->n_vertices)) return;

    no* temp = cria_no(vf);
    temp->prox = g->nos[vi].cab;
    g->nos[vi].cab = temp;
}

void add_dir(grafo *g, int vi, int vf){
    cria_aresta(g, vi, vf);
    g->n_arestas++;
}

void add_n_dir(grafo *g, int vi, int vf){
    cria_aresta(g, vi, vf);
    cria_aresta(g, vf, vi);
    g->n_arestas++;
}

void BFS(no *g, int i, bool *visitado, int g){
    kyu *visit = cria_fila;
    for(int j = 0; j < g; j++){
        push(visit, visited[j]);
    }
    while(g)
}

void bfs(grafo *g){
    bool visitado[g->n_vertices];
    for(int i = 0 ; i < g->n_vertices; i++){
        visitado[i] = false;
    }
    for(int i = 0; i < g->n_vertices; i++){
       no *temp = g->nos[i].cab;
       while(temp){
           if(!visitado[i]);
            BFS(temp, i, visitado);
            temp = temp->prox;
            printf("%i\n", i); 
        }  
       printf("\n");
    }
    printf("\n");
}