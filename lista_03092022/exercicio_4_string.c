#include<stdio.h>
#include<locale.h>

void cadastro_usuarios(){
	
	
	int i = 1;
	int vetor_idades[5];
	int k;
	float soma_idades = 0;
	char matriz_nomes[5][20];
	char resposta;
	
	//https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
	
	while(1){
		
		printf("Informe o nome do %d° cadastro: \n", i);
		scanf("%s", &matriz_nomes[i - 1]);
		printf("Informe a idade do %dº usuário: \n", i);
		scanf("%d", &vetor_idades[i - 1]);
		printf("\n");
		
		printf("Desdeja continuar o cadastro? \n");
		printf("Digite o 'c' para continuar e 's' para sair. \n");
		scanf("%s", &resposta);
		
		if('c' == resposta){
			
			i++;
			printf("%d\n", i);
	
		}else if('s' == resposta){
			
			printf("Fim do cadastro de usuários.\n");
			printf("oi\n");
			break;
			
		}else {
			
			printf("O valor digitado não foi o correto. \n");
			break;
		}
		
	}
	
	printf("Lista dos nomes e idades dos usuários cadastrados.\n");
	printf("\n");
	

	for(k = 0; k <= i - 1; k++){
		
		soma_idades = vetor_idades[k] + soma_idades;
		
		printf("%s ", matriz_nomes[k]);
		printf("%d", vetor_idades[k]);
		printf("\n");
		
	}
	
	printf("\n");
	printf("Foram cadastrados %d usuários e a média das idades dos mesmos foi %.2f anos.\n", i, soma_idades/i);
	
	
	
}

int main(){
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	
	cadastro_usuarios();
	return 0;
}
