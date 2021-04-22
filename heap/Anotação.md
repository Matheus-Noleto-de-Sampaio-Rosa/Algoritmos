# Ideia central.

  A raiz do problema seria a sacada da recursão. Para a recursão acontecer diretio primeiro é necessário saber como chegar em cada nó. 
  
```md
          0
         / \
        1   2
      /  \  /
     3   4  5
```

  Os nós da esquerda podem ser representados como 2*i+1 e os da direita como 2*i+2. Onde i será a posição atual. E para voltar ao nó pai basta usar
  (i-1)/2.
  
 ## Para criar um heap máxima.
 
 É fácil pensar em separar a heap em "mini heaps" de maneira que uma heap fique na sua menor unidade a qual é uma árvore binária de 3 unidades.
 agora basta pensar na condição que escolher sendo max ou uma min heap. Mas no fim das contas no código vai mudar alguns simbolos apenas.
 
 ## Ideia final
 
 Tendo em mente a mener unidade da heap basta pensar. Se o nó da esquerda for maior que o pai então você deixa guardado a posição do no nó da esquerda(guarde o valor).
 Caso contrario o pai será ainda o maior(guarde o valor da casa do pai).
 Agora compare o nó da direita e o nó com o maior valor caso o da direita seja o maior guarde seu valor.
 Se o maior for diferente do pai troque o valor do pai com o do maior e chame a funcao a partir do nó que foi guardado como maior.
 
 A partir do momento que chama a função na ultima linha está definido o código recursivo.
 Contudo precisa ainda executar isso em cada a partir do meio da altura da heap int(n/2) onde n é o tamanho do vetor que armazenará os valores e irá até o nó 0.
