#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX 512
#define WORD_MAX 32

// a estrutura deverá ter tres campos:
// um inteiro 'ocurrences' com o nr de ocorrencias
// um inteiro 'length' com o tamanho da palavra
// uma string 'str' com tamanho maximo WORD_MAX
typedef struct {

} word;


FILE * abreFicheiro (char *, char *);

/* recebe um ponteiro para uma estrutura word 
 e preenche os campos dessa estrutura com a string recebida.
 inicializa o contador de repetições a zero
 guarda o tamanho da string no campo correspondente
*/
void write_word(word * w, char * str);

/*
  recebe um vector de estruturas word com 'size' elementos.
  procura nesse vector por uma palavra que seja igual à string
recebida. A procura é case-insensitive.
a funcao deverá retornar o índice do vector em que a palavra foi encontrada
ou '-1' caso não encontre a palavra.
*/
int search_word(word * lista, char * str, int size);

/* imprime uma word no stdout */
void print_word(word *w);

int main (int argc, char **argv)
{
	FILE * fp;	
	int n_max_caracteres = 0;
	word lista[MAX];
	int n_words = 0, n = 0;
	char palavra[WORD_MAX];

	if (argc < 2)
	{
		printf("*** ERRO: indique o nome do ficheiro\n");
		exit(1);
	}
	
	while (!feof(fp))
	{
		// ler palavra do ficheiro
		if (fscanf(fp, "%s", palavra) != 1)
			continue;

	}

	fclose(fp);

	printf("Número de palavras: %d\n", n_words);
	printf("Maior palavra: %d\n", n_max_caracteres);

	// se o utilizador correr o programa com o argumento 'i'
	// imprimir todas as palavras chamando a funcao print_word()
	printf("Ocur\tLen\tWord\n");
	// ciclo...
	print_word();

	return 0;
}

void print_word(word *w)
{
	printf("%d\t%d\t%s\n", w->ocurrences, w->length, w->str);
}

FILE * abreFicheiro(char * nome, char * mode)
{
	FILE * f;
	printf("A abrir o ficheiro\n");
	f = fopen(nome, mode);
	if (f == NULL)
	{
		fprintf(stdout, "*** Não foi possivel abrir o ficheiro %s.", nome);
		exit(1);
	}
	return f;
}
