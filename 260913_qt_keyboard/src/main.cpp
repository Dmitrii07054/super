#include <QApplication>

#include "welcome_window.hpp"
#include "keyboard_window.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    dim::WelcomeWindow welcome;
    dim::KeyBoardWindow keyboard_window; 
	
	QObject::connect(&welcome, &dim::WelcomeWindow::open_keyboard, &keyboard_window,
                 [&]() {
                     keyboard_window.show();
                     welcome.hide();
                 });
				
    welcome.show();

    return app.exec();
}
