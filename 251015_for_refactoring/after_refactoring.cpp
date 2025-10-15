#include <cmath>
#include <iostream>

int main() {
	const int size = 3;	
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i << " элемент" << std::endl;
        std::cin >> arr[i];
    }
	
	bool is_increasing = true;
	int i = 0;
    while (i < size) {
        if (arr[i] > arr[i + 1]) {
            is_increasing = false;
			break;	
		}
        i++;
    }
	
    if (is_increasing) {
        std::cout << "Последовательность возрастает";
        std::cout << std::endl;
    } else {
        std::cout << "Последовательность не возрастает";
        std::cout << std::endl;
    }
	
    return 0;
}
