#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	char palavra[61];
	int i;
	int tamanho;
	long long int soma;
	int K = 1;




	while(scanf("%s",palavra)!=EOF){
		
		tamanho = strlen(palavra);
		soma = 0;
		for(i=0; i<tamanho; i++){
			if(palavra[i]=='b')
				
				soma = soma + pow(2,(tamanho-i)-1);
			
		}
		printf("Palavra %d\n",K );
		printf("%lld\n",soma);
		printf("\n");
		K++;

		
	}

	return 0;
}