### Ideia geral

    imagine que um ponteiro é um apartamento.
    Um ponteiro que aponta para um só valor é uma casa simples.
    Um ponteiro que aponta para um vetor é um apartamento, seus valores estão alocados um após o outro
    
    > maneira de acesso dado por v[x] ou *(v+x)
    
    maneira de alocar um vetor em um ponteiro
    
    ```c
    int* v = (int*) malloc(tamanho*sizeof(int));
    ```
    já que um está do lado do outro se usar free em um valor espécifico vai dar errado.
    
