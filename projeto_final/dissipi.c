#include "dissipi.h"
#include <stdio.h>
#include<math.h>
# define pi 3.141592653589793238462643383279502884

// Defini��o das vari�veis globais

	struct diodo {
		
		char modelo[50];
		float resistencia;
		float tensao_direta;
		
	};
	
	struct onda {
		
		int forma_onda;
		float frequencia;
		float ton;
		float corrente_pico;
		float corrente_ia;
		float corrente_ib;
	};
	
	float correntes_calculadas[2];
	struct diodo diodo_projeto;
	struct onda onda_projeto;




void cadastro_diodo_onda(){

	
	printf("Voc� escolheu a op��o Projeto Dissipador de Calor.\n");
	printf("\n");
	printf("---------In�cio cadastro do diodo-----------\n");
	printf("Informe o modelo do diodo:\n");
	scanf("%s", diodo_projeto.modelo);
	printf("Informe o valor da resist�ncia interna do diodo:\n");
	scanf("%f", &diodo_projeto.resistencia);
	printf("Informe o valor da tens�o direta do diodo:\n");
	scanf("%f", &diodo_projeto.tensao_direta);
	printf("----------Fim cadastro do diodo---------------\n");
	printf("\n");
	printf("---------In�cio cadastro do tipo de onda------------\n");
	printf("\n");
	printf("Digite o n�mero correspondente ao formato da onda de alimenta��o do circuito:\n");
	printf("\n");
	printf("1 - Onda Completa Sinusoidal\n");
	printf("2 - Pulso Sinusoidal\n");
	printf("3 - Onda Quadrada\n");
	printf("4 - Onda Triangular\n");
	printf("5 - Onda Trapezoidal\n");
	scanf("%d", &onda_projeto.forma_onda);
	printf("\n");
	printf("Informe o valor da frequ�ncia da onda:\n");
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
	
}

float calculo_imed_irms_k(struct onda onda1){
	
	float imed, irms, razao_ciclica, periodo, correntes_calculadas[2];
	
	printf("In�cio dos c�lculos de corrente m�dia e corrente rms.\n");
	printf("\n");
	
	switch(onda1.forma_onda){
		
		case 1:
			
			correntes_calculadas[0] = (2*onda1.corrente_pico)/pi;        				//C�lculo da corrente m�dia
			correntes_calculadas[1] = (onda1.corrente_pico)/sqrt(2);      				//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f\n", correntes_calculadas[0]);
			printf("O valor da corrente Irms �: %.2f\n", correntes_calculadas[1]);
			break;
		
		case 2:
			
			periodo = (1/onda1.frequencia);
			razao_ciclica = (onda1.ton/periodo);
			correntes_calculadas[0] = (onda1.corrente_pico)/pi;        						//C�lculo da corrente m�dia
			correntes_calculadas[1] = (onda1.corrente_pico)*sqrt(razao_ciclica/2);      		//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f\n", correntes_calculadas[0]);
			printf("O valor da corrente Irms �: %.2f\n", correntes_calculadas[1]);
			break;
			
		case 3:
			
			periodo = (1/onda1.frequencia);
			razao_ciclica = (onda1.ton/periodo);
			correntes_calculadas[0] = (razao_ciclica*onda1.corrente_pico);        					//C�lculo da corrente m�dia
			correntes_calculadas[1] = ((onda1.corrente_pico*sqrt(razao_ciclica)));     				 //C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f\n", correntes_calculadas[0]);
			printf("O valor da corrente Irms �: %.2f\n", correntes_calculadas[1]);
			break;
			
		case 4:
			
			periodo = (1/onda1.frequencia);
			razao_ciclica = (onda1.ton/periodo);
			correntes_calculadas[0] = (razao_ciclica/2)*onda1.corrente_pico;     					//C�lculo da corrente m�dia
			correntes_calculadas[1] = ((onda1.corrente_pico*sqrt(razao_ciclica/3)));      				//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f\n", correntes_calculadas[0]);
			printf("O valor da corrente Irms �: %.2f\n", correntes_calculadas[1]);
			break;
			
		case 5:
			
			periodo = (1/onda1.frequencia);
			razao_ciclica = (onda1.ton/periodo);
			correntes_calculadas[0] = (razao_ciclica*(onda1.corrente_ia + onda1.corrente_ib))/2;     																			//C�lculo da corrente m�dia
			correntes_calculadas[1] = sqrt((razao_ciclica * (pow(onda1.corrente_ib,2) + (onda1.corrente_ia*onda1.corrente_ib) + pow(onda1.corrente_ia,2)))/3);				//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f\n", correntes_calculadas[0]);
			printf("O valor da corrente Irms �: %.2f\n", correntes_calculadas[1]);
			break;
	}
	
	printf("---------Fim c�lculo corrente Irms e Imed-------------");
	
	return correntes_calculadas[2];
}




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
				calculo_potencia_diodo();
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



















