#include "dissipi.h"
#include <stdio.h>

void menu_escolha(){
	
	int opcao_digitada, opcao_continuacao;
	
	printf("------Este programa realiza o c�lculo de um dissipador de calor para um diodo de pot�ncia ou realiza consultas de data sheet--------\n");
	printf("\n");
	
	while(1){
	
		printf("Escolha a op��o desejada:\n");
		printf("\n");
		printf("1 - C�lculo do Dissipador.\n");
		printf("2 - Mostrar Data Sheet Dissipador de Calor.\n");
		printf("0 - Sair\n");
		printf("\n");
		scanf("%d", &opcao_digitada);
		
		switch(opcao_digitada){
			
			case 0:
				break;
			case 1:
				printf("Realizar c�lculo");
				break;
			
			case 2:
				printf("Mostrar data sheet");
				break;
			
			default:
				printf("O valor digitado esta incorreto.\n");
				break;
		}
		
		printf("\n");
		printf("Deseja continuar a utilizar a ferramenta ?\n");
		printf("Digite:\n");
		printf("\n");
		printf("1 - Sim\n");
		printf("2 - N�o\n");
		scanf("%d", &opcao_digitada);
		
		if(opcao_digitada == 2){
			break;
		} 
	}
	
	printf("Fim do programa !\n");
}
