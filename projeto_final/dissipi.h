#ifndef DISSIPI_H_
#define DISSIPI_H_

/*	
	Criar os strutucs com os métodos e atributos dos tipos de ondas e tipos de dissipadores
*/

void cadastro_diodo_onda(); //Esta função realiza o cálculo de potência
float calculo_imed_irms_k(struct onda onda1);
void menu_escolha();  //Função para apresentar o que vai ser feito e da a opção ao usuário somente para consulta os datasheets dos dissipadores ou realizar o projeto do dissipador


#endif
