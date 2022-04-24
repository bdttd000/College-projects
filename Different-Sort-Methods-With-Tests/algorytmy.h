#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#ifndef algorytmy_h
#define algorytmy_h

// First group
void insert_sort(int *tab, int n);
void selection_sort(int *tab, int n);
int selection_sort_min_number_index(int *tab, int n, int i);
void bubble_sort(int *tab, int n);

// Second group
void quickSort(int *tab, int low, int high);
int quicksort_divide(int *tab, int low, int high);
void shellSort(int *tab, int n);
void heapSort(int *tab, int n);
void heapsort_heapify(int *tab, int n, int i);
void heapsort_swap(int *a, int *b);

// Rest of functions
void time_diff(int before_sec, int after_sec, int before_usec, int after_usec);
void generateRandomArray(int *tabRandom, int n);
void saveToFile(int *tab, int n);
void getArray(int *tab, int n);
void reverseTab(int *tab, int *tab2, int n);

#endif /* algorytmy_h */
