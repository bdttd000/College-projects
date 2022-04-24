#include "algorytmy.h"

// INSERT SORT

void insert_sort(int *tab, int n) {
    int i,x,j;
    for(i=1; i<n;i++) {
        x=tab[i];
        j=i-1;
        while( tab[j]>x && j>=0) {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=x;
    }
}

// SELECTION SORT

int selection_sort_min_number_index(int *tab, int n, int i) {
    int x = i;
    for (i+1; i<n; i++) {
        if (tab[i]<tab[x]) x=i;
    }
    return x;
}

void selection_sort(int *tab, int n) {
    int i,x,j,y;
    for (i=0; i<n; i++) {
        x = selection_sort_min_number_index(tab,n,i);
        if (i != x) {
            y = tab[i];
            tab[i] = tab[x];
            tab[x] = y;
        }
    }
}

// BUBBLE SORT

void bubble_sort(int *tab, int n) {
    int i,x,j;
    do {
        for(i=0; i<n-1;i++) {
            if (tab[i]>tab[i+1]) {
                x=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=x;
            }
        }
        n-=1;
    } while (n>1);
}

// QUICKSORT

int quicksort_divide(int *tab, int low, int high) {
    int pivot, i, j, temp;
            pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (tab[i] <= tab[pivot] && i <= high)
            {
                i++;
            }
            while (tab[j] > tab[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
        temp = tab[j];
        tab[j] = tab[pivot];
        tab[pivot] = temp;
        return j;
}

void quickSort(int *tab, int low, int high) {
    int pivot, i, j, temp;
    if (low < high)
    {
        j = quicksort_divide(tab, low, high);
        quickSort(tab, low, j - 1);
        quickSort(tab, j + 1, high);
    }
}



// SEHLLSORT

void shellSort(int *tab, int n) {
    int j,i,x,h;
    for(h=1; h<n; h=3*h+1);
    h/=9;
    if (h==0) h=1;
    while (h>0) {
        for (j=n-h-1;j>=0;j--) {
            x = tab[j];
            i = j+h;
            while ((i<n) && (x>tab[i])) {
                tab[i-h]=tab[i];
                i+=h;
            }
            tab[i-h]=x;
        }
        h/=3;
    }
}

// HEAPSORT

void heapsort_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapsort_heapify(int *tab, int n, int i) {
    int largest, left, right;
    largest = i;
    left = 2*i+1;
    right = 2*i+2;
    if (left<n && tab[left]>tab[largest]) largest = left;
    if (right<n && tab[right]>tab[largest]) largest = right;
    if (largest!=i) {
        heapsort_swap(&tab[i], &tab[largest]);
        heapsort_heapify(tab, n, largest);
    }
}

void heapSort(int *tab, int n) {
    int i;
    for (i=n/2-1; i>=0; i--) heapsort_heapify(tab, n, i);
    for (i=n-1; i>=0; i--) {
      heapsort_swap(&tab[0], &tab[i]);
      heapsort_heapify(tab, i, 0);
    }
}

// REST OF FUNCTIONS

void time_diff(int before_sec, int after_sec, int before_usec, int after_usec) {
    if (after_usec<before_usec) {
        after_usec += 1000000;
        after_sec -= 1;
    }
    
    printf("%ld,%ld",(after_sec-before_sec),(after_usec-before_usec));
}

void generateRandomArray(int *tabRandom, int n) {
    int number;
    for (int i = 0; i < n; i++) {
        number = (rand() % 201) - 100;
        tabRandom[i] = number;
    }
}

void saveToFile(int *tab, int n) {
	FILE *plik;
    plik=fopen("dane.txt","w");
	for (int i=0; i<n; i++) {
		fprintf(plik,"%d\n",tab[i]);
	}
	fclose(plik); 	
}

void getArray(int *tab, int n) {
	FILE *plik;
    plik=fopen("dane.txt","r");
	for (int i=0; i<n; i++) {
		fscanf(plik,"%d\n",tab[i]);
	}
	fclose(plik); 	
}

void reverseTab(int *tab, int *tab2, int n) {
    for (int i = 0; i < n; i++) {
        tab2[i] = tab[n-1-i];
    }
}
