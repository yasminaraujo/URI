#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int C,B,E;
    int i;
    char espelho[50000];

    scanf("%d",&C);

    while(C!=0){
        scanf("%d%d",&B,&E);
        for (i=B;i<=E;i++){
            sprintf(&espelho[strlen(espelho)],"%d",i);
            printf("%d",i);
        }
        for(i=strlen(espelho)-1;i>=0;i--)
            printf("%c",espelho[i]);
        printf("\n");

        C--;
        espelho[0]='\0';
    }
    return 0;
}