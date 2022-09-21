#include "dissipi.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
# define pi 3.141592653589793238462643383279502884

void projeto_termico(float i_med, float i_rms){
	
	strcpy(to_220.modelo, "WV-T220-101E");
	to_220.package_type = 1;
	to_220.resistencia_termica = 13;
	
	strcpy(to_247.modelo, "WV-T247-101E");
	to_247.package_type = 2;
	to_247.resistencia_termica = 12;	
	
	float potencia_juncao, temperatura_juncao, temperatura_ambiente, temperatura_juncao_final;
	float resistencia_juncao_ideal, resistencia_dissipador_ideal, resistencia_rcd, resistencia_juncao_final;
	int opcao_continuacao, opcao_pasta;
	
	//Condi��o para determinar o valor de Rcd
	
	potencia_juncao = (diodo_projeto.tensao_direta*i_med) + (diodo_projeto.resistencia * pow(i_rms, 2));
	
	printf("Informe a temperatura ambiente do local de instala��o do diodo em �C: \n");
	scanf("%f", &temperatura_ambiente);
	
	temperatura_juncao = potencia_juncao * (diodo_projeto.resistencia_rjc + diodo_projeto.resistencia_rca) + temperatura_ambiente;
	
	
	if((temperatura_juncao >= diodo_projeto.temperatura_juncao) || (temperatura_juncao >= diodo_projeto.temperatura_juncao*0.8)){
		
		printf("A temperatura de jun��o calculda foi %.2f �C e esta acima da temperatura m�xima de jun��o do diodo que � %.2f �C.\n",temperatura_juncao, diodo_projeto.temperatura_juncao);
		printf("A instala��o do dissipador de calor � OBRIGAT�RIA !!\n");
		printf("\n");
		
	} else if(temperatura_juncao <= diodo_projeto.temperatura_juncao*0.8){ // Considerando 80% da temperatura m�xima da jun��o do diodo	

		printf("A temperatura de jun��o calculda foi %.2f �C e esta abaixo de 80% da temperatura m�xima de jun��o do diodo que � %.2f �C.",temperatura_juncao, diodo_projeto.temperatura_juncao);
		printf("A instala��o do dissipador de calor � RECOMENDADA !!\n");
		printf("\n");

	}
	
	printf("Informe a op��o desejada: \n");
	printf("\n");
	printf("1 - Continuar com o projeto.\n");
	printf("2 - Encerrar c�lculo.\n");
	scanf("%d", &opcao_continuacao);
	
	switch(opcao_continuacao){
		
		case 1:
			
			printf("Deseja aplicar pasta t�rmica entre o dissipador de calor e o diodo?\n");
			printf("1 - Sim / 2 - N�o\n");
			scanf("%d", &opcao_pasta);
			
			switch(opcao_pasta){
				
				case 1:
					
					if((diodo_projeto.package_type == 1)){
						
						resistencia_rcd = 0.5;
						
					} else if (diodo_projeto.package_type == 2) {
						
						resistencia_rcd = 2.5;
						
					}
					break;
				
				case 2:
					if((diodo_projeto.package_type == 1)){
						
						resistencia_rcd = 2;
						
					} else if (diodo_projeto.package_type == 2) {
						
						resistencia_rcd = 6;
						
					}
					break;
				
				default:
					
					printf("Valor digitado incorretamente. N�o ser� considerada a utiliza��o de pasta t�rmico e o valor de Rcd ser� 4 ohms/n");
					resistencia_rcd = 4;
					break;
			}
			
			
			resistencia_juncao_ideal = ((diodo_projeto.temperatura_juncao*0.8) - temperatura_ambiente)/potencia_juncao;
			resistencia_dissipador_ideal = resistencia_juncao_ideal - diodo_projeto.resistencia_rjc - resistencia_rcd;
			
			switch(diodo_projeto.package_type){
				
				case 1:
					
					if(resistencia_dissipador_ideal >= to_220.resistencia_termica){
						
						printf("O modelo de dissipador que temos cadastrado no sistema atende a aplica��o.\n");
						printf("O modelo escolhido ser�: %s\n", to_220.modelo);
						resistencia_juncao_final = diodo_projeto.resistencia_rjc + resistencia_rcd + to_220.resistencia_termica;
						temperatura_juncao_final = (potencia_juncao * resistencia_juncao_final) + temperatura_ambiente;
						printf("Ap�s a instala��o do dissipador de calor a temperatura da jun��o ser�: ");
						printf("%.2f �C.\n", temperatura_juncao_final);
												
					} else {
						
						printf("Os modelos de dissipador que temos cadastrados no sistema n�o atendem a aplica��o. Favor redimensionar o seu projeto.\n");
						
					}
					
					break;
					
				case 2:
					
					if(resistencia_dissipador_ideal >= to_247.resistencia_termica){
						
						printf("O modelo de dissipador que temos cadastrado no sistema atende a aplica��o.\n");
						printf("O modelo escolhido ser�: %s\n", to_247.modelo);
						
						resistencia_juncao_final = diodo_projeto.resistencia_rjc + resistencia_rcd + to_247.resistencia_termica;
						temperatura_juncao_final = (potencia_juncao * resistencia_juncao_final) + temperatura_ambiente;
						printf("Ap�s a instala��o do dissipador de calor a temperatura da jun��o ser�: ");
						printf("%.2f �C.\n", temperatura_juncao_final);
						
					} else {
						
						printf("Os modelos de dissipador que temos cadastrados no sistema n�o atendem a aplica��o. Favor redimensionar o seu projeto.\n");
						
					}
			
					break;
					
			}
			
			break;
			
		case 2:
				
			printf("Voc� optou pela n�o utiliza��o do dissipador de calor.\n");
			printf("A temperatura final de jun��o ser� %.2f �C\n", temperatura_juncao);
			break;
			
	}	


}

