#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,i,j;
    int estrela,branco,meio;

        while(scanf("%d",&N)!=EOF){
        estrela = 1;
        branco = N/2;
        meio = branco;


        while(estrela<=N){
            for(i=1; i<=branco;i++){
                printf(" ");
            }
            for(i=1; i<=estrela; i++)
                printf("*");
            estrela = estrela +2;
            branco--;
            printf("\n");
        }
            for(i=1;i<=meio;i++)
                printf(" ");
            printf("*\n");
            for(i=1;i<=meio-1;i++)
                printf(" ");
            printf("***\n");
            printf("\n");
    }
    return 0;
}