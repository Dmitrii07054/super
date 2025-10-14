#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

// Создание массива
int* createArray(int n);

// Ввод массива
void inputArray(int* arr, int n);

// Вывод массива
void printArray(int* arr, int n);

// Освобождение памяти
void deleteArray(int* arr);

// Сортировка вставками
void insertionSort(int* arr, int n);

#endif