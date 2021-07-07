#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int tpeso;

typedef struct adja{
    int vertice;
    tpeso peso;
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
    grafo *novo = (grafo*) malloc(sizeof(grafo));
    novo->vertices = n;
    novo->arestas = 0;
    novo->adj = (vertice*) malloc(n * sizeof(vertice));
    for(int i = 0; i < n; i++){
        novo->adj[i].cab = NULL;
    }
return novo;
}

adjacencia* addadjacencia(int v, int peso){
    adjacencia *temp = (adjacencia*) malloc(sizeof(adjacencia));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
return temp; 
}

bool addaresta(grafo *g, int vi, int vf, tpeso p){
    if(!g) return false;
    if((vi < 0) || (vi >= g->vertices)) return false;
    if((vf < 0) || (vf >= g->vertices)) return false;

    adjacencia *novo = addadjacencia(vf, p);
    novo->prox = g->adj[vi].cab;
    g->adj[vi].cab = novo;
    g->arestas++;
return true;  
}

void addndirecionado(grafo *g, int vi, int vf, tpeso p){
    addaresta(g, vi, vf, p);
    addaresta(g, vf, vi, p);
return;
}





void imp(grafo* g){
    if(g){
        printf("Vertices: %d, Arestas: %d\n", g->vertices, g->arestas);
        for(int i = 0; i < g->vertices; i++){
            printf("v(%i): ", g->adj[i].cab->vertice);
            adjacencia *temp = g->adj[i].cab;
            while(temp){
                printf("v%i(%i):%i ", i, temp->vertice, temp->peso);
                temp = temp->prox;
            }
            printf("\n");
        }
    }
return;
}

int main(){
    grafo *g = criagrafo(5);
    addndirecionado(g, 0, 0, 1);
    printf("a\n");
    addndirecionado(g, 2, 4, 1);
    printf("b\n");
    addndirecionado(g, 1, 3, 1);
    printf("c\n");
    addndirecionado(g, 0, 2, 10);
    printf("d\n");

    

    imp(g);
    
return 0;
}
