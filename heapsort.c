#include <stdio.h>
#include "heapsort.h"  // inclui a interface

// Troca os valores apontados por a e b.
static void swap(int *a, int *b) {
    int tmp = *a; //Guarda temporariamente o valor de a*
    *a = *b; //Coloca em  a* o valor que estava em a*
    *b = tmp; //Coloca em b* o valor guardado (antigo a*)
}

// "Afunda" o elemento na posição i para restaurar MAX-heap.
static void heapify(int v[], int n, int i) {
    int maior = i; //Assume que o maior valor é o índice i
    int esq = 2 * i + 1; //Índice  (1) filho da esquerda 
    int dir = 2 * i + 2; //índice (2) filho da direita

    if (esq < n && v[esq] > v[maior])
        maior = esq;

    if (dir < n && v[dir] > v[maior])  /*basicamente  comparamos um pai com os filhos
     e trocamos com o maior*/
        maior = dir;

    if (maior != i) {
        swap(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}

// Constrói um MAX-heap a partir do vetor.
static void buildMaxHeap(int v[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(v, n, i);
    } /*Ele começa no último nó não-folha (n/2)-1 
    e chama heapify pra ajustar cada subárvore*/
}

// Implementação do Heap Sort.
void heapSort(int v[], int n) {
    buildMaxHeap(v, n);
    for (int end = n - 1; end > 0; end--) { 
        swap(&v[0], &v[end]);
        heapify(v, end, 0);
    }
}

// Imprime o vetor.
void printArray(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (i) printf(" "); /*FUNÇÃO RESPONSAVEL POR IMPRIMIR OS 
        ELEMENTOS DO VETOR APÓS A ORDENAÇÃO*/
        printf("%d", v[i]);
    }
    printf("\n");
}
