#include<stdio.h>
#include<locale.h>

FILE *file;
float sequencia_numeros[100], media_sequencia = 0;
int i, k, status;

int main(){
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	printf("------------Este programa salva um vetor de números até o usuário digitar 0 e grava a sequência em um arquivo .txt--------------");
	printf("\n");
	
	for(i = 0; i <= 99; i++){
		
		printf("Digite o %d número da sequência.\n", i +1);
		scanf("%f", &sequencia_numeros[i]);
		
		media_sequencia = media_sequencia + sequencia_numeros[i];
		
		if(sequencia_numeros[i] == 0){
			printf("Fim da sequência. \n");
			printf("\n");
			break;
		}
		
	
	}
	
	media_sequencia = media_sequencia / (i + 1);
	
	file = fopen("dados", "w");
	
	if(file == NULL){
		
		printf("Erro ao abrir o programa. \n");
		return 1;
		
	}
	
	printf("O arquivo foi criado com sucesso. \n");
	
	printf("Iniciando a escrita.\n");
	
	
	for(k = 0; k <= i; k++){
		
		fprintf(file,"%.2f\n", sequencia_numeros[k]);
		
	}
	
	fprintf(file, "\nMédia dos números é: %.2f", media_sequencia);
	printf("Escrita finalizada.\n");
	
	status = fclose(file);
	
	if(status == 0){
		
		puts("Arquivo fechado com sucesso!\n");
		
	} else {
		
		puts("Erro ao fechar o arquivo !\n");
		
	}
	
	return 0;
}
