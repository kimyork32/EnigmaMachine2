#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void clearScreen() {
    system("cls");
}

void waitForEnter() {
    _getch();
}

int main() {
    int opc;

    while (opc != 3) {
        clearScreen();
        cout << "menu:\n"
             << "caso 1(1):\n"
             << "caso 2(2)\n"
             << "caso 3 exit(3)\n"
             << "opc: ";
        cin >> opc;

        switch (opc) {
            case 1:
                clearScreen();
                cout << "caso 1\n";
                waitForEnter();
                break;
            case 2:
                clearScreen();
                cout << "caso 2\n";
                waitForEnter();
                break;
            case 3:
                cout << "saliendo";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                waitForEnter();
        }
    }

    return 0;
}
