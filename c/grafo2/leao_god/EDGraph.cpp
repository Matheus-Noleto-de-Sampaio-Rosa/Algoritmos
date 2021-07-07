#include <bits/stdc++.h>

using namespace std;

typedef struct AdjListNode{
    int value;
    struct AdjListNode *next;
} AdjListNode;

typedef struct {
    AdjListNode *head;
} AdjList;

// Utlizar logo um ponteiro de AdjList ao invés de um array normal e preenche-lo depois com os AdjListNode;
typedef struct {
    int vertices;
    AdjList *array;
} Graph;

// Função de adicionar um novo nó na lista de adjacência.
AdjListNode *newAdjListNode(int value) {
    AdjListNode *node = (AdjListNode*) malloc(sizeof (AdjListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

Graph *newGraph(int vertices) {
    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->vertices = vertices;
    g->array = (AdjList*) malloc(vertices * sizeof(AdjList));

    // Preencher todas as cabeças com NULL, indicando que não há nenhuma aresta no momento;
    for(int i = 0; i < vertices; i++) {
        g->array[i].head = NULL; 
    }
    return g;
}

void newEdge(Graph *g, int start, int end) {
    AdjListNode *aln = newAdjListNode(end);
    // Atribuir o primeiro nó da lista para vir depois do novo nó adicionado.
    // Ex: x -> / ficará agora como end -> x -> /.
    aln->next = g->array[start].head;
    g->array[start].head = aln;

    // Como não é um digrafo, é necessário também atribuir o start na lista do end.
    aln = newAdjListNode(start);
    aln->next = g->array[end].head;
    g->array[end].head = aln;
}

void printGraph(Graph *g) {
    for(int i = 0; i < g->vertices; i++) {
        AdjListNode *temp = g->array[i].head;
        printf("%d : ", i);
        while(temp != NULL) {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        printf("/\n");
    }
}

void BFS(Graph *g, int v) {
    // Criar um array que representa os vertices visitados e marcar todos como false
    bool visited[g->vertices];
    for(int i = 0; i < g->vertices; i++) {
        visited[i] = false;
    }
    // Criar uma fila que auxiliará na iteração do grafo.
    queue<int> q;
    // Marcar o vertice recebido como visitado e adiciona-lo na fila.
    visited[v] = true;
    q.push(v);
    // Agoro iterar até que não sobre nenhum vertice
    while(!q.empty()) {
        v = q.front();
        printf("%d ", v);
        q.pop();
        AdjListNode *temp = g->array[v].head;
        while(temp != NULL) {
            if(!visited[temp->value]) {
                visited[temp->value] = true;
                q.push(temp->value);
            }
            temp = temp->next;
        }
    }
}

// void DFS(Graph *g, int v) {
//     // Criar um array que representa os vertices visitados e marcar todos como false
//     bool visited[g->vertices];
//     for(int i = 0; i < g->vertices; i++) {
//         visited[i] = false;
//     }
//     // Criar uma pilha que auxiliará na iteração do grafo.
//     stack<int> s;
//     // Marcar o vertice recebido como visitado e adiciona-lo na pilha.
//     visited[v] = true;
//     s.push(v);
//     // Agoro iterar até que não sobre nenhum vertice
//     while(!s.empty()) {
//         v = s.top();
//         //printf("%d ", v);
//         s.pop();
//         AdjListNode *temp = g->array[v].head;
//         while(temp != NULL) {
//             if(!visited[temp->value]) {
//                 visited[temp->value] = true;
//                 s.push(temp->value);
//             }
//             temp = temp->next;
//         }
//     }
// }

void dfs(Graph *g, int v, bool *visited) {
    visited[v] = true;
    AdjListNode *temp = g->array[v].head;
    while(temp != NULL) {
        if(!visited[temp->value]) {
            dfs(g, temp->value, visited);
            printf("%d", temp->value);
        }
        temp = temp->next;
    }
}

void DFS(Graph *g) {
    bool visited[g->vertices];
    for(int i = 0; i < g->vertices; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < g->vertices; i++) {
        if(!visited[i]) {
            dfs(g, i, visited);
            printf("%d", i);
        }
    }
}

int main() {
    Graph *graph = newGraph(7);
    newEdge(graph, 0, 5);
    newEdge(graph, 0, 3);
    newEdge(graph, 0, 4);
    newEdge(graph, 3, 2);
    newEdge(graph, 4, 2);
    newEdge(graph, 2, 6);
    newEdge(graph, 3, 1);
    newEdge(graph, 2, 1);

    DFS(graph);
    free(graph);
    return 0;
}