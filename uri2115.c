#include <stdio.h>
#include <stdlib.h>

typedef struct task{
	int tempo,dura;
}tarefas;

int compare(const void * a, const void * b)
{
	if(((tarefas*)a)->tempo < ((tarefas*)b)->tempo){
		return -1;
	}
	else if (((tarefas*)a)->tempo > ((tarefas*)b)->tempo){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int N,i,final;

	while(scanf("%d",&N)!=EOF){
		if(N == EOF)
			break;
		tarefas tarefa[N];
		for(i=0;i<N;i++){
			scanf("%d%d",&tarefa[i].tempo,&tarefa[i].dura);
		}
		qsort(tarefa,N,sizeof(tarefas),compare);
		
		final = tarefa[0].tempo + tarefa[0].dura;


		for(i=1; i<N;i++){
			if(final<tarefa[i].tempo){
				final = tarefa[i].tempo;		
			}
			final+=tarefa[i].dura;

		}

		printf("%d\n",final);
	}
	return 0;
}