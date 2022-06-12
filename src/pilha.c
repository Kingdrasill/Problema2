#include "pilha.h"

void FPVazia(Pilha *p){
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d){
	Block *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}

void PImprime2(Pilha *p,Pilha *p2){
	Block *aux;
	printf("Numeros\n");
	aux = p->top;
	while(aux != p->base){
		printf("%c\n", aux->data.val);
		aux = aux->prox;
	}

	printf("Operandos:\n");
	aux = p2->top;
	while(aux != p2->base){
		printf("%c\n", aux->data.val);
		aux = aux->prox;
	}

}

void FP2Vazia(Pilha2 *p){
	p->top   = 0;
	p->base  = 0;
}


void PUSH(Pilha2 *p, Pitem d){
	if (p->top >= MAXTAM){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha2 *p){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
	}
}

void PreencheP(Pilha2 *p){
	Pitem aux;
	aux.n = 0;
	for (int cont = 0; cont < MAXTAM; cont++){
		aux.n = rand()%100;
		PUSH(p, aux);
	}
}

int totiente(int a, int b){
	if(a == 0 || b == 0){
		return 0;
	}
	if(a == b){
		return a;
	}
	if(a > b){
		return totiente(a-b, b);
	}			
	return totiente(a, b-a);
}

void Coprimos(Pilha2 *p){
	for(int cont = 0; cont < MAXTAM; cont++){
		printf("\nNúmeros co-primos de %d: ", p->vet[p->top-1].n);
		for(int cont2 = 1; cont2 < p->vet[p->top-1].n; cont2++){
			if(totiente(p->vet[p->top-1].n, cont2) == 1){
				printf("%d ", cont2);
			}
		}
		POP(p);
	}
	printf("\n");
}

void Fibonacci(int n){
	Pilha2 *p = malloc(sizeof(Pilha2));
	FP2Vazia(p);
	Pitem aux;
	aux.val = 0;
	Pitem aux1;
	aux1.val = 0;
	for(int cont = 0; cont <= n; cont++){
		if(cont >= 2){
			if(p->vet[p->top-1].pos == cont-1){
				aux1 = p->vet[p->top-1];
				POP(p);
				aux.val = p->vet[p->top-1].val + aux1.val;
				aux.pos = cont;
				POP(p);
				PUSH(p, aux1);
				PUSH(p, aux);
			}else{
				printf("Erro no cálculo.");
			}
		}else{
			aux.val = cont;
			aux.pos = cont;
			PUSH(p, aux);
		}
	}
	printf("O valor de Fibonacci para %d é %lld.\n", n, p->vet[p->top-1].val);
}