/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa

Referências dos algoritmos de casamento de cadeias:

AUTOR: Professor Nivio Ziviani do DCC da UFMG
LINK: http://www2.dcc.ufmg.br/livros/algoritmos/cap8/codigo/c/8.1a8.6e8.8-pesquisacadeia.c
*/

#include "./Headers/auxiliares.h"

//gcc -o exec main.c ./Sources/algoritmos.c ./Sources/auxiliares.c
//mingw32-make exec

int main(int argc, char **argv)
{
    TipoTexto texto;
    TipoPadrao padrao;

    int escolhaMenu, k, permissaoInsercao, permissaoRemocao, permissaoSubstituicao;

    clock_t tempo; // variavel que armazenará o tempo de execução

    leituraArquivo(texto);
    printf("Digite o nome do padrao: ");
    scanf("%s", padrao);

    do
    {
        escolhaMenu = menu();
        switch (escolhaMenu)
        {
        case 1:

            puts("\nExecucao Forca Bruta:");

            tempo = clock();
            ForcaBruta(texto, strlen(texto), padrao, strlen(padrao));

            tempo = clock() - tempo;

            if (MODO_DEBUG)
                printf("Tempo de execucao: %lf\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));

            system("pause");
            break;

        case 2:

            puts("\nExecucao Shift-And Exato:");

            tempo = clock();
            ShiftAndExato(texto, strlen(texto), padrao, strlen(padrao));

            tempo = clock() - tempo;

            if (MODO_DEBUG)
                printf("Tempo de execucao: %lf\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));

            system("pause");
            break;

        case 3:

            puts("\nExecucao Shift-And Aproximado:");
            printf("Digite a Distancia de Edicao (valor de k): ");
            scanf("%d", &k);

            printf("Deseja permitir a operacao de insercao (1 = sim, 0 = nao): ");
            scanf("%d", &permissaoInsercao);

            printf("Deseja permitir a operacao de remocao (1 = sim, 0 = nao): ");
            scanf("%d", &permissaoRemocao);

            printf("Deseja permitir a operacao de substituicao (1 = sim, 0 = nao): ");
            scanf("%d", &permissaoSubstituicao);

            tempo = clock();
            ShiftAndAproximado(texto, strlen(texto), padrao, strlen(padrao), k, permissaoInsercao, permissaoRemocao, permissaoSubstituicao);

            tempo = clock() - tempo;

            if (MODO_DEBUG)
                printf("Tempo de execucao: %lf\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));

            system("pause");
            break;

        case 0:
            puts("\nObrigado por utilizar!");
            system("pause");
            break;

        default:
            puts("\nValor invalido! Poderia inserir outro?!");
            system("pause");
            break;
        }
        system("cls");
    } while (escolhaMenu != 0);
    return 0;
}