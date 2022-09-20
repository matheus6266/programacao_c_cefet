#include "calc.h"
#include<stdio.h>
#include<math.h>
# define pi 3.141592653589793238462643383279502884

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

float cubo(float x){
	
	return pow(x, 3);
}

int resto_divisao(int x, int y){
	
	return x % y;
}

int par(int x){
	
	if((x % 2) == 0){
		
		printf("Este número é par !\n");
		
	} else {
		
		printf("Este número é ímpar !\n");
	}
	
	return 0;
	
	}
	
int multiplo(int x, int y){
	
	if((x % y) == 0){
		
		printf("O %d é múltiplo de %d", x, y);
		
	} else {
		
		printf("O %d não é múltiplo de %d", x, y);
	}
	
	return 0;
	
}

int primo(int x){
	
	int i, auxiliar = 0, compara;
	
	compara = x;
	
	for(i = 1; i <= compara; i++){
		
		if(x % i == 0){
			
			auxiliar = auxiliar + 1;	
		}		
	}
	
	if(auxiliar == 2){
		
		printf("O número %d é primo!", x);
		
	} else {
		
		printf("O número %d não é primo !", x);
	}
	
	return 0;
}

float seno(float x){
	
	float conversao_angulo_radiano;
	
	conversao_angulo_radiano = (x*pi)/180;
	
	return sin(conversao_angulo_radiano);
}

float cosseno(float x){
	
	float conversao_angulo_radiano;
	
	conversao_angulo_radiano = (x*pi)/180;
	
	return cos(conversao_angulo_radiano);
	
}

float logaritmo(float x){
	
	return log10(x);
}
void menu(){
	
	int opcao_digitada;
	
	printf("------------Este programa realiza cálculos escolhidos pelo usuário-------------");
	printf("\n");
	
	while(1){
		
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
		printf("11 - Calcular o seno de um ângulo (graus)\n");
		printf("12 - Calcular o cosseno de um ângulo (graus)\n");
		printf("13 - Calcular o logartimo de base 10 de um número\n");
		
		scanf("%d", &opcao_digitada);
		
		if(opcao_digitada == 0) {
			
			printf("Fim do programa !");
			printf("\n");
			break;
			
		} else {
			
			execucao(opcao_digitada);
		}
		
	}
}
void execucao(int opcao_digitada){
	
	float x, y, resultado;
	int x_int, y_int;
	
	switch(opcao_digitada){
		
		case 1:
		
			printf("Você escolheu a opção SOMA. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%f", &x);
			printf("Escreva o número y.\n");
			scanf("%f", &y);
			resultado = soma(x, y);
			printf("A soma de %.2f + %.2f é %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 2:
		
			printf("Você escolheu a opção SUBTRAÇÂO. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%f", &x);
			printf("Escreva o número y.\n");
			scanf("%f", &y);
			resultado = subtracao(x, y);
			printf("A subtracao de %.2f - %.2f é %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 3:
			
			
			printf("Você escolheu a opção MULTIPLICAÇÃO. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%f", &x);
			printf("Escreva o número y.\n");
			scanf("%f", &y);
			resultado = produto(x, y);
			printf("O produto de %.2f * %.2f é %.2f. \n", x, y, resultado);
			printf("\n");
			break;
			
		case 4:
			
			
			printf("Você escolheu a opção DIVISAO. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%f", &x);
			printf("Escreva o número y.\n");
			scanf("%f", &y);
			resultado = divisao(x, y);
			printf("A divisao de %.2f / %.2f é %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 5:
			
			
			printf("Você escolheu a opção RESTO DA DIVISÃO. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%f", &x);
			printf("Escreva o número y.\n");
			scanf("%f", &y);
			resultado = resto_divisao(x, y);
			printf("O resto da divisão de %.2f por %.2f é %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 6:
			
			
			printf("Você escolheu a opção QUADRADO. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%f", &x);
			resultado = quadrado(x);
			printf("O quadrado de %.2f é %.2f\n", x, resultado);
			printf("\n");
			break;
			
		case 7:
			
			
			printf("Você escolheu a opção CUBO. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%f", &x);
			resultado = cubo(x);
			printf("O cubo de %.2f é %.2f\n", x, resultado);
			printf("\n");
			break;
			
		case 8:
			
			
			printf("Você escolheu a opção SABER SE O NÚMERO É PAR. \n");
			printf("\n");
			printf("Escreva o número x.\n");
			scanf("%d", &x_int);
			par(x_int);
			printf("\n");
			break;
		
		case 9:
			
			
			printf("Você escolheu a opção SABER SE O NÚMERO É MÚLTIPLO. \n");
			printf("\n");
			printf("Escreva o número x. \n");
			scanf("%d", &x_int);
			printf("Escreva o número y. \n");
			scanf("%d", &y_int);
			multiplo(x_int, y_int);
			printf("\n");
			break;
			
		case 10:
			
			printf("Você escolheu a opção SABER SE O NÚMERO É PRIMO. \n");
			printf("\n");
			printf("Escreva o número x. \n");
			scanf("%d", &x_int);
			primo(x_int);
			printf("\n");
			break;
			
		case 11:
			
			printf("Você escolheu a opção SENO. \n");
			printf("\n");
			printf("Escreva o número x. \n");
			scanf("%f", &x);
			resultado = seno(x);
			printf("O valor do seno de %.2f é %.2f .\n", x, resultado);
			printf("\n");
			break;
			
		case 12:
			
			printf("Você escolheu a opção COSSENO. \n");
			printf("\n");
			printf("Escreva o número x. \n");
			scanf("%f", &x);
			resultado = cosseno(x);
			printf("O valor do COSSENO de %.2f é %.2f .\n", x, resultado);
			printf("\n");
			break;
			
		case 13:
			
			
			printf("Você escolheu a opção LOGARITMO 10. \n");
			printf("\n");
			printf("Escreva o número x. \n");
			scanf("%f", &x);
			resultado = logaritmo(x);
			printf("O valor do LOGARITMO de %.2f é %.2f .\n", x, resultado);
			printf("\n");
			break;
		
		default:
			 
			printf("Valor digitado esta incorreto.\n");
			break;
		
	}
	
	
}

