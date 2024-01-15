#ifndef MENU_H
#define MENU_H

#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
#include "funcionar.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

class Menu{
private:
    char letra;
    Enigma maquinaEncriptar;
    Enigma maquinaDesencriptar;
    Funcionar work;

public:
    Menu();
    void menu();
    void clearScreen();
    void waitForEnter();
};

#endif