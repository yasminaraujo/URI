#include <stdio.h>
#include <stdlib.h>


    int mochila_cartucho (int* musicas,int N,int cart){ //Algoritmo da mochila binária para os cartuchos
    int y,i,a,b,c,aux;
    int resultado[N+1][cart+1];

    for(y=0;y<=cart;y++){
        resultado[0][y] =0;
        for(i=1;i<=N;i++){
            a = resultado[i-1][y];
            if(musicas[i]> y ){
                b=0;
            }
            else {
                b = resultado[i-1][y-musicas[i]] + musicas[i];
            }

            if(a>b){
                resultado[i][y]=a;
            }
            else{
                resultado[i][y] = b;
            }
        }
    }

    //achar os inseridos
    i=N;
    b=cart;
    aux = resultado[i][b];

    while(aux){
        if(resultado[i][b] != resultado[i-1][b]){
            b-=musicas[i];
            musicas[i] = 0;
        }
        i--;
        aux= resultado[i][b];
    }

    return resultado[N][cart];
}
void copia(int* musicas, int* auxilia, int tam){//função para criar um vetor auxiliar
    int i;
    for(i=1;i<=tam;i++){
        auxilia[i]= musicas[i];
    }
}


        int Permuta (int* music, int tam, int a,int b,int c){
           int auxiliar[tam+2];
            int i;

            for (i=1;i<=tam;i++){
                auxiliar[i] = music[i];
            }
            int aux = mochila_cartucho(auxiliar,tam,a) + mochila_cartucho(auxiliar,tam,b) + mochila_cartucho(auxiliar,tam,c);
            return aux;
        }
int main(){

    int N,K,soma,i,b,aux;
    int somas[7];

    while(scanf("%d",&N)!=EOF){
        if(N == EOF)
            break;
        scanf("%d",&K);

        int cartuchos[K+1];

        int musicas[N+1];
        int auxilia[N+1];

        for(i=1;i<=N;i++){
            scanf("%d",&musicas[i]);

        }
        for(i=1;i<=K;i++)
            scanf("%d",&cartuchos[i]);
        soma = 0;
        int auxi;
        copia(musicas,auxilia,N);
        for(i=1;i<=K;i++){//testa a ordem de entrada
            auxi = mochila_cartucho(auxilia,N,cartuchos[i]);
            soma += auxi;
        }
        copia(musicas,auxilia,N);

            for(i=K;i>=1;i--){//testa a ordem inversa
                auxi = mochila_cartucho(auxilia,N,cartuchos[i]);
                somas[1] += auxi;
            }
            if(somas[1]>somas[0])
                soma = somas[1];

        copia(musicas,auxilia,N);

        if(K==3){//Para três cartuchos, testa todas as permutações
            somas[0] = Permuta(musicas,N,cartuchos[1],cartuchos[2],cartuchos[3]);
            somas[1] = Permuta(musicas,N,cartuchos[1],cartuchos[3],cartuchos[2]);
            somas[2] = Permuta(musicas,N,cartuchos[2],cartuchos[3],cartuchos[1]);
            somas[3] = Permuta(musicas,N,cartuchos[2],cartuchos[1],cartuchos[3]);
            somas[4] = Permuta(musicas,N,cartuchos[3],cartuchos[1],cartuchos[2]);
            somas[5] = Permuta(musicas,N,cartuchos[3],cartuchos[2],cartuchos[1]);

            for(i=0;i<6;i++){
                if(somas[i] > soma)
                    soma = somas[i];
            }
        }

        printf("%d\n",soma);
    }
    return 0;
}