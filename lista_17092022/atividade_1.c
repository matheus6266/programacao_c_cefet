#include<stdio.h>
#include<locale.h>

FILE *file;
float notas[4], media_notas = 0;
char nome_materias[3][20] = {"Matem�tica", "F�sica", "Qu�mica"};
int i, status;


int main(){
	
	setlocale(LC_ALL,""); // Utiliza��o dos caracteres na codifica��o UTF - 8
	
	printf("---------------Este programa solicita ao us�rio tr�s notas (Matm�tica, F�sica e Qu�mica) e salva as notas em uma arquivo .txt------------------\n");
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
		
		fprintf(file,"Mat�ria: %s ", nome_materias[i]);
		fprintf(file,"Nota: %.2f\n", notas[i]);
		
		
	}
	
	fprintf(file, "\nM�dia das notas: %.2f", media_notas);
	printf("Escrita finalizada.\n");
	
	status = fclose(file);
	
	if(status == 0){
		
		puts("Arquivo fechado com sucesso!\n");
		
	} else {
		
		puts("Erro ao fechar o arquivo !\n");
		
	}
	
	
	return 0;
	
}
