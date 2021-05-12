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
    leituraArquivo(texto);

    printf("%s ",texto);


    return 0;
}