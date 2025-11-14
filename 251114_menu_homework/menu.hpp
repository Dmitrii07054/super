#pragma once

namespace MDP {
	struct MenuItem {
		const char* const title;
		void (*func)();
	};
}
