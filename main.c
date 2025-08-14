#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

int main(void) {
    int opcao;

    do {
        printf("\n===== MENU HEAP SORT =====\n");
        printf("1 - Ordenar vetor\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            fprintf(stderr, "Erro: entrada inválida.\n");
            return 1;
        }

        if (opcao == 1) {
            int n;
            printf("\nDigite a quantidade de elementos: ");
            if (scanf("%d", &n) != 1 || n <= 0) {
                fprintf(stderr, "Erro: entrada inválida para N.\n");
                return 1;
            }

            int *v = malloc(n * sizeof(int));
            if (!v) {
                fprintf(stderr, "Erro: falha ao alocar memória.\n");
                return 1;
            }

            printf("Digite os %d elementos: ", n);
            for (int i = 0; i < n; i++) {
                if (scanf("%d", &v[i]) != 1) {
                    fprintf(stderr, "Erro: entrada inválida.\n");
                    free(v);
                    return 1;
                }
            }

            heapSort(v, n);
            printf("\nVetor ordenado: ");
            printArray(v, n);

            free(v);
        }
        else if (opcao != 2) {
            printf("Opcao inválida! Tente novamente.\n");
        }

    } while (opcao != 2);

    printf("Encerrando o programa...\n");
    return 0;
}
