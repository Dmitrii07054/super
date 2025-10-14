#include <iostream>
#include "array_operations.h"

using namespace std;

// Создание массива
int* createArray(int n) {
    return new int[n];
}

// Ввод массива
void inputArray(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Вывод массива
void printArray(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Освобождение памяти
void deleteArray(int* arr) {
    delete[] arr;
}

// Сортировка вставками
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Перемещаем элементы arr[0..i-1], которые больше key
        // на одну позицию вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}