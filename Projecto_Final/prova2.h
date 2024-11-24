typedef struct lista LDL;
LDL *criarDupla(int v);
void Inicializardupla(LDL** l);
void inserirnaposicao(LDL** l, int v, int position);
void removernaposicao(LDL** l, int position);
int procurarlista(LDL* l, int element);
LDL* invertergrupos(LDL*l , int k);
void imprimirlista(LDL* l);
void eliminarlista(LDL**l);


