#ifndef ENIGMA_H
#define ENIGMA_H

#include "Component.h"
#include "Rotor.h"
#include <fstream>
#include <vector>

using namespace std;

class Enigma {
private:
  vector<Rotor> rotores_;
  vector<int> posiciones_rotores_;
  int num_de_rotores_;
  Component *tablero_enchufes_{nullptr};
  Component *reflector_{nullptr};

public:
  Enigma(int argc, char** argv);
  
  ~Enigma();
  
  void verificarConfiguracionTableroEnchufes(const char* ruta, vector<int>& contactos);
  void verificarConfiguracionReflector(const char* ruta, vector<int>& contactos);
  void verificarConfiguracionRotor(const char* ruta, vector<int>& contactos);
  void verificarConfiguracionPosicionRotor(const char* ruta);
  
  bool esEntradaTableroEnchufesValida(const char* ruta, fstream& flujo_entrada, int& numero_indice);
  
  bool esRangoCorrectoNumero(int num);
  
  int verificarAparecioAntes(vector<int> contactos, int num, int posicion);
  
  void cifrarMensaje(char& letra);
};

#endif
