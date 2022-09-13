#include<stdio.h>

char nomes_alunos[5][20];
float notas_alunos[15];
float media_individual[5];

// Função de cadastro dos alunos

void cadastro_nome_notas_alunos(){

    int indice_alunos = 1;

    for (int i = 0; i <= 4; i++)
    {
        printf("Escreva o nome do %d° aluno. \n", i+1);
        scanf("%s", &nomes_alunos[i]);


        for (int x = 0; x <= 2; x++)
        {

        printf("Informe a %d° nota do aluno %s. \n",x+1, nomes_alunos[i]);
        scanf("%f", &notas_alunos[indice_alunos]);
        indice_alunos = indice_alunos + 1;

        }

    }
}

// Função para o cálculo da média

void calculo_media(){

    float soma_notas_acumuladas, media_tuma, acumulado_notas_aluno;
    int indice_auxiliar_aluno = 1;
    int indice_auxiliar_menor, indice_auxiliar_maior;
    float menor_nota_media = 999; // Variável para realizar a comparação das notas
    float maior_nota_media = 0; // Variável para realizar a comparação das notas
   
    

    // Cálculo média geral da turma

    printf("-------------------------------------------\n");

    for (int i = 0; i <= 14; i++)
    {
        soma_notas_acumuladas = soma_notas_acumuladas + notas_alunos[i];
    }

    printf("A média geral das notas da turma foi: %.2f.\n", (soma_notas_acumuladas / 15));
    printf("-------------------------------------------\n");

    // Cálculo média individual

    for (int i = 0; i <= 4; i++)
    {
        acumulado_notas_aluno = 0;

        for (int x = 0; x <= 2; x++)
        {
            acumulado_notas_aluno = acumulado_notas_aluno + notas_alunos[indice_auxiliar_aluno];
            indice_auxiliar_aluno = indice_auxiliar_aluno + 1;
        }
        
        media_individual[i] = (acumulado_notas_aluno / 3);
        printf("A médida das notas do aluno %s foi: %.2f.\n", nomes_alunos[i], media_individual[i]);
        

    }

    printf("-------------------------------------------\n");

    // Verificação das maiores e menores médias

    indice_auxiliar_aluno = 1;

    for (int z = 0; z <= 4; z++)
    {
        if (media_individual[z] > maior_nota_media)
        {
            maior_nota_media = media_individual[z];
            indice_auxiliar_maior = z;

        } 
        if (media_individual[z] < menor_nota_media)
        {
            menor_nota_media = media_individual[z];
            indice_auxiliar_menor = z;
        }        
        
    }

    printf("A maior média foi do aluno %s com o valor de %.2f.\n", nomes_alunos[indice_auxiliar_maior], maior_nota_media);
    printf("A menor média foi do aluno %s com o valor de %.2f.\n", nomes_alunos[indice_auxiliar_menor], menor_nota_media);
    
}

// Função para a realização da recuperação

void calculo_recuperacao(){

    int indice_alunos_aprovados[5];
    int indice_alunos_reprovados[5];
    int exame_recuperacao, criterio_avaliacao;
    float nota_recuperacao, nota_recuperacao_consolidada;
    int aux_aprovados = 0;
    int aux_reprovados = 0;

    printf("-------------------------------------------\n");

// Verificação dos alunos aprovados e em recuperação

    for (int w = 0; w <= 4; w++)
    {
        if (media_individual[w] >= 60 )
        {   
            
            indice_alunos_aprovados[aux_aprovados] = w;
            printf("O aluno %s obteve uma média de %.2f e esta APROVADO!.\n", nomes_alunos[w], media_individual[w]);
            aux_aprovados++;
        }
        else if (media_individual[w] < 60)
        {
            
            indice_alunos_reprovados[aux_reprovados] = w;
            printf("O aluno %s obteve uma média de %.2f e esta em RECUPERAÇÂO!.\n", nomes_alunos[w], media_individual[w]);
            aux_reprovados++;
        }
        
    }
    
    printf("-------------------------------------------\n");
    printf("%d\n", aux_reprovados);

    if (aux_reprovados != 0)
    {
        for (int i = 0; i < aux_reprovados; i++)
        {
        
        printf("Deseja aplicar a recuperação para o aluno %s?\n", nomes_alunos[indice_alunos_reprovados[i]]);
        printf("Digite: 0 = Não.\n");
        printf("Digite: 1 = Sim.\n");
        scanf("%d", &exame_recuperacao);
        printf("\n");

        switch (exame_recuperacao)
        {
            case 0:
                printf("O aluno %s não fará recuperação !\n", nomes_alunos[indice_alunos_reprovados[i]]);
                printf("\n");
                break;
            case 1:
                printf("Informe o critério de avaliação:\n");
                printf("1: Nota Recueperação > 60.\n");
                printf("2: (Nota + Nota Recuperação)/2.\n");
                scanf("%d", &criterio_avaliacao);
                printf("\n");

                switch (criterio_avaliacao)
                {
                case 1:
                    printf("Informe a nota de recuperação do aluno %s.\n", nomes_alunos[indice_alunos_reprovados[i]]);
                    scanf("%f", &nota_recuperacao);
                    printf("\n");

                    if (nota_recuperacao > 60)
                    {
                        printf("O aluno %s foi aprovado na recuperação.\n", nomes_alunos[indice_alunos_reprovados[i]]);
                        printf("\n");

                    } else if (nota_recuperacao <= 60)
                    {
                        printf("O aluno %s não foi aprovado na recuperação.\n", nomes_alunos[indice_alunos_reprovados[i]]);
                        printf("\n");

                    }
                    
                    break;
                case 2:

                    printf("Informe a nota de recuperação do aluno %s.\n", nomes_alunos[indice_alunos_reprovados[i]]);
                    scanf("%f", &nota_recuperacao);
                    printf("\n");

                    nota_recuperacao_consolidada = (nota_recuperacao + media_individual[i])/2;

                    if (nota_recuperacao_consolidada > 60)
                    {
                        printf("O aluno %s foi aprovado na recuperação.\n", nomes_alunos[indice_alunos_reprovados[i]]);
                        printf("\n");

                    } else 
                    {
                        printf("O aluno %s não foi aprovado na recuperação.\n", nomes_alunos[indice_alunos_reprovados[i]]);
                        printf("\n");

                    }
                    break;
                

                default:
                    printf("Valor inválido.\n");
                    printf("\n");
                    break;
                
                }
            break;

            default:
                printf("Valor inválido.\n");
                printf("\n");
                break;
                
        }
        }

        printf("Fim do programa. \n");
        printf("\n");

    } else {
        printf("Nenhum aluno esta em recuperação este semestre !\n");
        printf("Fim do programa.\n");
        printf("\n");
    }       

}

    
int main(){

    cadastro_nome_notas_alunos();
    calculo_media();
    calculo_recuperacao();

    return 0;
}