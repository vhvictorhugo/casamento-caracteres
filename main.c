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

    time_t begin; //variavel que armazenara o tempo de execucao

    leituraArquivo(texto);

    printf("Digite o nome do padrao: ");
    scanf("%s", padrao);

    begin = clock();
    puts("Execucao Shift-And:");
    ShiftAndExato(texto, strlen(texto), padrao, strlen(padrao));
    begin = clock() - begin;
    printf("%lf e o tempo de execucao.\n", ((double)begin) / ((CLOCKS_PER_SEC / 1000)));

    puts("");

    begin = clock();
    puts("Execucao Forca Bruta:");
    ForcaBruta(texto, strlen(texto), padrao, strlen(padrao));
    begin = clock() - begin;
    printf("%lf e o tempo de execucao.\n", ((double)begin) / ((CLOCKS_PER_SEC / 1000)));

    return 0;
}