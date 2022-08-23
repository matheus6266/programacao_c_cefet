#include<stdio.h>

int numero_digitado;

void printbincharpad(int numero_digitado) {
    
    // A função printbincharpad recebe um número de 8 bits
    // e printa na tela o seu valor convertido em binário. 

    printf("O número %d convertido em binário é: ", numero_digitado);

    // Cara iteração do for, o parâmetro 1 << i desloca o 1 i bits e realiza
    // uma operação binário AND com o numero_digitado. Caso seja verdadeira
    // ele printa o caracter '1' e caso seja falso ele printa o caracter '0'.
    // Ou seja cara iteração do for printa uma posição do unsigned char de 8 bits.

    for (int i = 7; i >= 0; i--)
    {   
        putchar((numero_digitado & (1 << i)) ? '1' : '0');
    }
    
    putchar('\n');
}


int main(){
    
    // Este programa lê um número fornecido pelo usuário e imprime
    // o valor convertido para a base 2

    printf("Digite um número entre 0 a 255: \n");
    scanf("%d", &numero_digitado);
    
    if ((numero_digitado >= 0) && (numero_digitado <= 255)) {

        printbincharpad(numero_digitado);

    } else {

        printf("Favor informar um número válido entre 0 a 255. \n");
        printf("\n");
    }
    

    return 0;
}