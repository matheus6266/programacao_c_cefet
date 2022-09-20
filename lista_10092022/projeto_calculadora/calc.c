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
		
		printf("Este n�mero � par !\n");
		
	} else {
		
		printf("Este n�mero � �mpar !\n");
	}
	
	return 0;
	
	}
	
int multiplo(int x, int y){
	
	if((x % y) == 0){
		
		printf("O %d � m�ltiplo de %d", x, y);
		
	} else {
		
		printf("O %d n�o � m�ltiplo de %d", x, y);
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
		
		printf("O n�mero %d � primo!", x);
		
	} else {
		
		printf("O n�mero %d n�o � primo !", x);
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
	
	printf("------------Este programa realiza c�lculos escolhidos pelo usu�rio-------------");
	printf("\n");
	
	while(1){
		
		printf("Digite a op��o desejada:");
		printf("\n");
		printf("0 - Sair\n");
		printf("1 - Somar dois n�meros\n");
		printf("2 - Substrair dois n�meros\n");
		printf("3 - Multiplicar dois n�meros\n");
		printf("4 - Dividir dois n�meros\n");
		printf("5 - Resto da divis�o de dois n�meros\n");
		printf("6 - Quadrado de um n�mero\n");
		printf("7 - Cubo de um n�mero\n");
		printf("8 - Saber se um n�mero � par\n");
		printf("9 - Saber se um n�mero � multiplo de outro\n");
		printf("10 - Saber se um n�mero � primo\n");
		printf("11 - Calcular o seno de um �ngulo (graus)\n");
		printf("12 - Calcular o cosseno de um �ngulo (graus)\n");
		printf("13 - Calcular o logartimo de base 10 de um n�mero\n");
		
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
		
			printf("Voc� escolheu a op��o SOMA. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%f", &x);
			printf("Escreva o n�mero y.\n");
			scanf("%f", &y);
			resultado = soma(x, y);
			printf("A soma de %.2f + %.2f � %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 2:
		
			printf("Voc� escolheu a op��o SUBTRA��O. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%f", &x);
			printf("Escreva o n�mero y.\n");
			scanf("%f", &y);
			resultado = subtracao(x, y);
			printf("A subtracao de %.2f - %.2f � %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 3:
			
			
			printf("Voc� escolheu a op��o MULTIPLICA��O. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%f", &x);
			printf("Escreva o n�mero y.\n");
			scanf("%f", &y);
			resultado = produto(x, y);
			printf("O produto de %.2f * %.2f � %.2f. \n", x, y, resultado);
			printf("\n");
			break;
			
		case 4:
			
			
			printf("Voc� escolheu a op��o DIVISAO. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%f", &x);
			printf("Escreva o n�mero y.\n");
			scanf("%f", &y);
			resultado = divisao(x, y);
			printf("A divisao de %.2f / %.2f � %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 5:
			
			
			printf("Voc� escolheu a op��o RESTO DA DIVIS�O. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%f", &x);
			printf("Escreva o n�mero y.\n");
			scanf("%f", &y);
			resultado = resto_divisao(x, y);
			printf("O resto da divis�o de %.2f por %.2f � %.2f. \n", x, y, resultado);
			printf("\n");
			break;
		
		case 6:
			
			
			printf("Voc� escolheu a op��o QUADRADO. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%f", &x);
			resultado = quadrado(x);
			printf("O quadrado de %.2f � %.2f\n", x, resultado);
			printf("\n");
			break;
			
		case 7:
			
			
			printf("Voc� escolheu a op��o CUBO. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%f", &x);
			resultado = cubo(x);
			printf("O cubo de %.2f � %.2f\n", x, resultado);
			printf("\n");
			break;
			
		case 8:
			
			
			printf("Voc� escolheu a op��o SABER SE O N�MERO � PAR. \n");
			printf("\n");
			printf("Escreva o n�mero x.\n");
			scanf("%d", &x_int);
			par(x_int);
			printf("\n");
			break;
		
		case 9:
			
			
			printf("Voc� escolheu a op��o SABER SE O N�MERO � M�LTIPLO. \n");
			printf("\n");
			printf("Escreva o n�mero x. \n");
			scanf("%d", &x_int);
			printf("Escreva o n�mero y. \n");
			scanf("%d", &y_int);
			multiplo(x_int, y_int);
			printf("\n");
			break;
			
		case 10:
			
			printf("Voc� escolheu a op��o SABER SE O N�MERO � PRIMO. \n");
			printf("\n");
			printf("Escreva o n�mero x. \n");
			scanf("%d", &x_int);
			primo(x_int);
			printf("\n");
			break;
			
		case 11:
			
			printf("Voc� escolheu a op��o SENO. \n");
			printf("\n");
			printf("Escreva o n�mero x. \n");
			scanf("%f", &x);
			resultado = seno(x);
			printf("O valor do seno de %.2f � %.2f .\n", x, resultado);
			printf("\n");
			break;
			
		case 12:
			
			printf("Voc� escolheu a op��o COSSENO. \n");
			printf("\n");
			printf("Escreva o n�mero x. \n");
			scanf("%f", &x);
			resultado = cosseno(x);
			printf("O valor do COSSENO de %.2f � %.2f .\n", x, resultado);
			printf("\n");
			break;
			
		case 13:
			
			
			printf("Voc� escolheu a op��o LOGARITMO 10. \n");
			printf("\n");
			printf("Escreva o n�mero x. \n");
			scanf("%f", &x);
			resultado = logaritmo(x);
			printf("O valor do LOGARITMO de %.2f � %.2f .\n", x, resultado);
			printf("\n");
			break;
		
		default:
			 
			printf("Valor digitado esta incorreto.\n");
			break;
		
	}
	
	
}

