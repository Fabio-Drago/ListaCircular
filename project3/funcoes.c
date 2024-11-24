// funcoes.c
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void inicializarLista(ListaCircular **lista) {
    *lista = NULL;
    printf("Lista inicializada com sucesso!\n");
}

void inserirNo(ListaCircular **lista, int valor, int posicao) {
    ListaCircular *novo = (ListaCircular *)malloc(sizeof(ListaCircular));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        return;
    }
    novo->valor = valor;

    if (*lista == NULL) {
        novo->proximo = novo;  // Lista vazia, nó aponta para si mesmo
        *lista = novo;
    } else if (posicao == 0) {
        // Inserir no início
        ListaCircular *ultimo = *lista;
        while (ultimo->proximo != *lista) {
            ultimo = ultimo->proximo;
        }
        novo->proximo = *lista;
        ultimo->proximo = novo;
        *lista = novo;
    } else {
        // Inserir em outra posição
        ListaCircular *atual = *lista;
        int i;
        for (i = 0; i < posicao - 1 && atual->proximo != *lista; i++) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    printf("Valor %d inserido na posição %d.\n", valor, posicao);
}

void removerNo(ListaCircular **lista, int valor) {
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    ListaCircular *atual = *lista;
    ListaCircular *anterior = NULL;
    ListaCircular *primeiro = *lista;
    int encontrou = 0;

    do {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                // Removendo o primeiro nó
                if (atual->proximo == atual) {
                    // Se há apenas um nó
                    free(atual);
                    *lista = NULL;
                } else {
                    // Se há mais nós
                    ListaCircular *ultimo = atual;
                    while (ultimo->proximo != *lista) {
                        ultimo = ultimo->proximo;
                    }
                    *lista = atual->proximo;
                    ultimo->proximo = *lista;
                    free(atual);
                }
            } else {
                // Removendo nó do meio ou fim
                anterior->proximo = atual->proximo;
                free(atual);
            }
            encontrou = 1;
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != primeiro);

    if (encontrou) {
        printf("Valor %d removido com sucesso.\n", valor);
    } else {
        printf("Valor %d não encontrado na lista.\n", valor);
    }
}

void imprimirLista(ListaCircular *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    ListaCircular *atual = lista;
    printf("Lista: ");
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != lista);
    printf("\n");
}

void procurarElemento(ListaCircular *lista, int valor) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    ListaCircular *atual = lista;
    int posicao = 0;
    int encontrou = 0;

    do {
        if (atual->valor == valor) {
            printf("Valor %d encontrado na posição %d.\n", valor, posicao);
            encontrou = 1;
            break;
        }
        atual = atual->proximo;
        posicao++;
    } while (atual != lista);

    if (!encontrou) {
        printf("Valor %d não encontrado na lista.\n", valor);
    }
}

void remocaoCircular(ListaCircular **lista, int k) {
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    if (k <= 0) {
        printf("K deve ser maior que zero!\n");
        return;
    }

    ListaCircular *atual = *lista;
    ListaCircular *anterior = NULL;

    while (atual->proximo != atual) {
        // Conta k-1 posições
        for (int i = 1; i < k; i++) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Remove o nó atual
        printf("Removendo: %d\n", atual->valor);
        
        if (atual == *lista) {
            // Se estiver removendo o primeiro nó
            ListaCircular *ultimo = *lista;
            while (ultimo->proximo != *lista) {
                ultimo = ultimo->proximo;
            }
            *lista = atual->proximo;
            ultimo->proximo = *lista;
        } else {
            anterior->proximo = atual->proximo;
        }

        ListaCircular *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    printf("Último elemento restante: %d\n", (*lista)->valor);
}

void eliminarLista(ListaCircular **lista) {
    if (*lista == NULL) {
        printf("Lista já está vazia!\n");
        return;
    }

    ListaCircular *atual = *lista;
    ListaCircular *proximo;

    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != *lista);

    *lista = NULL;
    printf("Lista eliminada com sucesso!\n");
}