void calculo_imed_irms_k(struct onda onda_projeto){
	
	float imed, irms, razao_ciclica, periodo;
	
	printf("--------In�cio dos c�lculos de corrente m�dia e corrente rms.----------\n");
	printf("\n");
	
	switch(onda_projeto.forma_onda){
		
		case 1:
			
			imed = (2*onda_projeto.corrente_pico)/pi;        				//C�lculo da corrente m�dia
			irms = (onda_projeto.corrente_pico)/sqrt(2);      				//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f A\n", imed);
			printf("O valor da corrente Irms �: %.2f A\n", irms);
			printf("\n");
			break;
		
		case 2:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			imed = (onda_projeto.corrente_pico)/pi;        						//C�lculo da corrente m�dia
			irms = (onda_projeto.corrente_pico)*sqrt(razao_ciclica/2);      		//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f A\n", imed);
			printf("O valor da corrente Irms �: %.2f A\n", irms);
			printf("\n");
			break;
			
		case 3:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			imed = (razao_ciclica*onda_projeto.corrente_pico);        					//C�lculo da corrente m�dia
			irms = ((onda_projeto.corrente_pico*sqrt(razao_ciclica)));     				 //C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f A\n", imed);
			printf("O valor da corrente Irms �: %.2f A\n", irms);
			printf("\n");
			break;
			
		case 4:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			printf("%f", razao_ciclica);
			imed = (razao_ciclica/2)*onda_projeto.corrente_pico;     					//C�lculo da corrente m�dia
			irms = ((onda_projeto.corrente_pico*sqrt(razao_ciclica/3)));      				//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.8f A\n", imed);
			printf("O valor da corrente Irms �: %.8f A\n", irms);
			printf("\n");
			break;
			
		case 5:
			
			periodo = (1/onda_projeto.frequencia);
			razao_ciclica = (onda_projeto.ton/periodo);
			imed = (razao_ciclica*(onda_projeto.corrente_ia + onda_projeto.corrente_ib))/2;     																			//C�lculo da corrente m�dia
			irms = sqrt((razao_ciclica * (pow(onda_projeto.corrente_ib,2) + (onda_projeto.corrente_ia*onda_projeto.corrente_ib) + pow(onda_projeto.corrente_ia,2)))/3);				//C�lculo da corrente Irms
			printf("O valor da corrente m�dia �: %.2f A\n", imed);
			printf("O valor da corrente Irms �: %.2f A\n", irms);
			printf("\n");
			break;
	}
	
	printf("---------Fim c�lculo corrente Irms e Imed-------------\n");
	printf("\n");
	
	projeto_termico(imed, irms);
	
}

void cadastro_diodo_onda(){
	
	
	printf("Voc� escolheu a op��o Projeto Dissipador de Calor.\n");
	printf("\n");
	printf("---------In�cio cadastro do diodo-----------\n");
	printf("Informe o modelo do diodo:\n");
	scanf("%s", diodo_projeto.modelo);
	printf("Informe o tipo de encapsulamento do diodo: 1 - TO - 220 / 2 - TO - 247\n");
	scanf("%d", &diodo_projeto.package_type);
	printf("Informe a temperatura m�xima de jun��o do diodo em (�C):\n");
	scanf("%f", &diodo_projeto.temperatura_juncao);
	printf("Informe o valor da resist�ncia interna do diodo em (ohms):\n");
	scanf("%f", &diodo_projeto.resistencia);
	printf("Informe o valor da tens�o direta do diodo em (V):\n");
	scanf("%f", &diodo_projeto.tensao_direta);
	printf("Informe o valor da resist�ncia Rjc do diodo em (ohms):\n");
	scanf("%f", &diodo_projeto.resistencia_rjc);
	printf("Informe o valor da resist�ncia Rca do diodo em (ohms): \n");
	scanf("%f", &diodo_projeto.resistencia_rca);
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
	printf("Informe o valor da frequ�ncia da onda em (Hz):\n");
	scanf("%f", &onda_projeto.frequencia);
	printf("Informe o valor do Ton em (segundos):\n");
	scanf("%f", &onda_projeto.ton);

	if(onda_projeto.forma_onda == 5){
		
		printf("Informe o valor da corrente Ib em (A):\n");
		scanf("%f", &onda_projeto.corrente_ib);
		printf("Informe o valor da corrente Ia em (A):\n");
		scanf("%f", &onda_projeto.corrente_ia);
	} else {
		
		printf("Informe o valor da corrente de pico Ip em (A):\n");
		scanf("%f", &onda_projeto.corrente_pico);
	}
	printf("----------Fim cadastro da forma de onda---------------\n");
	printf("\n");
	
	calculo_imed_irms_k(onda_projeto);
	
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
		printf("2 - N�o\n");
		scanf("%d", &opcao_digitada);
		
		if(opcao_digitada == 2){
			break;
		} 
	}
	
	printf("Fim do programa !\n");
}



















