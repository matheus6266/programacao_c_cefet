#include<stdio.h>
#include<locale.h>

FILE *file;
float notas[4], media_notas = 0;
char nome_materias[3][20] = {"Matemática", "Física", "Química"};
int i, status;


int main(){
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	
	printf("---------------Este programa solicita ao usário três notas (Matmática, Física e Química) e salva as notas em uma arquivo .txt------------------\n");
	printf("\n");
	
	for (i = 0; i <= 2; i ++){
		
		printf("Escreva sua nota em %s. \n", nome_materias[i]);
		scanf("%f", &notas[i]);
		
		media_notas = media_notas + notas[i];
	}
	
	
	media_notas = media_notas/3;
	
	file = fopen("notas", "w");
	
	if(file == NULL){
		
		printf("Erro ao abrir o programa. \n");
		return 1;
		
	}
	
	printf("O arquivo foi criado com sucesso. \n");
	
	printf("Iniciando a escrita.\n");
	
	
	for(i = 0; i <= 2; i++){
		
		fprintf(file,"Matéria: %s ", nome_materias[i]);
		fprintf(file,"Nota: %.2f\n", notas[i]);
		
		
	}
	
	fprintf(file, "\nMédia das notas: %.2f", media_notas);
	printf("Escrita finalizada.\n");
	
	status = fclose(file);
	
	if(status == 0){
		
		puts("Arquivo fechado com sucesso!\n");
		
	} else {
		
		puts("Erro ao fechar o arquivo !\n");
		
	}
	
	
	return 0;
	
}
