#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
    char valor;
    struct lista* proximo;
};

Lista* cria(){
    return NULL;
}

Lista* insere(Lista* lista, char valor){
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    nova->valor = valor;
    nova->proximo = lista;
    return nova;
}

Lista* insere_final(Lista* lista, char c){
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    nova->proximo = NULL;
    nova->valor = c;
    if(vazia(lista)) lista = nova;
    else{
        Lista* aux = lista;
        while(aux->proximo !=NULL){
            aux = aux->proximo;
        }
        aux->proximo = nova;
    }
    return lista;
}



int vazia(Lista* lista){
    return (lista == NULL);
}

void imprime_rec(Lista* lista){
    if(vazia(lista)){
        return;
    }
    imprime_rec(lista->proximo);
    printf("%c\n",lista->valor);

}

void imprime_interativo(Lista* lista){
    if(vazia(lista)){
        exit(1);
    }
    Lista* aux = lista;
    while(aux!=NULL){
        //printf("%d\t", convert_inteiro(aux->valor));
        //printf("%d", lista->valor);
        aux = aux->proximo;
    }
}

int convert_int(char valor){
    if(valor == '0') return 0;
    else if(valor == '1') return 1;
    else if(valor == '2') return 2;
    else if(valor == '3') return 3;
    else if(valor == '4') return 4;
    else if(valor == '5') return 5;
    else if(valor == '6') return 6;
    else if(valor == '7') return 7;
    else if(valor == '8') return 8;
    else if(valor == '9') return 9;
    else if(valor == '-') return 45;
    else return 0;
}

char convert_char(int valor){
    if(valor == 0) return 48;
    else if(valor == 1) return 49;
    else if(valor == 2) return 50;
    else if(valor == 3) return 51;
    else if(valor == 4) return 52;
    else if(valor == 5) return 53;
    else if(valor == 6) return 54;
    else if(valor == 7) return 55;
    else if(valor == 8) return 56;
    else if(valor == 9) return 57;
    else if(valor == 45) return 45;
    else return 0;

}

void libera(Lista* lista){
    Lista* aux = lista;
    while(aux!=NULL){
        lista = lista->proximo;
        free(aux);
        aux = lista;
    }
}

Lista* le_arquivo(Lista* lista, char *arquivo){
    char ch;
	FILE *arq = fopen(arquivo,"r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while( (ch=fgetc(arq))!= EOF ){
            if(ch!='\n')
            lista = insere(lista,ch);
	    }
    fclose(arq);
    return lista;
}

Lista* insere_arquivo(Lista* lista, char *arquivo){
    Lista* aux = lista;
    FILE *arq = fopen(arquivo,"w");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while(aux!=NULL){
           fputc(aux->valor, arq);
            aux = aux->proximo;
	    }
    fclose(arq);
    return lista;
}

int verifica_negativa(Lista* lista){
    if(vazia(lista))return 0;
    Lista* aux = lista;
    while(aux!=NULL){
        if(aux->valor == '-'){
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

int tamanho_lista(Lista* lista){
    if(vazia(lista)) return 0;
    int tamanho = 0;
    Lista* aux = lista;

    while(aux!=NULL){
        tamanho+=1;
        aux = aux->proximo;
    }
    return tamanho-1;
}
/**
Lista* soma(Lista* n1, Lista* n2){
    Lista* n3;
    Lista* l1 = n1; Lista* l2 = n2;
    int soma = 0;
    if(verifica_negativa(n1) == 0 && verifica_negativa(n2) == 0){
        if(tamanho_lista(l1) > tamanho_lista(l2)){
            for(l1, l2; l1!=NULL, l2!=NULL; l1 = l1->proximo, l2 = l2->proximo){

                if(soma == 0 && l2!=NULL){
                    soma = convert_int(l1->valor) + convert_int(l2->valor);

                    if(soma<10){
                        n3 = insere(n3, convert_char(soma));
                        soma = 0;
                    }
                    else{
                        soma = soma-10;
                        n3 = insere(n3, convert_char(soma));
                        soma += 1;
                    }
                }
                else if(soma == 1 && l2!=NULL){
                    soma = convert_int(l1->valor) + convert_int(l2->valor) + 1;
                    if(soma<10){
                        n3 = insere(n3, convert_char(soma));
                        soma = 0;
                    }
                    else{
                        soma = soma-10;
                        n3 = insere(n3, convert_char(soma));
                        soma += 1;
                    }
                }
                else if(soma == 1 && l2 == NULL){
                    soma = convert_int(l1->valor) + 1;
                    if(soma<10){
                        n3 = insere(n3, convert_char(soma));
                        soma = 0;
                    }
                    else{
                        soma = soma - 10;
                        n3 = insere(n3, convert_char(soma));
                        soma += 1;
                    }
                }
                else{
                    n3 = insere(n3, convert_char(l1->valor));
                }
            }
        }
    }

    return n3;

}
**/

Lista* subtrai(Lista* l1, Lista* l2){

    return NULL;
}

int iguais(Lista* l1, Lista* l2){
    if(tamanho_lista(l1) != tamanho_lista(l2))return 0;
    else{
        Lista* aux1;
        Lista* aux2;
        for(aux1,aux2; aux1!=NULL, aux2!=NULL; aux1 = aux1->proximo, aux2 = aux2->proximo){
            if(aux1->valor!= aux2->valor) return 0;
        }
        return 1;
    }
    return 1;
}


Lista* soma(Lista* l1, Lista* l2){
    Lista* aux1 = l1;
    Lista* aux2 = l2;
    Lista* n3 = NULL;
    int x,y;
    char c;
    int sum = 0;
    int negativa = 0;
    if(tamanho_lista(l1) >= tamanho_lista(l2)){
        Lista* aux1 = l1;
        Lista* aux2 = l2;
    }
    else{
        Lista* aux1 = l2;
        Lista* aux2 = l1;

    }
    if(verifica_negativa(l1) == 1 && verifica_negativa(l2) ==1 ) negativa = 1;
    if(verifica_negativa(l1) == 1 && verifica_negativa(l2) ==1 || verifica_negativa(l1) == 0 && verifica_negativa(l2) == 0){

        for(aux1;aux1!=NULL; aux1 =aux1->proximo){
            x = convert_int(aux1->valor);
            if(aux2!=NULL){
                y = convert_int(aux2->valor);
                aux2 = aux2->proximo;
                sum = x+y+sum;
                if(sum<10){
                    c = convert_char(sum);
                    n3 = insere_final(n3, c);
                    sum = 0;
                }else{
                    sum = sum - 10;
                    c = convert_char(sum);
                    n3 = insere_final(n3, c);
                    sum = 1;
                }

            }
            else{
                if(sum == 0){
                    n3 = insere_final(n3, aux1->valor);
                }
                else{
                    x = convert_int(aux1->valor);
                    sum = x + sum;
                    if(sum<10){
                        c = convert_char(sum);
                        n3 = insere_final(n3, c);
                        sum = 0;
                    }
                    else{
                        sum = sum - 10;
                        c = convert_char(sum);
                        n3 = insere_final(n3, c);
                        sum = 1;

                    }
                }

            }
        }

        if(sum == 1){
            n3 = insere_final(n3,'1');
        }
    }
    else n3 = subtrai(l1,l2);
    return n3;
}


