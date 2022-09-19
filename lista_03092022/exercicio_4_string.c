#include<stdio.h>
#include<stdio.h>
#include<locale.h>

void cadastro_usuarios(){
	/*	
		Esta função realiza o cadastro dos usuários
	*/
	
	int i = 0;
	float soma_cadastros = 0;
	int vetor_idades[100];
	int k = 0;
	float soma_idades = 0;
	char matriz_nomes[100][20];
	char resposta[20];
	
	
	while(1){
		
		printf("Informe o nome do %d° cadastro: \n", i+1);
		scanf("%s", matriz_nomes[i]);
		printf("Informe a idade do %dº usuário: \n", i+1);
		scanf("%d", &vetor_idades[i]);
		printf("\n");
		
		printf("Desdeja continuar o cadastro? \n");
		printf("Digite o 'c' para continuar e 's' para sair. \n");
		scanf("%s", resposta);
		
		if(('c' == resposta[0]) || ('C' == resposta[0])){
			
			soma_cadastros++;
			i++;
	
		}else if(('s' == resposta[0]) || ('S' == resposta[0])){
			
			printf("Fim do cadastro de usuários.\n");
			soma_cadastros++;
			i++;
			break;
			
		}else {
			
			printf("O valor digitado não foi o correto. \n");
			soma_cadastros++;
			i++;
			break;
		}
		
	}
	
	printf("Lista dos nomes e idades dos usuários cadastrados.\n");
	printf("\n");
	

	for(k = 0; k <= i-1; k++){
		
		soma_idades = vetor_idades[k] + soma_idades;
		
		printf("%s ", matriz_nomes[k]);
		printf("%d", vetor_idades[k]);
		printf("\n");
		
	}
	
	printf("\n");
	printf("Foram cadastrados %.0f usuários e a média das idades dos mesmos foi %.2f anos.\n", soma_cadastros, (soma_idades/soma_cadastros));
	
}

int main(){
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	
	cadastro_usuarios();
	return 0;
}
