#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_function.hpp"

int main() {
  
	MDP::MenuItem study_summ = { "1 - Хочу учиться математике!", MDP::study_summ };
	MDP::MenuItem study_substract = { "2 - Хочу научиться вычитать!", MDP::study_substract };
	MDP::MenuItem study_multiply = { "3 - Хочу научиться умножать!", MDP::study_multiply };
	MDP::MenuItem study_divide = { "4 - Хочу научиться делить!", MDP::study_divide };
	MDP::MenuItem study_go_back = { "0 - Выйти в главное меню", MDP::study_go_back };
  
	MDP::MenuItem* study_children[] = { 
		&study_go_back,
		&study_summ,
		&study_substract,
		&study_multiply,
		&study_divide,
	};
	const int study_size = sizeof(study_children) / sizeof(study_children[0]);
	
	MDP::MenuItem study = { "1 - Хочу учиться математике!", MDP::show_menu, study_children, study_size };
	MDP::MenuItem exit = { "0 - Я лучше пойду полежу...", MDP::exit };
	
	
	MDP::MenuItem* main_children[] = { &exit, &study };
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
	
	MDP::MenuItem main = { nullptr, MDP::show_menu, main_children, main_size };
	
	study_summ.parent = &study;
	study_substract.parent = &study;
	study_multiply.parent = &study;
	study_divide.parent = &study;
	study_go_back.parent = &study;
	
	study.parent = &main;
	exit.parent = &main;
	
	const MDP::MenuItem* current = &main;
	do {
		current = current->func(current);
	} while (true);
    
	return 0;
}
