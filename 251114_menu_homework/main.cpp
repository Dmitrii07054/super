#include <clocale>
#include <iostream>

int main() {
	
	int user_input;
	do {
		std::cout << "Обучайка приветсвует тебя, мой юный ученик!" << std::endl;
		std::cout << "1 - Хочу учиться математике!" << std::endl;
		std::cout << "Я лучше пойду полежу..." << std::endl;
		std::cout << "Обучайка > ";
		
		std::cin >> user_input;
		if (user_input == 1) {
			
		}
		else if (user_input == 0) {
			exit(0);
		}
		
		std::cout << std::endl;
	} while (true);
	
	return 0;
}