#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char** argv){
  cout << "hola mundo" << endl;

  // ARGUMENTOS
  if(argc < 3 || argc == 4){
    cerr << "usar: enigma plugboard-arhivo reflector-archivo rotorRotor-archivo posicionRotor-archivo" << endl;
    return NUMERO_INSUFICIENTE_DE_PARAMETROS;
  }

  // CREACION DE INSTANCIAS ENIGMA
  Enigma *enigmaEncriptacion = nullptr;
  Enigma *enigmaDesencriptacion= nullptr;
  try{
    enigmaEncriptacion = new Enigma(argc, argv);
  }
  catch(int error){
    delete enigmaEncriptacion;
    return error;
  }
  try{
    enigmaDesencriptacion = new Enigma(argc, argv);
  }
  catch(int error){
    delete enigmaDesencriptacion;
    return error;
  }

  // CREANDO FICHEROS
  string nombreArchivo = "texto.txt";
  ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }
  
  return SIN_ERROR;
}
