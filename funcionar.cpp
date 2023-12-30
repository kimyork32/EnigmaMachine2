#include "funcionar.h"
#include "Enigma.h"
Funcionar::Funcionar(){}

void Funcionar::encriptar(Enigma& enigma, ifstream texto, std::ofstream textoEncriptado){
  if (!texto.is_open() || !textoEncriptado.is_open()) {
      std::cerr << "Error al abrir uno de los archivos" << std::endl;
      return;
  }
  char letra;
  while (texto >> letra) {
      if (letra - 'A' < 0 || LONGITUD_ALFABETO - 1 < letra - 'A') {
          std::cerr << letra << "Los caracteres de entrada deben ser letras en mayúsculas de la A a la Z" << std::endl;
          return;
      }
      enigma.cifrarMensaje(letra);
      textoEncriptado << letra;
  }

  texto.close();
  textoEncriptado.close();
}

void Funcionar::desencriptar(Enigma& enigma, std::ifstream textoEncriptado, std::ofstream textoDesencriptado){
  if (!textoEncriptado.is_open() || !textoDesencriptado.is_open()) {
      std::cerr << "Error al abrir uno de los archivos" << std::endl;
      return;
  }
  char letra;
  while (textoEncriptado >> letra) {
      if (letra - 'A' < 0 || LONGITUD_ALFABETO - 1 < letra - 'A') {
          std::cerr << letra << "Los caracteres de entrada deben ser letras en mayúsculas de la A a la Z" << std::endl;
          return;
      }
      enigma.cifrarMensaje(letra);
      textoDesencriptado << letra;
  }

  textoEncriptado.close();
  textoDesencriptado.close();
}