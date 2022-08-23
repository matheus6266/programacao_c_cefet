#include<stdio.h>

int dia_semana;

int main(){
    
    // Este programa informa ao usuário se ele tem ou não direito a meia entrada

    printf("Informe o dia da semana\n");
    printf("0 - Domingo\n""1 - Segunda - Feira\n""2 - Terça - Feira\n""3 - Quarta - feira\n");
    printf("4 - Quinta - Feira\n""5 - Sexta - Feira\n""6 - Sábado\n");
    scanf("%d", &dia_semana);

    if ((dia_semana == 0)||(dia_semana == 1)||(dia_semana == 2)||(dia_semana == 3)||(dia_semana == 4)||(dia_semana == 5)||(dia_semana == 6)){
        
        if (dia_semana == 1){

            printf("Você irá pagar meia - entrada\n");
            printf("\n");

        } else{

            int info_estudante;
            printf("Você é estudante?\n");
            printf("1 - Sim\n""2 - Não\n");
            scanf("%d", &info_estudante);

            if (info_estudante == 1){
                printf("Você tem direito a meia entrada.\n");

            } else{

                int idade_usuario;

                printf("Qual a sua idade?\n");
                scanf("%d", &idade_usuario);

                if((idade_usuario > 65) || (idade_usuario < 12)){

                    printf("Você irá pagar meia - entrada\n");
                    printf("\n");

                } else if(dia_semana == 3){

                    int info_casal;

                    printf("Você é um casal?\n");
                    printf("1 - Sim\n""2 - Não\n");
                    scanf("%d", &dia_semana);

                    if(dia_semana == 1){
                        printf("Vocês tem direito a meia - entrada\n");
                        printf("\n");
                    } else{
                        printf("Você não tem direito à meia entrada\n");
                        printf("\n");
                    }

                    } else{
                        printf("Você não tem direito a meia-entrada\n");
                        printf("\n");
                    }
            }
        }
            
    } else{
        
        printf("Favor informar um dia da semana válido\n");
        printf("\n");

        }
    
    return 0;
}