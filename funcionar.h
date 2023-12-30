#ifndef FUNCIONAR_H
#define FUNCIONAR_H
#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
#include <fstream>
#include <iostream>
class Funcionar{
private:
    char letra;
public:
    Funcionar();
    void encriptar(Enigma& enigma, std::ifstream texto, std::ofstream textoEncriptado);
    void desencriptar(Enigma& enigma, std::ifstream textoEncriptado, std::ofstream textoDesencriptado);
};
#endif