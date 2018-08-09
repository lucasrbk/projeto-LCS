#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <locale.h>

void imprimir(char *texto1,char *texto2){

int tam=(strlen(texto1)+strlen(texto1));
int i=0;

        printf("%s\n",texto1);
        printf("%s\n",texto2);
        printf("tamanho dos textos: %d \n",tam);
}

void teste(){

char texto1[10][10];
char texto2[10][10];
int x,y,cont;

    printf("digite uma sequencia: ");
    scanf("%s",texto1);
    printf("digite uma sequencia: ");
    scanf("%s",texto2);

    imprimir(texto1,texto2);

    if(texto1[i]==texto2[i]){

    }



}
void lcs(char *texto1, char* texto2){

    char matriz[10][10];
    int tam,cont,i=1,x,y;
    tam = (strlen(texto1)+strlen(texto2));

    while(i<=tam){

        if(texto1[i]==texto2[i]){

        }
    }


}
void abre_arquivos(){
      FILE* f; FILE* f2;
      int tam1,tam2;
      char texto1[15],texto2[15];

    f = fopen("palavras1.txt", "r");
    f2 = fopen("palavras2.txt", "r");

    while( (fscanf(f,"%s", texto1))!=EOF ){
			printf("%s \n", texto1);}

    while( (fscanf(f2,"%s", texto2))!=EOF ){
            printf("%s \n", texto2);}

    tam1 = strlen(texto1);
    printf("%d\n",tam1);
    tam2 = strlen(texto2);
    printf("%d\n",tam2);

}

void preencher(int tam1, int tam2){
    char texto1[tam1]; char texto2[tam2];
    //fscanf(f,"%s", texto1);
    //fscanf(f2,"%s", texto2);
}

void compara_arquivo(){

}



int main(){
//setlocale  (LC_ALL, "Portuguese");


    //abre_arquivos();

    teste();


    return 0;

}
