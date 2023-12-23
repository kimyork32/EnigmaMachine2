#ifndef FUNCIONAR_H
#define FUNCIONAR_H
#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
class Funcionar{
private:
    char letra;
    int argc;
    char** argv;
public:
    Funcionar();
    encriptar();
    desencriptar();
};
#endif