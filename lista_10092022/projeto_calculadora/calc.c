#include "calc.h"

float soma(float x, float y){
	
	return x + y;
}

float subtracao(float x, float y){
	
	return x - y;
}

float produto(float x, float y){
	
	return x * y;
}

float divisao(float x, float y){
	
	return x/y;
}

float quadrado(float x){
	
	return pow(x ,2);
}

float cubo(flaot x){
	
	return pow(x, 3);
}

int resto_divisao(int x, int y){
	
	return x % y;
}

int par(int x){
	
	if(x % 2 == 0){
		
		printf("Este número é par !\n");
		
	} else {
		
		printf("Este número é ímpar !\n");
	}
	
	return 0;
	
	}
	
int multiplo(int x, int y){
	
	if(x%y == 0){
		
		printf("O %d é múltiplo de %d", x, y);
	} else {
		
		printf("O %d não é múltiplo de %d", x, y);
	}
	
	return 0;
	
}

int primo(int x){
	
	int = i, auxiliar = 0;
	
	for(i = 1; i <= 9, i++){
		
		if(x%i == 0){
			
			auxiliar = auxiliar + 1;	
		}		
	}
	
	if(auxiliar > 1){
		
		printf("O número %d não é primo!", x);
		
	} else {
		
		printf("O número %d é preimo !", x);
	}
	
	return 0;
}

float seno(float x){
	
	return sin(x);
}

float cosseno(float x){
	
	return cos(x);
	
}
int logaritmo(int x){
	
	return log10(10);
}
void menu(){
	
	int opcao_digitada = 1, retorno = 1;
	
	printf("------------Este programa realiza cálculos escolhidos pelo usuário-------------");
	printf("\n");
	
	while(retorno =! 0){
		
		printf("Digite a opção desejada:");
		printf("\n");
		printf("0 - Sair\n");
		printf("1 - Somar dois números\n");
		printf("2 - Substrair dois números\n");
		printf("3 - Multiplicar dois números\n");
		printf("4 - Dividir dois números\n");
		printf("5 - Resto da divisão de dois números\n");
		printf("6 - Quadrado de um número\n");
		printf("7 - Cubo de um número\n");
		printf("8 - Saber se um número é par\n");
		printf("9 - Saber se um número é multiplo de outro\n");
		printf("10 - Saber se um número é primo\n");
		printf("11 - Calcular o seno de um ângulo\n");
		printf("12 - Calcular o cosseno de um ângulo\n");
		printf("13 - Calcular o logartimo de base 10 de um número\n");
			
		scanf("%d", &opcao_digitada);
			
		retorno = execucao(opcao_digitada);
		
	}
}
void execucao(int opcao_digitada){
	
	case 0:
		
		printf("Fim do programa !");
		printf("\n");
		
		return 0;
	
	case 1:
		
	
	
}

