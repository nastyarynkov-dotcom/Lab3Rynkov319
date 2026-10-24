#include <iostream>
#include <cmath> // Необхідно для функцій sin() та pow()

using namespace std;

// Оголошення функцій
// 1. If5. Знайти кількість додатних і від'ємних чисел серед трьох введених.
void task_if5();

// 2. If24. Знайти значення функції f(x).
void task_if24();

// 3. Figure 8 (Варіант 8). Визначити належність точки жовтій області.
void task_figure8();

int main() {
    int menu;
    cout << "Task number (1, 2 or 3): ";
    cin >> menu;

    // Перемикання між завданнями
    switch (menu) {
        case 1: task_if5(); break;     // Завдання 1 (If5)
        case 2: task_if24(); break;    // Завдання 2 (If24)
        case 3: task_figure8(); break; // Завдання 3 (Figure 8 - жовта фігура)
        default: cout << "Wrong task! (Only 1, 2, 3)" << endl; // Повідомлення про помилку
    }

    return 0;
}

// Завдання 1: реалізація (If5)
void task_if5() {
    int a, b, c;
    cout << "\n************* If 5 *****************" << endl;
    cout << "Enter three integers (a b c): ";
    cin >> a >> b >> c;

    if (cin) { // Перевірка коректності введення
        int positiveCount = 0;
        int negativeCount = 0;

        // Перевірка першого числа
        if (a > 0) positiveCount++;
        else if (a < 0) negativeCount++;

        // Перевірка другого числа
        if (b > 0) positiveCount++;
        else if (b < 0) negativeCount++;

        // Перевірка третього числа
        if (c > 0) positiveCount++;
        else if (c < 0) negativeCount++;

        cout << "Positive numbers count: " << positiveCount << endl;
        cout << "Negative numbers count: " << negativeCount << endl;
    } 
    else {
        cout << "Wrong integers!" << endl;
    }
}

// Завдання 2: реалізація (If24)
void task_if24() {
    double x;
    cout << "\n************* If 24 *****************" << endl;
    cout << "Enter real number x: ";
    cin >> x;

    if (!cin) { // Перевірка коректності введення
        cout << "Wrong input!" << endl;
        return;
    }

    double f;
    // Обчислення значення функції залежно від x
    if (x > 0) {
        f = 2 * sin(x);
    } else {
        f = 6 - x;
    }

    cout << "f(" << x << ") = " << f << endl;
}

// Завдання 3: реалізація (Figure 8 - Жовта фігура)
void task_figure8() {
    double a;    // сторона квадрата
    double x, y; // координати точки

    cout << "\n************* Figure 8 *****************" << endl;
    cout << "Введіть сторону квадрата a (a > 0): ";
    cin >> a;

    if (cin.fail() || a <= 0) {
        cerr << "Некоректні дані!" << endl;
        return;
    }

    cout << "Введіть координати точки (x, y): ";
    cin >> x >> y;

    if (!cin) {
        cout << "Не числові дані!" << endl;
        return;
    }

    // 1. Верхній правий трикутник: x >= 0, y >= 0, обмежений прямою y = a/2 - x
    bool inUpperTriangle = (x >= 0) && (y >= 0) && (y <= (a / 2.0) - x);

    // 2. Нижня жовта частина:
    // Центр вписаного кола: (0, -a/2), радіус R = a/2
    double xc = 0.0;
    double yc = -a / 2.0;
    double R = a / 2.0;
    double circleDist = pow(x - xc, 2) + pow(y - yc, 2);

    // Точка в правій половині вписаного кола
    bool inCircleRight = (circleDist <= R * R) && (x >= 0);

    // Точка в кутку під діагоналлю (y = 2x - a)
    bool inLowerCorner = (x >= 0) && (y <= 0) && (y >= -a) && (y <= 2 * x - a);

    bool inLowerYellow = inCircleRight || inLowerCorner;

    // Перевірка загальної належності жовтій області
    if (inUpperTriangle || inLowerYellow) {
        cout << "Точка належить жовтій області (Figure 8)." << endl;
    } else {
        cout << "Точка НЕ належить жовтій області (Figure 8)." << endl;
    }
}
