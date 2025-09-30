#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    int x = 10, y = 5;
    
    cout << "=== Простая модульная программа ===" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << endl;
    
    cout << "Сложение: " << add(x, y) << endl;
    cout << "Вычитание: " << subtract(x, y) << endl;
    cout << "Умножение: " << multiply(x, y) << endl;
    
    try {
        cout << "Деление: " << divide(x, y) << endl;
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    cout << endl;
    system("pause");
    return 0;
}