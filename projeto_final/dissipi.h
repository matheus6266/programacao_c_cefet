#ifndef DISSIPI_H_
#define DISSIPI_H_

/*	
	Criar os strutucs com os m�todos e atributos dos tipos de ondas e tipos de dissipadores
*/

void cadastro_diodo_onda(); //Esta fun��o realiza o c�lculo de pot�ncia
float calculo_imed_irms_k(struct onda onda1);
void menu_escolha();  //Fun��o para apresentar o que vai ser feito e da a op��o ao usu�rio somente para consulta os datasheets dos dissipadores ou realizar o projeto do dissipador


#endif
