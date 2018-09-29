#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	char nome[100050][15];
	int pnt[100050];
	int i,N,j,empate;
	long int  totalB, totalA, B_peso,A_peso;

	while(scanf("%d",&N) != 0){

		if(N==0)
			break;
		totalA = totalB = B_peso = A_peso =0;

		empate = 0;

		for(i=1;i<=N;i++){
			scanf("%s",nome[i]);
			pnt[i] = 0;
			for(j=0;j<strlen(nome[i]);j++){
				pnt[i] = pnt[i] + nome[i][j]; //soma o total de pontos para cada nome
		
			}
			totalB = totalB + pnt[i]; // Total de pontos para o timeB sem pesos, considerando o time B como um time com todos os membros 
			B_peso = B_peso + (pnt[i] * i); // Adiciona os pesos crescentes para o time B
		}
	
		for(i=1;i<=N;i++){ 
			B_peso = B_peso - totalB; // O novo B_peso, que será comparado é diminuido uma posição na escala de pesos. ou seja, o que era 4ª posição agora é a 3ª
			totalA = totalA + pnt[i]; // O Total A é adicionado um elemento. Se for o primeiro laço do for o time A terá apenas o primeiro nome
			A_peso = A_peso + totalA; // A_peso é igaul a pontuação anterior + a pontuação do novo membro do time + A pontuação antiga de Total A.
			totalB = totalB - pnt[i]; // Tira um elemento de B para rodar o prox laço

			if(B_peso == A_peso){ // Se tiverem a pontuação igual é empate
				empate = i; // O nome que dá o empate é a posição em que para o laço for
				break;
			}

			
		}

		if(empate == 0){
			printf("Impossibilidade de empate.\n");
		}
		else {
			printf("%s\n",nome[empate]);
		}

	}

	return 0;
} 
