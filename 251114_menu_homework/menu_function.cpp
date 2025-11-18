#include "menu_function.hpp"

#include <cstdlib>
#include <iostream>

const MDP::MenuItem* MDP::show_menu(const MenuItem* current) {
	std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Обучайка > ";
	
	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;
	
	return current->children[user_input];
}

const MDP::MenuItem* MDP::exit(const MenuItem* current) {
	std::exit(0);
}

//
const MDP::MenuItem* MDP::study_algebra(const MenuItem* current) {
	
	std::cout << "Переходим к изучению алгебры!" << std::endl << std::endl;
	return current->parent;
}

const MDP::MenuItem* MDP::study_analysis(const MenuItem* current) {
	
	std::cout << "Переходим к изучению математического анализа!" << std::endl << std::endl;
	return current->parent;
}

const MDP::MenuItem* MDP::study_go_back(const MenuItem* current) {
	return current->parent;
}

const MDP::MenuItem* MDP::study_summ(const MenuItem* current) {
	
	std::cout << "Изучаем сложение!" << std::endl << std::endl;
	return current->parent;
}

const MDP::MenuItem* MDP::study_substract(const MenuItem* current) {

	std::cout << "Изучаем вычитание!" << std::endl;
	return current->parent;
}

const MDP::MenuItem* MDP::study_multiply(const MenuItem* current) {

	std::cout << "Изучаем умножение!" << std::endl;
	return current->parent;
}

const MDP::MenuItem* MDP::study_divide(const MenuItem* current) {

	std::cout << "Изучаем деление!" << std::endl << std::endl;
	return current->parent;
}

const MDP::MenuItem* MDP::study_go_back_subjects(const MenuItem* current) {
	return current->parent->parent;
}

const MDP::MenuItem* MDP::study_diff(const MenuItem* current) {
	std::cout << "Изучаем дифференциальное исчисление!" << std::endl << std::endl;
	return current->parent;
}
	
const MDP::MenuItem* MDP::study_integral(const MenuItem* current) {
	std::cout << "Изучаем интегральное исчисление!" << std::endl << std::endl;
	return current->parent;
}
	
	