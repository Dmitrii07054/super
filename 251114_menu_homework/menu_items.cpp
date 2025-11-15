#include  "menu_items.hpp"

#include <cstddef>

#include "menu_function.hpp"

const MDP::MenuItem MDP::STUDY_SUMM = {
	"1 - Хочу научиться складывать!", MDP::study_summ, &MDP::STUDY
};
const MDP::MenuItem MDP::STUDY_SUBSTRACT = {
	"2 - Хочу научиться вычитать!", MDP::study_substract, &MDP::STUDY
};
const MDP::MenuItem MDP::STUDY_MULTIPLY = {
	"3 - Хочу научиться умножать!", MDP::study_multiply, &MDP::STUDY
};
const MDP::MenuItem MDP::STUDY_DIVIDE = {
	"4 - Хочу научиться делить!", MDP::study_divide, &MDP::STUDY
};
const MDP::MenuItem MDP::STUDY_GO_BACK = {
	"0 - Вернуться назад!", MDP::study_go_back, &MDP::STUDY
};

namespace {
	const MDP::MenuItem* const study_children[] = {
		&MDP::STUDY_GO_BACK,
		&MDP::STUDY_SUMM,
		&MDP::STUDY_SUBSTRACT,
		&MDP::STUDY_MULTIPLY,
		&MDP::STUDY_DIVIDE
	};
	const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const MDP::MenuItem MDP::STUDY = {
	"1 - Хочу учиться математике!", MDP::show_menu, &MDP::MAIN, study_children, study_size
};
const MDP::MenuItem MDP::EXIT = {
	"0 - Я лучше пойду полежу...", MDP::exit, &MDP::MAIN
};

namespace {
	const MDP::MenuItem* const main_children[] = {
		&MDP::EXIT,
		&MDP::STUDY
	};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const MDP::MenuItem MDP::MAIN = {
	nullptr, MDP::show_menu, nullptr, main_children, main_size
};
