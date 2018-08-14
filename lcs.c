#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void tamanho(char *texto1,char *texto2){
int tam = (strlen(texto1)+strlen(texto2));
int i=0;
        printf("\ntamanho total dos textos: %d ",tam);
}

int maior(int A, int B){
    if (A>B){
        return A;
    }else{
        return B;
    }
}

void digitar(){

char texto1[100];
char texto2[100];

    printf("\n digitar tem o limite de 1000 caracteres....\n");
    printf("digite uma sequência: ");
    scanf("%s",&texto1);

    printf("digite uma sequência: ");
    scanf("%s",&texto2);

    controle(texto1,texto2);

}

void controle(char *texto1, char *texto2){

int resultado = 0;

    resultado = lcs(texto1,texto2);
    tamanho(texto1,texto2);
    printf("\nsemelhanças encontradas: %d",resultado);


}

//função do LCS
int lcs(char *texto1, char *texto2){

char matriz[strlen(texto1)+1][strlen(texto2)+1];
int x=0,y=0,i=0,j=0;

//zerando os indices desnecessarios
    for(i=0;i<=strlen(texto1);i++){
        matriz[i][0]=0;
    }
     for(j=0;j<=strlen(texto2);j++){
        matriz[0][j]=0;
    }

//LCS
   for(i=1;i<=strlen(texto1);i++){

        for(j=1 ; j <= strlen(texto2) ; j++){

            if(texto1[i-1] == texto2[j-1]){
                matriz[i][j] = matriz[i-1][j-1] +1;

                }else{
                    matriz[i][j] = maior(matriz[i][j-1],matriz[i-1][j]);
                }
        }
    }

//imprimindo a matriz
    printf("\t");
    for(i=0;i<strlen(texto1);i++){
        printf(" %c   ",texto1[i]);
    }
    printf("\n  ");

    for(i=0;i<=strlen(texto1);i++){

        for(j=0;j<=strlen(texto2);j++){
                printf(" [%d] ",matriz[i][j]);
        }
        printf("\n");
        printf(" \n%c ",texto2[i]);
    }

//imprimindo o pontos de semelhanca
 int aux,cont = maior(strlen(texto1),strlen(texto2))+1;
 char sem[cont+1];
      sem[cont] = ' ';

      for(aux =0;aux<=cont;aux++){
        sem[aux]=' ';
      }

 x=i,y=j;

    while(x>0 && y>0){
        if(texto1[x-1] == texto2[y-1]){
            sem[cont-1] = texto1[x-1];
            x--,y--,cont--;
        }else if(matriz[x-1][y] > matriz[x][y-1]){
            x--;
        }else{
            y--;
        }
    }
    printf("\npontos semelhantes: %s", sem);

// imprimindo o grau de semelhança
int maior;
float grau;

    if(strlen(texto1)>strlen(texto2)){
        maior = strlen(texto1);
    }else{
        maior = strlen(texto2);
    }

    grau = matriz[strlen(texto1)][strlen(texto2)];
    grau = ((grau)/(maior));

    printf("\ngrau de semelhança: %.2f ", grau);

//fim da função
    return matriz[strlen(texto1)][strlen(texto2)];

}

//função para abrir os arquivos e começar o programa
void abrir(){
      FILE* f; FILE* f2;
      int tam1=0,tam2=0;
      char caracter;

    f = fopen("texto1.txt", "r");
    f2 = fopen("texto2.txt", "r");

     while (!feof(f)){
        caracter = fgetc(f);
        tam1++;
      }
      while (!feof(f2)){
        caracter = fgetc(f2);
        tam2++;
      }
    fclose(f);
    fclose(f2);

char texto1[tam1+1];
char texto2[tam2+1];

    f = fopen("texto1.txt", "r");
    f2 = fopen("texto2.txt", "r");

    while( (fscanf(f,"%s", texto1))!=EOF );
    while( (fscanf(f2,"%s", texto2))!=EOF );

    fclose(f);
    fclose(f2);

   controle(texto1,texto2);
}

int main(){
    setlocale(LC_ALL,"");
    int e=0;
    printf(" Digite\n 1 - para digitar os textos \n 2 - para ler arquivos de texto\n");
    scanf("%d",&e);


        if(e == 1){
            digitar();
            e = 0;
        }else if(e == 2){
            abrir();
        }else{
            printf("\ndigite apenas 1 ou 2....\n");
        }

    return 0;

}
