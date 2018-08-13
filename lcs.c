#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <locale.h>

void imprimir(char *texto1,char *texto2){
int tam = (strlen(texto1)+strlen(texto2));
int i=0;

        printf("%s\n",texto1);
        printf("%s\n",texto2);
        printf("tamanho dos textos: %d \n",tam);
}

void teste(){

int matriz[10][10];
char texto1[10];
char texto2[10];
int tam = (strlen(texto1)+strlen(texto2));
int x,y,i,j,cont;
int resultante;
char sem[strlen(texto1)];

    printf("digite uma sequencia: ");
    scanf("%s",texto1);
    printf("digite uma sequencia: ");
    scanf("%s",texto2);

    imprimir(texto1,texto2);

    resultante = lcs(texto1,texto2);

}

int lcs(char *texto1, char* texto2){

    char matriz[strlen(texto1)+1][strlen(texto2)+1];
    int tam,cont,i=0,j=0,x,y;
    tam = (strlen(texto1)+strlen(texto2));
    int res;

    for(i=0;i<=strlen(texto1);i++){
        matriz[i][0]=0;
    }
     for(j=0;j<=strlen(texto2);j++){
        matriz[0][j]=0;
    }

   for(i=0;i<=strlen(texto1);i++){
        for(j=0;j<=strlen(texto2);j++){
            if(texto1[i]==texto2[i]){
                matriz[i][j] = matriz[i-1][j-1] +1;
                }else if(matriz[i-1][j] > matriz[i][j-1]){
                    matriz[i][j]=matriz[i-1][j];
                }else if(matriz[i-1][j] < matriz[i][j-1]){
                    matriz[i][j]=matriz[i][j-1];
                }else{
                    matriz[i][j]=0;
                }
        }
    }

    return res;
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
