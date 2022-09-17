#include<stdio.h>
#include<locale.h>

FILE *file;
char nome_arquivo[20];
char meu_nome[25] = "Matheus Barros Oliveira";
char temp[255];
int linha_atual = 1;
int status, fechou;

int main(){
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	
	printf("---------Este programa escreve e abre um arquivo-----------\n");
	printf("Escreva o nome que você deseja adicionar ao arquivo com a extensão.\n");
	scanf("%s", &nome_arquivo);
	
	file = fopen(nome_arquivo, "w");
	
	if(file == NULL){
		
		printf("Erro ao abrir o programa. \n");
		return 1;
		
	}
	
	printf("O arquivo foi criado com sucesso. \n");
	
	printf("Iniciando a escrita.\n");
	fprintf(file,"Olá o meu nome é %s e este arquivo se chama %s.\n", meu_nome, nome_arquivo);
	printf("Escrita finalizada.\n");
	
	status = fclose(file);
	
	if(status == 0){
		
		puts("Arquivo fechado com sucesso!\n");
		
	} else {
		
		puts("Erro ao fechar o arquivo !\n");
		
	}
	
	file = fopen(nome_arquivo, "r");
	
	if(file == NULL){
		
		printf("Erro ao abrir o programa. \n");
		return 1;
		
	}
	
	printf("O arquivo foi aberto com sucesso. \n");
	printf("Iniciando a leitura");
	
	while(fgets(temp, 255, file) != NULL){
		
		printf("Linha %d = ", linha_atual++);
		printf(temp);
	}
	
	printf("Leitura finalizada.\n");
	
	fechou = fclose(file);
	
	if(fechou == 0){
		
		printf("Arquivo fechado com sucesso!\n");
		
	} else {
		
		printf("Erro ao fechar o arquivo !\n");
	}
	
	return 0;
	
}
