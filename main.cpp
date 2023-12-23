#include "Enigma.h"
#include "alfabeto.h"
#include "errores.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char** argv){
  cout << "hola mundo" << endl;
  if(argc < 3 || argc == 4){
    cerr << "usar: enigma plugboard-arhivo reflector-archivo rotorRotor-archivo posicionRotor-archivo" << endl;
    return NUMERO_INSUFICIENTE_DE_PARAMETROS;
  }
  Enigma *enigmaEncriptacion = nullptr;
  Enigma *enigmaDescriptacion= nullptr;
  try{
    enigmaEncriptacion = new Enigma(argc, argv);
  }
  catch(int error){
    delete enigmaEncriptacion;
    return error;
  }
  try{
    enigmaDescriptacion = new Enigma(argc, arvc);
  }
  catch(int error){
    delete enigmaDescriptacion;
    return error;
  }
  int opc;
  while(opc!=3){
      cout << "Enigma:\n"
          << "caso 1(1):\n"
          << "caso 2(2)\n"
          << "caso 3 exit(3)\n"
          <<"opc: ";
      cin >> opc;
      switch(opc){
          case 1:
              cout << "caso 1";
              break;
          case 2:
              cout << "caso 2";
              break;
          case 3:
              cout << "saliendo";
      }
  }
  char letra;
  while(!cin.eof()){
    cin >> letra;
    if(cin.fail()){
      break;
    }

    if(letra - 'A' < 0 || LONGITUD_ALFABETO -1 < letra - 'A'){
      cerr << letra << "Los caracteres de entrada deben ser letras en mayusculas de la A a la Z" << endl;
      delete enigmaEncriptacion;
      delete enigmaDescriptacion;
      return CARACTER_DE_ENTRADA_INVALIDO;
    }
    enigmaEncriptacion->cifrarMensaje(letra);
    cout << letra;
  }
  delete enigmaEncriptacion;
  return SIN_ERROR;
}
