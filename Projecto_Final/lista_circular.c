#include <stdio.h>
#include <stdlib.h>
#include"lista_circular.h"

// Definição do nó da lista circular
typedef struct no {
    int valor;
    struct no* proximo;
} Listacircular;

// Função para criar um novo nó
Listacircular* criar(int v) {
    Listacircular* novo = (Listacircular*)malloc(sizeof(Listacircular));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = v;
    novo->proximo = novo; // Inicialmente aponta para si mesmo
    return novo;
}

// Função para inicializar a lista circular
void inicializar_lista(Listacircular** l) {
    *l = NULL;
}

// Função para inserir um nó em uma posição específica
void inserir_posicao(Listacircular** l, int v, int posicao) {
    Listacircular* novo = criar(v);

    if (*l == NULL || posicao == 0) { // Inserir no início
        if (*l == NULL) {
            *l = novo;
        } else {
            Listacircular* aux = *l;
            while (aux->proximo != *l) { // Encontrar o último nó
                aux = aux->proximo;
            }
            novo->proximo = *l;
            aux->proximo = novo;
            *l = novo; // Atualiza o início
        }
    } else { // Inserir em uma posição específica
        Listacircular* aux = *l;
        int contador = 0;

        // Avança até a posição ou o final
        while (contador < posicao - 1 && aux->proximo != *l) {
            aux = aux->proximo;
            contador++;
        }

        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
}

// Função para remover um nó de uma posição específica
void remover_no(Listacircular** l, int posicao) {
    if (*l == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Listacircular* aux = *l;
    Listacircular* anterior = NULL;

    // Remover o primeiro nó
    if (posicao == 0) {
        while (aux->proximo != *l) { // Encontra o último nó
            aux = aux->proximo;
        }

        if (aux == *l) { // Apenas um nó na lista
            free(*l);
            *l = NULL;
        } else {
            Listacircular* temp = *l;
            aux->proximo = (*l)->proximo;
            *l = (*l)->proximo;
            free(temp);
        }
    } else { // Remover em outra posição
        int contador = 0;
        while (contador < posicao && aux->proximo != *l) {
            anterior = aux;
            aux = aux->proximo;
            contador++;
        }

        if (contador == posicao) {
            anterior->proximo = aux->proximo;
            free(aux);
        } else {
            printf("Posição inválida.\n");
        }
    }
}

// Função para imprimir a lista circular
void imprimir_lista(Listacircular* l) {
    if (l == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Listacircular* aux = l;
    do {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    } while (aux != l);
    printf("\n");
}

// Função para procurar um elemento na lista circular
int procurar_Elemento(Listacircular* l, int v) {
    if (l == NULL) {
        printf("Lista vazia!\n");
        return -1;
    }

    Listacircular* aux = l;
    int posicao = 0;
    do {
        if (aux->valor == v) {
            return posicao; // Retorna a posição do elemento
        }
        aux = aux->proximo;
        posicao++;
    } while (aux != l);

    return -1; // Retorna -1 se o valor não for encontrado
}

// Função para realizar a remoção circular
void remocao_circular(Listacircular** l, int k) {
    if (*l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    if (k <= 1) {
        printf("O valor de k deve ser maior que 1.\n");
        return;
    }

    Listacircular* aux = *l;
    Listacircular* anterior = NULL;

    while ((*l)->proximo != *l) {
        for (int i = 1; i < k; i++) {
            anterior = aux;
            aux = aux->proximo;
        }
        printf("Removendo: %d\n", aux->valor);
        anterior->proximo = aux->proximo;
        if (aux == *l) {
            *l = aux->proximo;
        }
        free(aux);
        aux = anterior->proximo;
    }
    printf("Último elemento restante: %d\n", (*l)->valor);
}

// Função para eliminar toda a lista circular
void eliminar_lista(Listacircular** l) {
    if (*l == NULL) {
        printf("A lista já está vazia!\n");
        return;
    }

    Listacircular* aux = *l;
    Listacircular* proximo;

    do {
        proximo = aux->proximo;
        free(aux);
        aux = proximo;
    } while (aux != *l);

    *l = NULL;
    printf("Lista eliminada com sucesso!\n");
}

