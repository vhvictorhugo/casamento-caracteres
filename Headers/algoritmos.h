/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

/*
#ifdef __unix__
#include <unistd.h>

#elif defined(_WIN32) || defined(WIN32)

#define OS_Windows

#include <windows.h>

#endif
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
void ShiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, long k);
void ShiftAndAproximadoAlterado(TipoTexto T, long n, TipoPadrao P, long m, long k, int permissao);