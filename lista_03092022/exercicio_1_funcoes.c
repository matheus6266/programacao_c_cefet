#include<stdio.h>
#include<math.h>
#include<locale.h>

float base, expoente, resultado;


int verifica_expoente(float expoente){
	
	/*Esta verifica se o expoente � maior ou igual a 1 e somente
	  realiza a exponecia��o se o expoente for maior que 1.
	*/
	
	int status_verificacao;
	
	if(expoente >= 1){
		
		status_verificacao = 1;
		
	} else {
		
		status_verificacao = 0;
	}
	
	return status_verificacao;
}


void potencia(float base, float expoente){
	
	/* Esta fun��o realiza a exponencia��o de dois n�meros cujo expoente
	   seja maior ou igual a 1.
	*/
	float resultado;
	
	if(verifica_expoente(expoente) == 1){
		
		resultado = pow(base, expoente);
		printf("O resultado da exponencia��o �: %.2f", resultado);
		
	} else {
		
		printf("O expoente � menor que 1 e a expoencia��o n�o foi realizada.\n");
	}
	
}

void main(){
	
	setlocale(LC_ALL,""); // Utiliza��o dos caracteres na codifica��o UTF - 8
	
	printf("-------Este programa realiza a potencia��o de n�meros inteiros com base");
	printf(" e expoente positivos e n�o nulos -----------\n");
	printf("\n");
	printf("Escreva o valor da base.\n");
	scanf("%f", &base);
	printf("Escreva o valor do expoente.\n");
	scanf("%f", &expoente);
	
	potencia(base, expoente);

}
