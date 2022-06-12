#include "menu.h"

void Menu() {
    Pilha P1;
    Pilha P2;
    int opcao;
    bool cont=true;

    while(cont) {
        printf("\n1 - Dividir equacao em duas pilhas\n2 - Escreve equacao infixa de modo posfixa e prefixa\n3 - Calcular co-primos\n4 - Calcular Fibonacci\n5 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                OptionEquation(&P1, &P2);
                break;
            
            case 2:
                printf("\nNos nao conseguimos fazer este exercicio!\n");
                break;
            
            case 3:
                OptionTotiente();
                break;

            case 4:
                OptionFibonacci();
                break;

            case 5:
                cont = false;
                break;

            default:
                printf("Opcao Invalida!");
                break;
        }
    }
}

void OptionEquation(Pilha *p1, Pilha *p2) {
	Item aux;

    char equacao[TAM];
    int tam;
	FPVazia(p1);
    FPVazia(p2);

    printf("\nInforme a equacao: ");
    scanf("%c", (char *) stdin);
    fgets(equacao,TAM,stdin);
    tam = strlen(equacao);

    for (int i = 0; i < tam; i++){
        if(equacao[i] >= '0' && equacao[i] <= '9'){
            aux.val = equacao[i];
            Push(p1,aux);
        }
        if(equacao[i] == '+' || equacao[i] == '-' || equacao[i] == '/' || equacao[i] == '*'){
            aux.val = equacao[i];
            Push(p2,aux);
        }
    }	
	PImprime2(p1, p2);
}

void OptionTotiente() {
    Pilha2 *p = malloc(sizeof(Pilha2));
	FP2Vazia(p);
	PreencheP(p);
	Coprimos(p);
}

void OptionFibonacci() {
    int n = 0;
	printf("\nDigite um valor para o calculo de Fibonacci: ");
	scanf("%d", &n);
	Fibonacci(n);
}