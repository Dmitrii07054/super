#include <iostream>
#include "array_operations.h"

using namespace std;

int main() {
    int n;
    cout << "Введите длину массива: ";
    cin >> n;
    
    // Создаем массив заданного размера
    int* arr = createArray(n);
    
    cout << "Введите элементы массива:" << endl;
    inputArray(arr, n);
    
    // Выводим исходный массив
    cout << "Исходный массив: ";
    printArray(arr, n);
    
    // Сортируем массив
    insertionSort(arr, n);
    
    // Выводим отсортированный массив
    cout << "Отсортированный массив: ";
    printArray(arr, n);
    
    deleteArray(arr); // Освобождаем память
    return 0;
}