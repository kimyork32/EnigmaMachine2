#ifndef FUNCIONAR_H
#define FUNCIONAR_H
#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
#include <fstream>
#include <iostream>
class Funcionar{
private:
    string oracion;
public:
    Funcionar();
    void encriptar(Enigma& enigma, string ruta);
    void borrarOracion();
    void MostrarContenidoText(string ruta);
    string getOracion();
    
};
#endif