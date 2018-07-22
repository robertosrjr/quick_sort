/*
 ============================================================================
 Name        : QuickSort.c
 Author      : Roberto S. Ramos Jr
 Version     : 1.0
 Copyright   : robertosrjr@gmail.com
 Description : Algoritmos e Estrutura de Dados em C - QuickSort in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int vec[] = {12, 58, 16, 38, 31, 23, 37, 11, 42, 27, 47, 31};
int tamanho = 12;
int qtd = 0;

int main(void) {

	puts("Algoritmos e Estrutura de Dados em C - QuickSort");

	int qtde = 0;
	printf("Imprimir vector: ");
	print_vector();
	printf("\n");

	qtde = quickSort(vec, tamanho, qtd);
	printf("Imprimir vector ordenado: ");
	print_vector();
	printf("\n");

	printf("Quantidade de Iterações: %d", qtde);

	return EXIT_SUCCESS;
}

int quickSort(int vec[], int left, int right, int qtd) {

	int r;
	if (right > left) {

		r = particiona(vec, left, right);
		qtd = quickSort(vec, left, r - 1, qtd);
		qtd = quickSort(vec, r + 1, right, qtd);
	}
	return (qtd +1);
}

int particiona(int vec[], int left, int right) {

	int i, j;
	i = left;
	for (j = left + 1; j <= right; ++j) {

		if (vec[j] < vec[left]) {

			++i;
			troca(&vec[i], &vec[j]);
		}
	}
	troca(&vec[left], &vec[i]);
	return i;
}

void troca(int* a, int* b) {

	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_vector() {

	int i;
	for (i = 0; i < tamanho -1; i++) {

		printf("%d, ", vec[i]);
	}
}

