// main.c
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    ListaCircular *lista = NULL;
    int opcao, valor, posicao, k;
    char limpar_buffer;

    while (1) {
        printf("\n--- MENU LISTA CIRCULAR ---\n");
        printf("1. Inicializar Lista\n");
        printf("2. Inserir nó em posição especifica\n");
        printf("3. Remover nó\n");
        printf("4. Imprimir lista\n");
        printf("5. Procurar elemento\n");
        printf("6. Remoção circular com K\n");
        printf("7. Eliminar lista\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Digite um número.\n");
            while ((limpar_buffer = getchar()) != '\n' && limpar_buffer != EOF);
            continue;
        }

        while ((limpar_buffer = getchar()) != '\n' && limpar_buffer != EOF);

        switch (opcao) {
            case 1:
                inicializarLista(&lista);
                break;

            case 2:
                printf("Digite o valor a inserir: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Valor inválido!\n");
                    while ((limpar_buffer = getchar()) != '\n' && limpar_buffer != EOF);
                    break;
                }
                printf("Digite a posição (0 para início): ");
                if (scanf("%d", &posicao) != 1 || posicao < 0) {
                    printf("Posição inválida!\n");
                    while ((limpar_buffer = getchar()) != '\n' && limpar_buffer != EOF);
                    break;
                }
                inserirNo(&lista, valor, posicao);
                break;

            case 3:
                printf("Digite o valor do nó a remover: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Valor inválido!\n");
                    while ((limpar_buffer = getchar()) != '\n' && limpar_buffer != EOF);
                    break;
                }
                removerNo(&lista, valor);
                break;

            case 4:
                imprimirLista(lista);
                break;

            case 5:
                printf("Digite o valor a procurar: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Valor inválido!\n");
                    while ((limpar_buffer = getchar()) != '\n' && limpar_buffer != EOF);
                    break;
                }
                procurarElemento(lista, valor);
                break;

            case 6:
                printf("Digite o valor de K: ");
                if (scanf("%d", &k) != 1 || k <= 0) {
                    printf("K deve ser maior que zero!\n");
                    while ((limpar_buffer = getchar()) != '\n' && limpar_buffer != EOF);
                    break;
                }
                remocaoCircular(&lista, k);
                break;

            case 7:
                eliminarLista(&lista);
                break;

            case 8:
                printf("Encerrando o programa...\n");
                eliminarLista(&lista);
                return 0;

            default:
                printf("Opção inválida! Escolha entre 1 e 8.\n");
        }
    }

    return 0;
}