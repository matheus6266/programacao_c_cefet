#include<stdio.h>
#include<string.h>
#include<locale.h>



struct produto {
	
	char nome[30];
	int codigo;
	double preco;
	
};

struct produto produtos_cadastrados[10];

void cadastro_itens(){
	
	
	strcpy(produtos_cadastrados[0].nome, "Pe de Moleque");
	produtos_cadastrados[0].codigo = 13205;
	produtos_cadastrados[0].preco = 0.2;
	
	strcpy(produtos_cadastrados[1].nome, "Cocada Baiana");
	produtos_cadastrados[1].codigo = 15202;
	produtos_cadastrados[1].preco = 0.5;
		
	
}

void imprimir_itens(){

	
	printf("------------------Impressão dos Itens------------------\n");
	printf("\n");
	
	printf("Nome Produto: %s \n", produtos_cadastrados[0].nome);
	printf("Código do Produto: %d\n", produtos_cadastrados[0].codigo);
	printf("Preço do Produto: R$ %.2lf\n", produtos_cadastrados[0].preco);
	printf("\n");
	
	printf("Nome Produto: %s \n", produtos_cadastrados[1].nome);
	printf("Código do Produto: %d\n", produtos_cadastrados[1].codigo);
	printf("Preço do Produto: R$ %.2lf\n", produtos_cadastrados[1].preco);
	printf("\n");
	
	
}


int main(){
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	cadastro_itens();
	imprimir_itens();
	
	return 0;
}
