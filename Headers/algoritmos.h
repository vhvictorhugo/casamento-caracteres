/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa

Referências dos algoritmos de casamento de cadeias:

AUTOR: Professor Nivio Ziviani do DCC da UFMG
LINK: http://www2.dcc.ufmg.br/livros/algoritmos/cap8/codigo/c/8.1a8.6e8.8-pesquisacadeia.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXTAMTEXTO 999999
#define MAXTAMPADRAO 30
#define MAXCHAR 256
#define NUMMAXERROS 10
#define MODO_DEBUG 1 // 0 = desativado, 1 = ativado

typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

void ShiftAndExato(TipoTexto T, long n, TipoPadrao P, long m);
void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m);
void ShiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, long k, int permissaoInsercao, int permissaoRemocao, int permissaoSubstituicao);