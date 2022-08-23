#include<stdio.h>
#include<math.h>

// Para realizar a compilação da biblioteca math.h usar o seguinte comando:
// gcc nome_progama.c -o nome_programa -lm

double num_a, num_b;
char operacao_desejada;

int main(){

    // Este programa realiza a operação entre dois números fornecida
    // pelo usuário
    
    printf("Escolha a operação desejada: \n");
    printf("\n");
    printf("Operadores: \n");
    printf("Soma (+)\n""Subtração (-)\n""Multiplicação (*)\n""Divisão (/)\n");
    printf("Potência (^)\n""Raíz Quadrada (r)\n");
    scanf("%c",&operacao_desejada);
    printf("\n");


    switch (operacao_desejada){

    case '+':

        printf("Informe o primeiro número: \n");
        scanf("%lf", &num_a);
        printf("Informe o segundo número: \n");
        scanf("%lf", &num_b);

        printf("O resultado da soma será: ");
        printf("%.2lf", (num_a + num_b));
        printf("\n");
        break;
    
    case '-':

        printf("Informe o primeiro número: \n");
        scanf("%lf", &num_a);
        printf("Informe o segundo número: \n");
        scanf("%lf", &num_b);

        printf("O resultado da subtração será: ");
        printf("%.2lf", (num_a - num_b));
        printf("\n");
        break;
    
    case '*':

        printf("Informe o primeiro número: \n");
        scanf("%lf", &num_a);
        printf("Informe o segundo número: \n");
        scanf("%lf", &num_b);

        printf("O resultado da multiplicação será: ");
        printf("%.2lf", (num_a * num_b));
        printf("\n");
        break;
    
    case '/':

        printf("Informe o numerador: \n");
        scanf("%lf", &num_a);
        printf("Informe o denominador: \n");
        scanf("%lf", &num_b);
        printf("\n");

        printf("O resultado da divisão será: ");
        printf("%.2lf", (num_a / num_b));
        printf("\n");
        break;
    
    case '^':

        printf("Informe a potência desejada: \n");
        scanf("%lf", &num_a);
        printf("Informe a base: \n");
        scanf("%lf", &num_b);
        printf("\n");

        printf("O resultado da potenciação é: ");
        printf("%.2lf", pow(num_a, num_b));
        printf("\n");
        break;
    
    case 'r':

        printf("Informe o número a sera extraído a raiz quadrada: \n");
        scanf("%lf", &num_a);

        printf("O resultado da radiação será: ");
        printf("%.2lf", sqrt(num_a));
        printf("\n");
        break;

    
    default:

        printf("Informe uma operação válida !\n");
        printf("\n");
        break;
    }


    return 0;

}