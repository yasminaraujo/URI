#include <stdio.h>
#include<stdlib.h>

typedef struct Celula *Apontador;

typedef struct Celula {
int carta;
Apontador Prox;
} Celula;

typedef struct TipoFila {
Apontador Frente, Tras;
} TipoFila;

void FFVazia (TipoFila *Fila){
	Fila->Frente = (Apontador) malloc(sizeof(Celula));
	Fila->Tras = Fila->Frente;
	Fila->Frente->Prox = NULL;
}

void Enfileira (int x, TipoFila *Fila){
	Fila->Tras->Prox = (Apontador) malloc(sizeof(Celula));
	Fila->Tras = Fila->Tras->Prox;
	Fila->Tras->carta = x;
	Fila->Tras->Prox = NULL;
}

void Descarta (TipoFila *Fila, int* Descarte, int tam){
	int descartada = Fila->Frente->Prox->carta;
	//printf("%d\n",Fila->Frente->carta );
	Descarte[tam] = descartada;
	Fila->Frente->Prox= Fila->Frente->Prox->Prox;
}

void ColocaBase (TipoFila *Fila){
	Apontador q = Fila->Frente->Prox;
	Fila->Frente->Prox = Fila->Frente->Prox->Prox;
	Fila->Tras->Prox = q;
	Fila->Tras = q;
}

int main()
{
	int n,i;

	while(scanf("%d",&n)!=0){
		if(n==0){
			break;
		}
		int descartadas[50];
		int tamanho,indice;
		TipoFila fila;

		FFVazia(&fila);
		tamanho = n;
		indice = 0;

		for(i=1;i<=n;i++){
			Enfileira(i,&fila);
		}

		while (tamanho != 1){
			Descarta(&fila,descartadas,indice);
			indice++;
			tamanho--;
			ColocaBase(&fila);
		}
		printf("Discarded cards: 1, ");
		for(i=1;i<indice;i++){
			printf("%d",descartadas[i]);
			if(i != (indice-1)){
				printf(", ");
			}
		}
		printf("\n");

		printf("Remaining card: %d\n",fila.Tras->carta);
	}
	return 0;
}