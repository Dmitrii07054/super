#include "io.hpp"
#include <iostream>

void dim::print_array(const char* const comment, int* arr, const int size) {
	std::cout << comment << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}