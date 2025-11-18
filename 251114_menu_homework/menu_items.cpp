#include  "menu_items.hpp"

#include <cstddef>

#include "menu_function.hpp"

const MDP::MenuItem MDP::STUDY_SUMM = {
	"1 - Хочу научиться складывать!", MDP::study_summ, &MDP::STUDY_ALGEBRA
};
const MDP::MenuItem MDP::STUDY_SUBSTRACT = {
	"2 - Хочу научиться вычитать!", MDP::study_substract, &MDP::STUDY_ALGEBRA
};
const MDP::MenuItem MDP::STUDY_MULTIPLY = {
	"3 - Хочу научиться умножать!", MDP::study_multiply, &MDP::STUDY_ALGEBRA
};
const MDP::MenuItem MDP::STUDY_DIVIDE = {
	"4 - Хочу научиться делить!", MDP::study_divide, &MDP::STUDY_ALGEBRA
};
const MDP::MenuItem MDP::STUDY_GO_BACK_SUBJECTS = {
	"0 - Вернуться к выбору предметов!", MDP::study_go_back_subjects, &MDP::STUDY_ALGEBRA
};

namespace {
	const MDP::MenuItem* const algebra_children[] = {
		&MDP::STUDY_GO_BACK_SUBJECTS,
		&MDP::STUDY_SUMM,
		&MDP::STUDY_SUBSTRACT,
		&MDP::STUDY_MULTIPLY,
		&MDP::STUDY_DIVIDE
	};
	const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);
}

const MDP::MenuItem MDP::STUDY_DIFF = {
	"1 - Хочу изучить дифференциальное исчисление!", MDP::study_diff, &MDP::STUDY_ANALYSIS
};

const MDP::MenuItem MDP::STUDY_INTEGRAL = {
	"2 - Хочу изучить интегральное исчисление!", MDP::study_integral, &MDP::STUDY_ANALYSIS
};

namespace {
	const MDP::MenuItem* const analysis_children[] = {
		&MDP::STUDY_GO_BACK_SUBJECTS,
		&MDP::STUDY_DIFF,
		&MDP::STUDY_INTEGRAL,
	};
	const int analysis_size = sizeof(analysis_children) / sizeof(analysis_children[0]);
}

const MDP::MenuItem MDP::STUDY_ALGEBRA = {
	"1 - Хочу изучать алгебру!", MDP::show_menu, &MDP::STUDY, algebra_children, algebra_size
};

const MDP::MenuItem MDP::STUDY_ANALYSIS = {
	"2 - Хочу изучать математический анализ!", MDP::show_menu, &MDP::STUDY, analysis_children, analysis_size
};

const MDP::MenuItem MDP::STUDY_GO_BACK = {
	"0  - Выйти в главное меню!", MDP::study_go_back, &MDP::MAIN
};

namespace {
	const MDP::MenuItem* const study_children[] = {
		&MDP::STUDY_GO_BACK,
		&MDP::STUDY_ALGEBRA,
		&MDP::STUDY_ANALYSIS
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
