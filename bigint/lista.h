typedef struct lista Lista;

Lista* cria();

Lista* insere(Lista* lista, char c);

int vazia(Lista* lista);

void libera(Lista* lista);

void imprime_rec(Lista* lista);

void imprime_interativo(Lista* lista);

int convert_int(char valor);

char convert_char(int valor);

Lista* le_arquivo(Lista* lista, char *arquivo);

Lista* insere_final(Lista* lista, char c);

Lista* soma(Lista* l1, Lista* l2);

Lista* insere_arquivo(Lista* lista, char *arquivo);

Lista* subtrai(Lista* l1, Lista* l2);

int iguais(Lista* l1, Lista* l2);

