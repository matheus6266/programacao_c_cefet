#include "dissipi.h"
#include <stdio.h>
#include<math.h>
# define pi 3.141592653589793238462643383279502884

void projeto_termico(float i_med, float i_rms){
	
	float potencia_juncao, temperatura_juncao;
	
	potencia_juncao = (diodo_projeto.tensao_direta*i_med) + (diodo_projeto.resistencia * pow(i_rms, 2));
	printf("%f", potencia_juncao);
	
	
}


void calculo_imed_irms_k(struct onda onda_projeto){
	
	float imed, irms, razao_ciclica, periodo;
	
	printf("Início dos cálculos de corrente média e corrente rms.\n");
	printf("\n");
	
	switch(onda_projeto.forma_onda){
		
		case 1:
			
			imed = (2*onda_projeto.corrente_pico)/pi;        				//Cálculo da corrente média
			irms = (onda_projeto.corrente_pico)/sqrt(2);      				//Cálculo da corrente Irms
			printf("O valor da corrente média é: %.2f\n", imed);
			printf("O valor da corrente Irms é: %.2f\n", irms);
			break;
		
		case 2:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			imed = (onda_projeto.corrente_pico)/pi;        						//Cálculo da corrente média
			irms = (onda_projeto.corrente_pico)*sqrt(razao_ciclica/2);      		//Cálculo da corrente Irms
			printf("O valor da corrente média é: %.2f\n", imed);
			printf("O valor da corrente Irms é: %.2f\n", irms);
			break;
			
		case 3:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			imed = (razao_ciclica*onda_projeto.corrente_pico);        					//Cálculo da corrente média
			irms = ((onda_projeto.corrente_pico*sqrt(razao_ciclica)));     				 //Cálculo da corrente Irms
			printf("O valor da corrente média é: %.2f\n", imed);
			printf("O valor da corrente Irms é: %.2f\n", irms);
			break;
			
		case 4:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			imed = (razao_ciclica/2)*onda_projeto.corrente_pico;     					//Cálculo da corrente média
			irms = ((onda_projeto.corrente_pico*sqrt(razao_ciclica/3)));      				//Cálculo da corrente Irms
			printf("O valor da corrente média é: %.2f\n", imed);
			printf("O valor da corrente Irms é: %.2f\n", irms);
			break;
			
		case 5:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			imed = (razao_ciclica*(onda_projeto.corrente_ia + onda_projeto.corrente_ib))/2;     																			//Cálculo da corrente média
			irms = sqrt((razao_ciclica * (pow(onda_projeto.corrente_ib,2) + (onda_projeto.corrente_ia*onda_projeto.corrente_ib) + pow(onda_projeto.corrente_ia,2)))/3);				//Cálculo da corrente Irms
			printf("O valor da corrente média é: %.2f\n", imed);
			printf("O valor da corrente Irms é: %.2f\n", irms);
			break;
	}
	
	printf("---------Fim cálculo corrente Irms e Imed-------------");
	printf("\n");
	
	projeto_termico(imed, irms);
	
}

void cadastro_diodo_onda(){
	
	
	printf("Você escolheu a opção Projeto Dissipador de Calor.\n");
	printf("\n");
	printf("---------Início cadastro do diodo-----------\n");
	printf("Informe o modelo do diodo:\n");
	scanf("%s", diodo_projeto.modelo);
	printf("Informe o valor da resistência interna do diodo:\n");
	scanf("%f", &diodo_projeto.resistencia);
	printf("Informe o valor da tensão direta do diodo:\n");
	scanf("%f", &diodo_projeto.tensao_direta);
	printf("Informe o valor da resistência Rjc do diodo:\n");
	scanf("%f", &diodo_projeto.resistencia_rjc);
	printf("Informe o valor da resistência Rca do diodo: \n");
	scanf("%f", &diodo_projeto.resistencia_rca);
	printf("----------Fim cadastro do diodo---------------\n");
	printf("\n");
	printf("---------Início cadastro do tipo de onda------------\n");
	printf("\n");
	printf("Digite o número correspondente ao formato da onda de alimentação do circuito:\n");
	printf("\n");
	printf("1 - Onda Completa Sinusoidal\n");
	printf("2 - Pulso Sinusoidal\n");
	printf("3 - Onda Quadrada\n");
	printf("4 - Onda Triangular\n");
	printf("5 - Onda Trapezoidal\n");
	scanf("%d", &onda_projeto.forma_onda);
	printf("\n");
	printf("Informe o valor da frequência da onda:\n");
	scanf("%f", &onda_projeto.frequencia);
	printf("Informe o valor do Ton:\n");
	scanf("%f", &onda_projeto.ton);

	if(onda_projeto.forma_onda == 5){
		
		printf("Informe o valor da corrente Ib:\n");
		scanf("%f", &onda_projeto.corrente_ib);
		printf("Informe o valor da corrente Ia:\n");
		scanf("%f", &onda_projeto.corrente_ia);
	} else {
		
		printf("Informe o valor da corrente de pico Ip:\n");
		scanf("%f", &onda_projeto.corrente_pico);
	}
	printf("----------Fim cadastro da forma de onda---------------\n");
	printf("\n");
	
	calculo_imed_irms_k(onda_projeto);
	
}
	

void menu_escolha(){
	
	int opcao_digitada, opcao_continuacao;
	
	printf("------Este programa realiza o cálculo de um dissipador de calor para um diodo de potência ou realiza consultas de data sheet--------\n");
	printf("\n");
	
	while(1){
	
		printf("Escolha a opção desejada:\n");
		printf("\n");
		printf("1 - Cálculo do Dissipador.\n");
		printf("2 - Mostrar Data Sheet Dissipador de Calor.\n");
		printf("0 - Sair\n");
		printf("\n");
		scanf("%d", &opcao_digitada);
		
		switch(opcao_digitada){
			
			case 0:
				break;
			case 1:
				cadastro_diodo_onda();
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
		printf("2 - Não\n");
		scanf("%d", &opcao_digitada);
		
		if(opcao_digitada == 2){
			break;
		} 
	}
	
	printf("Fim do programa !\n");
}



















