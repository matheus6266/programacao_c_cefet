#include<stdio.h>
#include<math.h>
#include<locale.h>

int base, expoente, resultado;


int verifica_expoente(int expoente){
	
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


void potencia(int base, int expoente){
	
	/* Esta fun��o realiza a exponencia��o de dois n�meros cujo expoente
	   seja maior ou igual a 1.
	*/
	
	
	if(verifica_expoente(expoente) == 1){
		
		resultado = pow(base, expoente);
		printf("O resultado da exponencia��o �: %d", resultado);
		
	} else {
		
		printf("O expoente � menor que 1 e a expoencia��o n�o foi realizada.\n");
	}
	
}

void main(){
	
	setlocale(LC_ALL,""); // Utiliza��o dos caracteres na codifica��o UTF - 8
	
	printf("-------Este programa realiza a potencia��o de n�meros inteiros com base");
	printf(" e expoente inteiros positivos e n�o nulos -----------\n");
	printf("\n");
	printf("Escreva o valor da base.\n");
	scanf("%d", &base);
	printf("Escreva o valor do expoente.\n");
	scanf("%d", &expoente);
	
	potencia(base, expoente);

}
