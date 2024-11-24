#include <stdio.h>
#include <stdlib.h>
#include"prova2.h"

// Estrutura da lista
typedef struct lista {
    int valor;
    struct lista* prox;
    struct lista* ant;
} LDL;

LDL* criarDupla(int v) {
    LDL* novo = (LDL*)malloc(sizeof(LDL));
    novo->valor = v;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void Inicializardupla(LDL** l) {
    *l = NULL;
}

void inserirnaposicao(LDL** l, int v, int position) {
    LDL* novo = criarDupla(v);
    if (*l == NULL || position == 0) {
        novo->prox = *l;
        if (*l != NULL) {
            (*l)->ant = novo;
        }
        *l = novo;
    } else {
        LDL* aux = *l;
        int i = 0;
        while (aux->prox != NULL && i < position - 1) {
            aux = aux->prox;
            i++;
        }
        novo->prox = aux->prox;
        novo->ant = aux;
        if (aux->prox) {
            aux->prox->ant = novo;
        }
        aux->prox = novo;
    }
}

void removernaposicao(LDL** l, int position) {
    if (*l == NULL) {
        printf("Lista está vazia.\n");
        return;
    }
    LDL* aux = *l;
    if (position == 0) {
        *l = aux->prox;
        if (*l != NULL) {
            (*l)->ant = NULL;
        }
        free(aux);
    } else {
        int i = 0;
        while (aux != NULL && i < position) {
            aux = aux->prox;
            i++;
        }
        if (aux == NULL) {
            printf("Posição inválida.\n");
            return;
        }
        if (aux->ant) {
            aux->ant->prox = aux->prox;
        }
        if (aux->prox) {
            aux->prox->ant = aux->ant;
        }
        free(aux);
    }
}

int procurarlista(LDL* l, int element) {
    LDL* aux = l;
    int position = 0;
    while (aux != NULL) {
        if (aux->valor == element) {
            return position;
        }
        aux = aux->prox;
        position++;
    }
    return -1;
}

LDL* inverterGrupos(LDL* head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    LDL* atual = head;
    LDL* novoInicio = NULL;
    LDL* fimAnterior = NULL;

    while (atual != NULL) {
        int count = 0;
        LDL* grupoInicio = atual;
        LDL* grupoFim = NULL;

        while (atual != NULL && count < k) {
            grupoFim = atual;
            atual = atual->prox;
            count++;
        }

        LDL* prev = NULL;
        LDL* curr = grupoInicio;

        while (curr != atual) {
            LDL* next = curr->prox;
            curr->prox = prev;
            curr->ant = next;
            prev = curr;
            curr = next;
        }

        if (fimAnterior != NULL) {
            fimAnterior->prox = grupoFim;
        } else {
            novoInicio = grupoFim;
        }

        grupoInicio->prox = atual;
        if (atual != NULL) {
            atual->ant = grupoInicio;
        }

        fimAnterior = grupoInicio;
    }

    return novoInicio;
}

void imprimirlista(LDL* l) {
    if (l == NULL) {
        printf("Lista está vazia.\n");
        return;
    }
    LDL* aux = l;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}


void eliminarLista(LDL** l) {
    if (*l == NULL) {
        printf("A lista já está vazia.\n");
        return;
    }

    LDL* atual = *l;
    LDL* proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *l = NULL;
    printf("A lista foi eliminada com sucesso.\n");
}


