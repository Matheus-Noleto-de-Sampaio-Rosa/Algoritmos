#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int vertice; //id
    int tamAdj; //quantas ligacoes tem esse no
    struct No *adj; //lista de adjacencia com outros vertices
} no;

int main() {
    int num_vertices;
    printf("Digite o numero de vertices: ");
    scanf("%d", &num_vertices);

    no *vertices = (no *) malloc(num_vertices * sizeof(no));
    vertices->tamAdj = num_vertices;

    for(int i = 0, ligacoes; i < num_vertices; i++) {
        vertices[i].vertice = i;
        printf("\n");
        printf("Quantas ligacoes tem o vertice %d? ", i);
        scanf("%d", &ligacoes); //numero de ligacoes
        vertices[i].adj = (struct No *) malloc(ligacoes * sizeof(struct No));
        vertices[i].tamAdj = ligacoes; //vertice i tem esse numero de ligacoes
        printf("\nDigite as ligacoes abaixo:\n");
        for(int j = 0, a; j < ligacoes; j++) {
            scanf("%d", &a); //vertice ligado ao vertice "i"
            vertices[i].adj[j].adj = NULL; //n tem uma lista de adjacencia dentro da lista de adjacencia de um vértice
            vertices[i].adj[j].vertice = a; //adiciona o vertice que está ligado a ele
        }
    }

    for(int i = 0; i < num_vertices; i++) {
        printf("Vertice: %d\n", vertices[i].vertice);
        printf("Ligacoes: ");
        for(int j = 0; j < vertices[i].tamAdj; j++) {
            printf("%d ", vertices[i].adj[j].vertice);
        }
        printf("\n");
        
    }

    return 0;
}