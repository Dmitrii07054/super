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
	
	MDP::MenuItem study = { "1 - Хочу учиться математике!", MDP::study };
	MDP::MenuItem exit = { "0 - Я лучше пойду полежу...", MDP::exit };
	
	
	MDP::MenuItem* main_children[] = { &exit, &study };
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
	
	int user_input;
  do {
    std::cout << "Обучайка приветсвует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < main_size; i++) {
      std::cout << main_children[i]->title << std::endl;
    }
    std::cout << main_children[0]->title << std::endl;
    std::cout << "Обучайка > ";
    
    std::cin >> user_input;
    main_children[user_input]->func();
    
    std::cout << std::endl;
  } while (true);
  
  return 0;
}
