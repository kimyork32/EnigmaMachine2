#ifndef MENU_H
#define MENU_H

#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
#include "funcionar.h"
#include <iostream>
#include <cstring>
#include <string>

class Menu{
private:
    char letra;
    Enigma enigmaDesencriptacion;
    Enigma enigmaEncriptacion;
    Funcionar work;
    std::string texto;
    std::string textoEncriptado;
    std::string textoDesencriptado;
public:
    Menu(Enigma& enigmaEncriptacion, Enigma& enigmaDesencriptacion, Funcionar& work, 
    std::string texto, std::string textoEncriptado, std::string textoDesencriptado);
    void menu();
    void clearScreen();
    void waitForEnter();
};

#endif