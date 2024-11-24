// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct No {
    int valor;
    struct No* proximo;
} ListaCircular;

void inicializarLista(ListaCircular **lista);
void inserirNo(ListaCircular **lista, int valor, int posicao);
void removerNo(ListaCircular **lista, int valor);
void imprimirLista(ListaCircular *lista);
void procurarElemento(ListaCircular *lista, int valor);
void remocaoCircular(ListaCircular **lista, int k);
void eliminarLista(ListaCircular **lista);

#endif