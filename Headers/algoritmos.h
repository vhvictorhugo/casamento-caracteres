/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXTAMTEXTO 9999
#define MAXTAMPADRAO 30
#define MAXCHAR 256
typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

void ShiftAndExato(TipoTexto T, long n, TipoPadrao P, long m);
void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m);