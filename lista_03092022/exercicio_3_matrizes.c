#include<stdio.h>
#include<locale.h>

float matriz_a[3][3];
float matriz_b[3][3];
float soma_matriz[3][3];


void soma_matrizes(float matriz_a[3][3], float matriz_b[3][3]){
	// Esta função realiza a soma de duas matrizes 3x3
	
	
	int i,j;
	
	printf("A matriz resultante da soma da matriz A e B é: \n");
	for(i = 0; i <= 2; i++){
		
		for(j = 0; j <= 2; j++){
			
			soma_matriz[i][j] = matriz_a[i][j] + matriz_b[i][j];
			printf("%.2f ", soma_matriz[i][j]);
			
		}
		
		printf("\n");
	}
}

int main(){
	
	int i, j;
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	
	printf("--------Este programa realiza a soma de duas matrizes 3x3-----------\n");
	printf("\n");
	
	// Preenchimento da matriz A
	
	printf("Preenchimento da Matriz A.\n");
	
	for(i = 0; i <= 2; i++){
		
		for(j = 0; j <= 2; j++){
			
			printf("Escreva o elemento da linha %d e coluna %d da matriz A.\n", i + 1, j + 1);
			scanf("%f", &matriz_a[i][j]);	
		}
	}
	
	// Preenchimento da matriz B
	
	printf("Preenchimento da Matriz B.\n");
	
	for(i = 0; i <= 2; i++){
		
		for(j = 0; j <= 2; j++){
			
			printf("Escreva o elemento da linha %d e coluna %d da matriz B.\n", i + 1, j + 1);
			scanf("%f", &matriz_b[i][j]);
			
		}
	}
	
	
	soma_matrizes(matriz_a, matriz_b);
	
	return 0;
	
}


