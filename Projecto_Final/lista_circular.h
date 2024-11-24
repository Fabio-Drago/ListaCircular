// Estrutura do n�
typedef struct no Listacircular;

// Funções da lista circular
Listacircular* criar(int v);
void inicializar_lista(Listacircular** l);
void inserir_posicao(Listacircular** l, int v, int posicao);
void remover_no(Listacircular** l, int posicao);
void imprimir_lista(Listacircular* l);
int procurar_Elemento(Listacircular* l, int v);
void eliminar_lista(Listacircular** l);
void remocao_circular(Listacircular** l, int k);


