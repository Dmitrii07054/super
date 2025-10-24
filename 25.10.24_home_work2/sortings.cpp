#include "sortings.hpp"

void dim::sortings::insertion_sort(int* const arr, const int size) { 
    int i, k, j;  
    for (i = 1; i < size; i++) {  
        k = arr[i];  
        j = i - 1;
        while (j >= 0 && arr[j] > k) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = k;  
    }  
}  

