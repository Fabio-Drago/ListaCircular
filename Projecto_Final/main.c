#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista_circular.h"
#include "prova2.h"
#include "lista_circular.c"
#include "prova2.c"

void menu_principal() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Operações com Lista Circular\n");
    printf("2. Operações com Lista Duplamente Ligada\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
}

void menu_circular() {
    printf("\n--- Menu Lista Circular ---\n");
    printf("1. Inserir elemento em uma posição\n");
    printf("2. Remover elemento em uma posição\n");
    printf("3. Imprimir a lista\n");
    printf("4. Buscar elemento na lista\n");
    printf("5. Realizar remoção circular\n");
    printf("6. Eliminar lista\n");
    printf("7. Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
}

void menu_dupla() {
    printf("\n--- Menu Lista Duplamente Ligada ---\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Procurar elemento\n");
    printf("4. Inverter grupos de K nós\n");
    printf("5. Imprimir lista\n");
    printf("6. Eliminar lista\n");
    printf("7. Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicialização das listas
    Listacircular* lista_circular = NULL;
    LDL* lista_dupla = NULL;
    inicializar_lista(&lista_circular);
    Inicializardupla(&lista_dupla);

    int opcao_principal, opcao_secundaria, valor, posicao;

    do {
        menu_principal();
        if (scanf("%d", &opcao_principal) != 1) {
            printf("Entrada inválida! Por favor, insira um número válido.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao_principal) {
            case 1: // Menu Lista Circular
                do {
                    menu_circular();
                    if (scanf("%d", &opcao_secundaria) != 1) {
                        printf("Entrada inválida!\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (opcao_secundaria) {
                        case 1: // Inserir elemento
                            printf("Digite o valor a ser inserido: ");
                            scanf("%d", &valor);
                            printf("Digite a posição (0 para início): ");
                            scanf("%d", &posicao);
                            inserir_posicao(&lista_circular, valor, posicao);
                            break;
                        case 2: // Remover elemento
                            printf("Digite a posição do elemento a ser removido: ");
                            scanf("%d", &posicao);
                            remover_no(&lista_circular, posicao);
                            break;
                        case 3: // Imprimir lista
                            printf("Lista atual: ");
                            imprimir_lista(lista_circular);
                            break;
                        case 4: // Buscar elemento
                            printf("Digite o valor a ser buscado: ");
                            scanf("%d", &valor);
                            posicao = procurar_Elemento(lista_circular, valor);
                            if (posicao == -1) {
                                printf("Elemento não encontrado.\n");
                            } else {
                                printf("Elemento encontrado na posição: %d\n", posicao);
                            }
                            break;
                        case 5: // Remoção circular
                            printf("Digite o valor de k (maior que 1): ");
                            int k;
                            scanf("%d", &k);
                            remocao_circular(&lista_circular, k);
                            break;
                        case 6: // Eliminar lista
                            eliminar_lista(&lista_circular);
                            break;
                        case 7: // Voltar ao menu principal
                            break;
                        default:
                            printf("Opção inválida!\n");
                    }
                } while (opcao_secundaria != 7);
                break;

            case 2: // Menu Lista Duplamente Ligada
                do {
                    menu_dupla();
                    if (scanf("%d", &opcao_secundaria) != 1) {
                        printf("Entrada inválida!\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (opcao_secundaria) {
                        case 1: // Inserir elemento
                            printf("Digite o valor a ser inserido: ");
                            scanf("%d", &valor);
                            printf("Digite a posição onde deseja inserir(0 para o inicio): ");
                            scanf("%d", &posicao);
                            inserirnaposicao(&lista_dupla, valor, posicao);
                            break;
                        case 2: // Remover elemento
                            printf("Digite a posição do elemento a ser removido: ");
                            scanf("%d", &posicao);
                            removernaposicao(&lista_dupla, posicao);
                            break;
                        case 3: // Procurar elemento
                            printf("Digite o valor a ser procurado: ");
                            scanf("%d", &valor);
                            posicao = procurarlista(lista_dupla, valor);
                            if (posicao != -1) {
                                printf("Elemento %d encontrado na posição %d.\n", valor, posicao);
                            } else {
                                printf("Elemento %d não encontrado.\n", valor);
                            }
                            break;
                        case 4: // Inverter grupos
                            printf("Digite o valor de K: ");
                            scanf("%d", &posicao);
                            lista_dupla = inverterGrupos(lista_dupla, posicao);
                            printf("Lista invertida em grupos de %d nós com sucesso!\n", posicao);
                            break;
                        case 5: // Imprimir lista
                            printf("Elementos da lista: ");
                            imprimirlista(lista_dupla);
                            break;
                        case 6: // Eliminar lista
                            eliminarLista(&lista_dupla);
                            break;
                        case 7: // Voltar ao menu principal
                            break;
                        default:
                            printf("Opção inválida!\n");
                    }
                } while (opcao_secundaria != 7);
                break;

            case 3: // Sair do programa
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao_principal != 3);

    return 0;
}