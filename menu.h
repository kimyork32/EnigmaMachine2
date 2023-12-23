#ifndef MENU_H
#define MENU_H

#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
#include <iostream>
#include <cstring>
#include <string>

class Menu{
private:
    char letra;
public:
    Menu();
    void menu(Enigma&enigmaEncriptacion, Enigma& enigmaDesencriptacion);
    void encriptar();
    void clearScreen();
    void waitForEnter();
};

#endif