#pragma once
#ifndef CORELIB_H
#define CORELIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ----------------- Códigos de colores ANSI ----------------- */

// Texto normal
#define BLK "\x1B[0;30m"
#define RED "\x1B[0;31m"
#define GRN "\x1B[0;32m"
#define YEL "\x1B[0;33m"
#define BLU "\x1B[0;34m"
#define MAG "\x1B[0;35m"
#define CYN "\x1B[0;36m"
#define WHT "\x1B[0;37m"

// Texto en negrita
#define BBLK "\x1B[1;30m"
#define BRED "\x1B[1;31m"
#define BGRN "\x1B[1;32m"
#define BYEL "\x1B[1;33m"
#define BBLU "\x1B[1;34m"
#define BMAG "\x1B[1;35m"
#define BCYN "\x1B[1;36m"
#define BWHT "\x1B[1;37m"

// Texto subrayado
#define UBLK "\x1B[4;30m"
#define URED "\x1B[4;31m"
#define UGRN "\x1B[4;32m"
#define UYEL "\x1B[4;33m"
#define UBLU "\x1B[4;34m"
#define UMAG "\x1B[4;35m"
#define UCYN "\x1B[4;36m"
#define UWHT "\x1B[4;37m"

// Fondos
#define BLKB "\x1B[40m"
#define REDB "\x1B[41m"
#define GRNB "\x1B[42m"
#define YELB "\x1B[43m"
#define BLUB "\x1B[44m"
#define MAGB "\x1B[45m"
#define CYNB "\x1B[46m"
#define WHTB "\x1B[47m"

// Fondos de alta intensidad
#define BLKHB "\x1B[0;100m"
#define REDHB "\x1B[0;101m"
#define GRNHB "\x1B[0;102m"
#define YELHB "\x1B[0;103m"
#define BLUHB "\x1B[0;104m"
#define MAGHB "\x1B[0;105m"
#define CYNHB "\x1B[0;106m"
#define WHTHB "\x1B[0;107m"

// Texto de alta intensidad
#define HBLK "\x1B[0;90m"
#define HRED "\x1B[0;91m"
#define HGRN "\x1B[0;92m"
#define HYEL "\x1B[0;93m"
#define HBLU "\x1B[0;94m"
#define HMAG "\x1B[0;95m"
#define HCYN "\x1B[0;96m"
#define HWHT "\x1B[0;97m"

// Texto en negrita de alta intensidad
#define BHBLK "\x1B[1;90m"
#define BHRED "\x1B[1;91m"
#define BHGRN "\x1B[1;92m"
#define BHYEL "\x1B[1;93m"
#define BHBLU "\x1B[1;94m"
#define BHMAG "\x1B[1;95m"
#define BHCYN "\x1B[1;96m"
#define BHWHT "\x1B[1;97m"

// Resetear colores
#define CRST "\x1B[0m"
#define COLOR_RESET "\x1B[0m"
#define CRESET "\x1B[0m"


/* ----------------- Funciones útiles ----------------- */

// Intercambia dos enteros
static inline void swap_int(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Bubble Sort
static inline void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap_int(&arr[j], &arr[j + 1]);
			}
		}
	}
}

// Insertion Sort
static inline void insertion_sort(int arr[], int n) {
	int key, j;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Función auxiliar para Quick Sort (partición)
static inline int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap_int(&arr[i], &arr[j]);
		}
	}
	swap_int(&arr[i + 1], &arr[high]);
	return i + 1;
}

// Quick Sort
static inline void quick_sort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

// Búsqueda lineal
static inline int linear_search(int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) return i;
	}
	return -1;
}

// Búsqueda binaria (requiere array ordenado)
static inline int binary_search(int arr[], int n, int key) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

// Imprime un array de enteros
static inline void print_array(const int arr[], int n) {
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}




#endif // CORELIB_H