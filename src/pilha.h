#ifndef PILHA_H 
#define PILHA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#define TAM 30
#define MAXTAM 20

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;
typedef struct PItem PItem;
typedef struct Pilha2 Pilha2;

struct Item{
	char val;
};

struct Block{
	Item data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};

typedef struct Pitem{
	long long val;
	int n;
	int pos;
}Pitem;

typedef struct Pilha2{
	Pitem vet[MAXTAM];
	int top;
	int base;
}Pilha2;

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime2(Pilha *p,Pilha *p2);

void FP2Vazia(Pilha2 *p);
void PUSH(Pilha2 *p, Pitem d);
void POP(Pilha2 *p);
void PrintP(Pilha2 *p);
void PreencheP(Pilha2 *p);

int totiente(int a, int b);
void Coprimos(Pilha2 *p);

void Fibonacci(int n);

#endif