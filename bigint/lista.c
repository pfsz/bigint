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

// recebe dois numeros com sinais diferentes, lista com maior unidade
Lista* verifica_tamanho_maior(Lista* l1, Lista* l2){
    Lista *aux1 = l1;
    Lista *aux2 = l2;
    Lista *negativo = NULL, *positivo = NULL;

    if(verifica_negativa(l1)){
        negativo = l1;
        positivo = l2;
    }
    else{
        negativo = l2;
        positivo = l1;
    }

    int tamPositivo = tamanho_lista(positivo), tamNegativo = tamanho_lista(negativo)-1;
    if(tamNegativo > tamPositivo) return negativo;
    else if(tamPositivo > tamNegativo) return positivo;
    else{
        if(maior_valor_numero(l1,l2)!=NULL){
            return maior_valor_numero(l1,l2);
        }
        return NULL;
    }
}

// numeros do mesmo tamanho (sem contar o sinal negativo)
// retorna a lista com a maior unidade;
Lista* maior_valor_numero(Lista* l1, Lista* l2){
    if(iguais(l1, l2)) return NULL;
    Lista *desvirada1 = l1, *aux1 = l1, *desvirada2 = l2, *aux2 = l2;
    while(aux1!=NULL && aux2!=NULL && aux1->valor!='-' && aux2->valor!='-'){
        desvirada1 = insere(desvirada1, aux1->valor);
        aux1 = aux1->proximo;
        desvirada2 = insere(desvirada2, aux2->valor);
        aux2 = aux2->proximo;
    }
    //listas desviradas sem sinal
    Lista * maior = NULL;
    aux1 = desvirada1, aux2 = desvirada2;
    while(aux1!=NULL && aux2!=NULL){
        if(aux1->valor > aux2-> valor){
            return l1;
        }
        if(aux2->valor > aux1->valor){
            return l2;
        }
    }
    return NULL;
}
// verifica se as listas sao iguai sem o sinal
int verifica_igual_pos_negativa(Lista* l1, Lista* l2){
    Lista *aux1 = l1;
    Lista *aux2 = l2;
    while(aux1!=NULL && aux2!=NULL){
        if(aux1->valor != aux2->valor){
            return 0;
        }
    }
    return 1;

}

