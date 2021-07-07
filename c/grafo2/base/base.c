#include <stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;
typedef int bool;

typedef struct No{
    int vertice;
    int peso;
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

no* add_no(int vf, int peso){
    no *novo = (no *) malloc(sizeof(no));

    novo->vertice = vf;
    novo->peso = peso;
    novo->prox = NULL;

    return novo;
}

bool add_aresta(grafo *g, int vi, int vf, int p){
    if(!g) return false;
    if((vf < 0) || (vf > g->n_vertices)) return false;
    if((vi < 0) || (vi > g->n_vertices)) return false;

    no *novo = add_no(vf, p);
    novo->prox = g->nos[vi].cab;
    g->nos[vi].cab = novo;

    return true;
}

void add_dir(grafo *g, int vi, int vf, int p){
    add_aresta(g, vi, vf, p);
    g->arestas++;
}

void add_n_dir(grafo *g, int vi, int vf, int p){
    add_aresta(g, vi, vf, p);
    add_aresta(g, vf, vi, p);
    g->arestas++;
}

void remno(grafo *g, int vi){
    if(g){
        for(int i = 0; i < g->n_vertices; i++){
            while(g->nos[i].cab){
                printf("B\n");
                if(temp->vertice == vi){
                    no* temp = g->nos[i].cab;
                    g->nos[i].cab = g->nos[i].cab->prox;
                    free(temp);
                }
                temp = temp->prox;
            }
        }
    }
}

void imp(grafo *g){
    if(g){
        printf("Vertices: %i, Arestas: %i\n", g->n_vertices, g->arestas);
        for(int i = 0; i < g->n_vertices; i++){
            no* temp = g->nos[i].cab;
            while(temp){
                printf("v%i(%i) ", temp->vertice, temp->peso);
                temp = temp->prox;
            }
            printf("\n");
        }
    }
}

int main(){
    grafo *g = criagrafo(5);
    printf("%d %d\n", g->n_vertices, g->arestas);
    
    add_aresta(g, 2, 0, 2);
    add_aresta(g, 1, 3, 1);
    add_aresta(g, 3, 4, 1);
    
    imp(g);

    remno(g, 0);

    imp(g);

    free(g);
    return 0;
}