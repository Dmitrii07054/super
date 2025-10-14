#include <iostream>

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Сдвигаем элементы больше key вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int size;
    
    // Ввод размера массива
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    
    // Создание динамического массива
    int* arr = new int[size];
    
    // Ввод элементов
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    
    // Сортировка
    insertionSort(arr, size);
    
    // Вывод результата
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Освобождение памяти
    delete[] arr;
    
    return 0;
}



#include "io.hpp"
#include "sortings.hpp"

int main() {
    int arr[] = {1, 8, 2, 5, 3, 11};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	biv::print_array("Массив до сортировки:", arr, arr_size);
    
    biv::sortings::bubble_sort(arr, arr_size);

    biv::print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}