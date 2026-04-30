#include "vector.hpp"

#include <iostream>

using dim::Vector;

template<typename T>
Vector<T>::Vector() {
	arr = new T[capacity];
	size = 0;
}

template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position > size) {
		return false;
	}
	
	if (size == capacity) {
		capacity *= 2;
		T* new_arr = new T[capacity];
	
		for (std::size_t i = 0; i < position; i++) {
			new_arr[i] = arr[i];
		}
		for (std::size_t i = position + 1; i < size; i++) {
			new_arr[i] = arr[i-1];
		}
		
		delete[] arr;
		arr = new_arr;
	} else {
		for (std::size_t i = position + 1; i < size; i++) {
			arr[i] = arr[i-1];
		}
	}
	
	arr[position] = value;
	++size;
	
	return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
	if (size == 0) {
		std::cout << "Empty!" << std::endl;
		return;
	}
	
	for (std::size_t i = 0; i < size; i++) {
		std::cout << "[" << i << "] = " << arr[i] << std::endl;
	}
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	if (size == capacity) {
		capacity *= 2;
		T* new_arr = new T[capacity];
		
		for (std::size_t i = 0; i < size; i++) {
			new_arr[i] = arr[i];
		}
		
		delete[] arr;
		arr = new_arr;
	}
	arr[size] = value;
	++size;
}

template<typename T>
bool Vector<T>::remove_first(const T& value)
 {
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			for (std::size_t j = i; j < size-1; j++) {
				arr[j] = arr[j+1];
			}
			--size;
		
			if (size <= capacity / 4) {
				std::size_t new_capacity = capacity / 2;
				if (new_capacity < START_CAPACITY) {
					new_capacity = START_CAPACITY;
				}
				T* new_arr = new T[new_capacity];
				for (std::size_t i = 0; i < new_capacity; i++) {
					new_arr[i] = arr[i];
				}
				delete[] arr;
				capacity = 0;
				size = 0;
				arr = new_arr;
				
			}
			
			return true;
		}
		
	}
	return false;
}

