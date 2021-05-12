/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/auxiliares.h"

//gcc -o exec main.c ./Sources/algoritmos.c ./Sources/auxiliares.c
//mingw32-make exec

int main(int argc, char **argv)
{
    TipoTexto texto;
    TipoPadrao padrao;

    int escolhaMenu;

    leituraArquivo(texto);
    printf("Digite o nome do padrao: ");
    scanf("%s", padrao);

    do
    {

        escolhaMenu = menu();
        switch (escolhaMenu)
        {

        case 1:

            puts("Execucao Forca Bruta:");
            ForcaBruta(texto, strlen(texto), padrao, strlen(padrao));
            system("pause");
            break;

        case 2:
            puts("Execucao Shift-And Exato:");
            ShiftAndExato(texto, strlen(texto), padrao, strlen(padrao));
            system("pause");
            break;

        case 3:
            puts("ainda n foi feito");
            system("pause");
            break;

        case 0:
            puts("Obrigado por utilizar!");
            system("pause");
            break;

        default:
            puts("Valor invalido! Poderia inserir outro?!");
            system("pause");
            break;
        }

    } while (escolhaMenu != 0);

    return 0;
}