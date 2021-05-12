/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/algoritmos.h"

void ShiftAndExato(TipoTexto T, long n, TipoPadrao P, long m)
{
    long Masc[MAXCHAR], i, R = 0;
    for (i = 0; i < MAXCHAR; i++)
        Masc[i] = 0;
    for (i = 1; i <= m; i++)
        Masc[P[i - 1] + 127] |= 1 << (m - i);
    for (i = 0; i < n; i++)
    {
        R = ((((unsigned long)R) >> 1) |
             (1 << (m - 1))) &
            Masc[T[i] + 127];
        if ((R & 1) != 0)
            printf(" Casamento na posicao %3ld\n", i - m + 2);
    }
}

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m)
{
    long i, j, k;
    for (i = 1; i <= (n - m + 1); i++)
    {
        k = i;
        j = 1;
        while (T[k - 1] == P[j - 1] && j <= m)
        {
            j++;
            k++;
        }
        if (j > m)
            printf("Casamento na posicao: %3ld\n", i);
    }
}