Lista* subtrai(Lista* l1, Lista* l2){
    Lista *negativa;
    Lista *positiva;
    Lista *n3 = NULL;
    Lista *maior_unidade;
    int sinal_negativo;
    int subtrai = 0;
    char c;
    int pos, neg;

    if(verifica_negativa(l1) == 1){
        negativa = l1;
        positiva = l2;
    }
    if(verifica_negativa(l2) == 1){
        negativa = l2;
        positiva = l1;
    }
    //se negativa igual positiva sem o sinal entao retorna NULL
    if(tamanho_lista(negativa)-1 == tamanho_lista(positiva)){
        //
        if(verifica_igual_pos_negativa(l1,l2) == 1) return NULL;
        else{
            // recebe a lista com a maior unidade para que seja feita a subtracao e heranca do sinal
            maior_unidade = maior_valor_numero(l1,l2);
            //se a lista de maior unidade for a negativa o sinal e guardado
            if(iguais(negativa, maior_unidade) == 1) sinal_negativo = 1;
            else sinal_negativo = 0;
        }
    }
    // entra caso a lista de unidade maior seja a negativa com listas com mema qntd de numeros
    if(tamanho_lista(negativa)-1 == tamanho_lista(positiva) && sinal_negativo == 1){

    }

    // se a negativa for maior subtrai e recebe o sinal de -
    if(tamanho_lista(negativa)-1 > tamanho_lista(positiva)){
        for(negativa; negativa!=NULL; negativa = negativa->proximo){
            if(negativa->valor != '-'){
                    if(positiva!=NULL){
                            pos = convert_int(positiva->valor);
                            neg = convert_int(negativa->valor);
                        if(pos <= neg){
                            if(subtrai == -1 && pos!=neg){
                                subtrai = neg - pos  + subtrai;
                                c = convert_char(subtrai);
                                n3 = insere(n3,c);
                                subtrai = 0;
                            }
                            else if(subtrai == -1 && pos == neg){
                                n3 = insere(n3,'9');
                                subtrai = -1;

                            }
                            else{
                                subtrai = neg - pos + subtrai;
                                c = convert_char(subtrai);
                                n3 = insere(n3,c);
                                subtrai = 0;
                            }

                        }
                        else{
                            subtrai =(( (10 + neg) - pos) + subtrai);
                            c = convert_char(subtrai);
                            n3 = insere(n3,c);
                            subtrai = -1;

                        }

                        positiva = positiva->proximo;
                    }
                    //caso a lista positiva acabe
                    else{
                        if(subtrai == -1){
                            neg = convert_int(negativa->valor);
                            subtrai = (neg) + subtrai;

                            if(subtrai == 0){
                                if(negativa->proximo == NULL || negativa->proximo == '-'){
                                    n3 = insere(n3, '-');
                                    return n3;
                                }
                                else{
                                    c = convert_char(subtrai);
                                    n3 = insere(n3,c);
                                    subtrai = 0;
                                }
                            }
                            else{
                                c = convert_char(subtrai);
                                n3 = insere(n3, c);
                                subtrai = 0;
                            }
                        }
                        //utima verificacao
                        else{
                            n3 = insere(n3, negativa->valor);
                        }
                    }
            }

        }
        n3 = insere(n3,'-');
        return n3;

}

    // se a positiva é maior subtrai e fica sem sinal
    else if(tamanho_lista(negativa)-1 < tamanho_lista(positiva)){
        for(positiva; positiva!=NULL ; positiva = positiva->proximo){
            pos = convert_int(positiva->valor);
            //percorre negativa ate que seja diferente de - ou null
            if(negativa!=NULL && negativa->valor !='-'){
                neg = convert_int(negativa->valor);
                if(neg <= pos){
                    if(subtrai == -1 && pos!=neg){
                        subtrai = (pos - neg)  + subtrai;
                        c = convert_char(subtrai);
                        n3 = insere(n3,c);
                        subtrai = 0;
                    }
                    else if(subtrai == -1 && pos == neg){
                        n3 = insere(n3,'9');
                        subtrai = -1;

                    }
                    else{
                        subtrai = (pos - neg) + subtrai;
                        c = convert_char(subtrai);
                        n3 = insere(n3,c);
                        subtrai = 0;
                    }

            }
            else{
                subtrai =(( (10 + pos) - neg) + subtrai);
                c = convert_char(subtrai);
                n3 = insere(n3,c);
                subtrai = -1;

            }

            negativa = negativa->proximo;

        }

        //caso a lista positiva acabe
        else{
            if(subtrai == -1){
                    pos = convert_int(positiva->valor);
                    subtrai = (pos) + subtrai;
                    if(subtrai == 0){
                        if(positiva->proximo == NULL){
                            return n3;
                        }
                        else{
                            c = convert_char(subtrai);
                            n3 = insere(n3,c);
                            subtrai = 0;
                        }

                    }
                    else{
                        c = convert_char(subtrai);
                        n3 = insere(n3, c);
                        subtrai = 0;
                        }
                    }
                            //utima verificacao
            else{
                n3 = insere(n3, positiva->valor);
            }
        }
    }
        return n3;
    }





}

int iguais(Lista* l1, Lista* l2){
    if(tamanho_lista(l1) != tamanho_lista(l2))return 0;
    else{
        Lista* aux1 = l1;
        Lista* aux2 = l2;
        for(aux1,aux2; aux1!=NULL, aux2!=NULL; aux1 = aux1->proximo, aux2 = aux2->proximo){
            if(aux1->valor!= aux2->valor) return 0;
        }
        return 1;
    }
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
    //se ambas forem negativas o sinal negativo e add no final
    if(verifica_negativa(l1) == 1 && verifica_negativa(l2) ==1 ) negativa = 1;
    //se ambas forem negativas ou ambaspositivas efetuasse uma soma
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
    if(negativa == 1) n3 = insere_final(n3,'-');
    return n3;
}


