/*
 * Sort.cpp
 *
 *  Created on: 2015-8-26
 *      Author: jz
 */


#include "Sort.h"


Sort::Sort() {
        // TODO Auto-generated constructor stub


}


Sort::~Sort() {
        // TODO Auto-generated destructor stub
}


void Sort::insert_sort(int array[], int n) {
        for (int i = 1; i < n; ++i) {
                int val = array[i];
                int j = i - 1;
                while (j >= 0 && array[j] > val) {
                        array[j + 1] = array[j];
                        --j;
                }
                array[j + 1] = val;
        }
}


inline int left(int i) {
        return (i << 1) + 1;
}


inline int right(int i) {
        return (i + 1) << 1;
}


inline int parent(int i) {
        return ((i + 1) >> 1) - 1;
}


inline void swap(int &a, int &b) {
        int c = a;
        a = b;
        b = c;
}


void heap_adjust(int a[], int i, int heap_n) {
        int lchild = left(i);
        int rchild = right(i);
        int max = i;
        if (i <= parent(heap_n - 1)) {
                if (lchild < heap_n && a[lchild] > a[i]) {
                        max = lchild;
                }
                if (rchild < heap_n && a[rchild] > a[max]) {
                        max = rchild;
                }
                if (max != i) {
                        swap(a[i], a[max]);
                        heap_adjust(a, max, heap_n);
                }
        }
}


void build_heap(int a[], int n) {
        for (int i = parent(n - 1); i >= 0; --i) {
                heap_adjust(a, i, n);
        }
}


void Sort::heap_sort(int array[], int n) {
        build_heap(array, n);
        for (int i = n - 1; i > 0; --i) {
                swap(array[0], array[i]);
                heap_adjust(array, 0, --n);
        }
}


int partition(int a[], int p, int r) {
        int i = p - 1;
        for (int j = p; j < r; ++j) {
                if (a[j] < a[r]) {
                        swap(a[++i], a[j]);
                }
        }
        swap(a[++i], a[r]);
        return i;
}


void quick_sort_sub(int a[], int p, int r) {
        if (p < r) {
                int q = partition(a, p, r);
                quick_sort_sub(a, p, q - 1);
                quick_sort_sub(a, q + 1, r);
        }
}


void Sort::select_sort(int array[], int n) {
        for (int i = 0; i < n; ++i) {
                int k = i;
                for (int j = i + 1; j < n; ++j) {
                        if (array[j] < array[k])
                                k = j;
                }
                swap(array[k], array[i]);
        }
}


void Sort::quick_sort(int array[], int n) {
        quick_sort_sub(array, 0, n - 1);
}


void Sort::shell_sort(int array[], int n) {
        for (int gap = n >> 1; gap > 0; gap >>= 1) {
                for (int i = gap; i < n; ++i) {
                        for (int j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap) {
                                swap(array[j], array[j + gap]);
                        }
                }
        }
}


void Sort::bubble_sort(int array[], int n) {
        for (int i = 0; i < n; ++i) {
                for (int j = n - 1; j > i; --j) {
                        if (array[j] < array[j - 1])
                                swap(array[j], array[j - 1]);
                }
        }
}


void merge(int array[], int tmp[], int left, int right) {
        int m = (left + right) >> 1;
        int i = left, j = m + 1;
        for (int k = left; k <= right; ++k) {
                tmp[k] = array[i] < array[j] ? array[i++] : array[j++];
                if (i > m) {
                        while (j <= right) tmp[++k] = array[j++];
                        break;
                }
                if (j > right){
                        while (i <= m) tmp[++k] = array[i++];
                        break;
                }
        }
        for (int k = left; k <= right; ++k) {
                array[k] = tmp[k];
        }
}


void merge_sort_sub(int array[], int tmp[], int left, int right) {
        if (left < right) {
                int m = (left + right) >> 1;
                merge_sort_sub(array, tmp, left, m);
                merge_sort_sub(array, tmp, m + 1, right);
                merge(array, tmp, left, right);
        }
}


void Sort::merge_sort(int array[], int n) {
        int *tmp = new int[n];
        merge_sort_sub(array, tmp, 0, n - 1);
        delete[] tmp;
}
