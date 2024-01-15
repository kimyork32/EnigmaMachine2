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
  vector<string> configuraciones;
  int num_de_rotores_;
  Component *tablero_enchufes_{nullptr};
  Component *reflector_{nullptr};
  // void inicializar(int argc, vector<string> argv);
public:
  Enigma(int argc, vector<string> argv);
  ~Enigma();
  void verificarConfiguracionTableroEnchufes(string ruta, vector<int>& contactos);
  void verificarConfiguracionReflector(string ruta, vector<int>& contactos);
  void verificarConfiguracionRotor(string ruta, vector<int>& contactos);
  void verificarConfiguracionPosicionRotor(string ruta);
  
  bool esEntradaTableroEnchufesValida(string ruta, fstream& flujo_entrada, int& numero_indice);
  
  bool esRangoCorrectoNumero(int num);
  
  int verificarAparecioAntes(vector<int> contactos, int num, int posicion);
  
  void cifrarMensaje(char& letra);

  vector<string> getConfiguraciones();
};

#endif
