#include<stdio.h>
#include<locale.h>



int main(){
	
	setlocale(LC_ALL,""); // Utilização dos caracteres na codificação UTF - 8
	
	int i;
	char matriz_nomes[5][10] = 
	{
		"PEDRO",
		"MARIA",
		"JESUS",
		"IFC",
		"LUZERNA"
	};

	
	for(i = 0; i <= 4; i++){
		printf("%s", matriz_nomes[i]);
		printf("\n");
	}
	
	return 0;
	
	
}
