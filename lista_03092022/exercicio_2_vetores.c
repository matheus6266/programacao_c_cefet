#include<stdio.h>
#include<locale.h>

int vetor[10];


void ordena_vetor(int vetor[10]){
	// Fun��o que ordena um vetor em ordem crescente
	
	int j,i, auxiliar;
	
	for(i = 1; i < 10; i++){
		
		auxiliar = vetor[i];
		j = i - 1;
		
		while((j >= 0) && (vetor[j] > auxiliar)){
			
			vetor[j + 1] = vetor[j];
			j = j - 1;
			
		}
		
		vetor[j + 1] = auxiliar;
	}
	
	
	printf("O vetor ordenado �: \n");
	printf("\n");
	
	for(i = 0; i <= 9; i++){
		
		printf("%d ", vetor[i]);
	}
	
}


int main(){
	
	int i;
	setlocale(LC_ALL,""); // Utiliza��o dos caracteres na codifica��o UTF - 8
	
	printf("----------Este programa ordena um vetor de tamanho 10 em ordem crescente-------------\n");
	printf("\n");
	
	for(i = 0; i<=9; i++){
		
		printf("Informe o n�mero da posi��o %d do vetor.\n", i+1);
		scanf("%d", &vetor[i]);
	}
		
	ordena_vetor(vetor);
	
	return 0;
	
}

