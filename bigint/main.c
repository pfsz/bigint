#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
int menu(){
    int v;
    printf("------------------------------\n");
    printf("Digite uma das seguintes opções: \n");
    printf("1 - Amazenar um big int\n");
    printf("2 - Imprimir um big int\n");
    printf("3- Somar um big int\n");
    printf("DIGITE UM VALOR:\n\n");
    scanf("%d", &v);
}

void menu_escolha(Lista* nova){

    int valor = menu();
     switch ( valor ){
     case 1 :
       armazenar(nova);
     break;

     case 2 :

     break;

     case 3 :

     break;

     default :
       printf ("Valor invalido!\n");
  }


}**/

int main(){
    printf("-----BIG INT N1 ---------\n");
    Lista* n1 = cria();
    char url1[]="n1.txt";
    n1 = le_arquivo(n1, &url1);
    imprime_rec(n1);
    printf("-----BIG INT N2 ---------\n");
    Lista* n2 = cria();
    char url2[]="n2.txt";
    n2 = le_arquivo(n2, &url2);
    imprime_rec(n2);
    /**
    printf("-----BIG INT N3 = N1 + N2 ---------\n");
    char url3[]="n3.txt";
    Lista* n3 = cria();

    n3 = soma(n1, n2);

    insere_arquivo(n3, &url3);
    printf("\n");
    imprime_rec(n3);

    libera(n3);
    **/
    printf("----------------VERIFICA IGUAIS------------------\n");
    if(iguais(n1,n2)) printf("IGUAIS\n");
    else printf("DIFERENTES\n");

    libera(n1);
    libera(n2);
    return 0;
}
