# Correção da Prova: Estruturas de Dados e Algoritmos

**Data:** 09/12/2025  
**Assunto:** Listas, Pilhas, Filas e Árvores Binárias  

---

## 1. Estruturas de Dados Lineares (1,5 pontos)
**Gabarito:** V - V - F - V 

**(V)** A remoção de um elemento no início de uma lista simplesmente encadeada ocorre em tempo O(1), desde que se tenha acesso à cabeça da lista. 
**(V)** Filas e pilhas são casos particulares de listas lineares, pois restringem o ponto de inserção e remoção. 
**(F)** Em uma pilha, a operação Desempilha remove o elemento da base da estrutura. 
    * *Correção:* Em uma pilha (*Stack*), a remoção ocorre no topo, não na base.
**(V)** Uma fila segue a política FIFO: o primeiro elemento a entrar é o primeiro a sair. 

---

## 2. Lista Simplesmente Encadeada sem Descritor (1,5 pontos)
**Gabarito:** V - F - F - V - V 

**(V)** A operação de inserção no início de L pode ser feita em tempo constante O(1). 
**(F)** Para acessar o último elemento de L, é necessário apenas um passo, independentemente do tamanho da lista. 
    * *Correção:* Sem um descritor (ponteiro para o fim), é necessário percorrer a lista inteira, o que custa O(n).
**(F)** A remoção de um elemento no meio da lista pode ser feita sem conhecer o nó anterior. 
    * *Correção:* Em listas simplesmente encadeadas, é preciso ter acesso ao nó anterior para refazer os encadeamentos.
**(V)** Para inserir um elemento no final de L, normalmente é preciso percorrer toda a lista até encontrar o último nó. 
**(V)** A busca sequencial em L apresenta complexidade O(n) no pior caso. 

---

## 3. Árvore Binária de Busca - ABB (1,5 pontos)
**Gabarito:** V - F - V - F 

**(V)** Em uma ABB, a busca por um valor segue pela subárvore esquerda quando o valor procurado é menor que a chave do nó atual. 
**(F)** [O maior/menor] valor de ABB encontra-se sempre no nó raiz. 
    * *Nota:* O texto original está parcialmente cortado, mas a afirmação é falsa. Na raiz está o valor inicial; o menor está à extrema esquerda e o maior à extrema direita.
**(V)** Inserções sucessivas de valores ordenados podem degradar uma ABB, tornando sua altura igual à do pior caso (lista encadeada). 
**(F)** A remoção de um nó com dois filhos em uma ABB é feita apenas removendo o nó sem necessidade de substituição. 
    * *Correção:* É necessário substituir o nó removido pelo seu antecessor ou sucessor para manter as propriedades da árvore.

---

## 4. Análise de Complexidade e Estruturas (1,5 pontos)
**Gabarito:** F - V - F - F 

**(F)** A operação de inserção em uma fila implementada com vetor circular possui custo O(n) devido ao deslocamento dos elementos. 
    * *Correção:* Em vetores circulares, a inserção é O(1) pois não há deslocamento de elementos, apenas atualização de índices.
**(V)** Em uma lista simplesmente encadeada sem descritor, o acesso ao último elemento exige percorrer toda a lista, resultando em complexidade O(n). 
**(F)** Em uma pilha, a operação de remoção depende do tamanho da estrutura, pois é necessário percorrer todos os elementos antes de remover o topo. 
    * *Correção:* A remoção em pilha é sempre no topo e tem custo O(1), sem necessidade de percorrer a estrutura.
**(F)** Em uma árvore binária de busca balanceada, a busca por um elemento tem complexidade O(n) no pior caso. 
    * *Correção:* Em árvores balanceadas (como AVL ou Rubro-Negra), a busca no pior caso é O(log n).

---
*Fonte: Prova de Estrutura de Dados e Algoritmos - UnB Gama (09/12/2025).*