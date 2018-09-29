#include <stdio.h>
#include <stdlib.h>


    int mochila_bomba (int* peso_bomba,int N,int carga_max,int* dano){ //Algoritmo da mochila binária para os cartuchos
    int y,i,a,b,c,aux;
    int resultado[N+1][carga_max+1];

    for(y=0;y<=carga_max;y++){
        resultado[0][y] =0;
        for(i=1;i<=N;i++){
            a = resultado[i-1][y];
            if(peso_bomba[i]> y ){
                b=0;
            }
            else {
                b = resultado[i-1][y-peso_bomba[i]] + dano[i];
            }

            if(a>b){
                resultado[i][y]=a;
            }
            else{
                resultado[i][y] = b;
            }
        }
    }



    return resultado[N][carga_max];
}

int main(){

	int casos,c,i;
	scanf("%d",&casos);

	int misseis,carga,castelo;

	for(c=1; c<=casos; c++){
		scanf("%d",&misseis);

		int poder[misseis + 1];
		int peso[misseis +1];

		for(i=1;i<=misseis;i++){
			scanf("%d %d",&poder[i],&peso[i]);
		}

		scanf("%d \n %d",&carga,&castelo);

		int resultado = mochila_bomba(peso,misseis,carga,poder);

		if(resultado>=castelo){
			printf("Missao completada com sucesso\n");
		}
		else{
			printf("Falha na missao\n");
		}

	}

    return 0;
}