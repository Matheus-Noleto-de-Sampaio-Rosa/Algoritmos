#include <stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;
typedef int bool;

typedef struct No{
    int vertice;
    struct No *prox;
}no;

typedef struct vert{
    no* cab;
}vertice;

typedef struct graf{
    int n_vertices;
    int arestas;
    vertice *nos;
}grafo;

grafo *criagrafo(int n){
    grafo *g = (grafo *) malloc(sizeof(grafo));
    
    g->n_vertices = n;
    g->arestas = 0;
    g->nos = (vertice *) malloc(n * sizeof(vertice));
    for(int i = 0; i < n; i++){
        g->nos[i].cab = NULL;
    }
    
    return g;
}

no* add_no(int vf){
    no *novo = (no *) malloc(sizeof(no));

    novo->vertice = vf;
    novo->prox = NULL;

    return novo;
}

bool add_aresta(grafo *g, int vi, int vf){
    if(!g) return false;
    if((vf < 0) || (vf > g->n_vertices)) return false;
    if((vi < 0) || (vi > g->n_vertices)) return false;

    no *novo = add_no(vf);
    novo->prox = g->nos[vi].cab;
    g->nos[vi].cab = novo;

    return true;
}

void add_dir(grafo *g, int vi, int vf){
    add_aresta(g, vi, vf);
    g->arestas++;
}

void add_n_dir(grafo *g, int vi, int vf){
    add_aresta(g, vi, vf);
    add_aresta(g, vf, vi);
    g->arestas++;
}

void dfs(grafo *g, int i, bool *visited){
    visited[i] = true;
    no* temp = g->nos[i].cab;
    while(temp){
        if(!visited[temp->vertice]){
            dfs(g, temp->vertice, visited);
            printf("%d ", temp->vertice);
        }
        temp = temp->prox;
    }
}

void DFS(grafo* g){
    bool visited[g->n_vertices];
    for(int i = 0; i < g->n_vertices; i++){
        visited[i] = false;
    }
    for(int i = 0; i < g->n_vertices; i++){
        dfs(g, i, visited);
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < g->n_vertices; i++){
        printf("%i", visited[i]);
    }
    printf("\n");
}

void imp(grafo *g){
    if(g){
        printf("Vertices: %i, Arestas: %i\n", g->n_vertices, g->arestas);
        for(int i = 0; i < g->n_vertices; i++){
            no* temp = g->nos[i].cab;
            while(temp){
                printf("v(%i) ", temp->vertice);
                temp = temp->prox;
            }
            printf("\n");
        }
    }
}

int main(){
    grafo *g = criagrafo(5);
    printf("%d %d\n", g->n_vertices, g->arestas);
    
    add_n_dir(g, 2, 0);
    add_n_dir(g, 1, 3);
    add_n_dir(g, 3, 4);
    
    imp(g);

    DFS(g);

    free(g);
    return 0;
}