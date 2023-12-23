#ifndef ROTOR_H
#define ROTOR_H

#include "Alfabeto.h"  
#include <vector>

using namespace std;

class Rotor {
private:
  int posicion_actual_;
  int posicion_anterior_;
  int contactos_[LONGITUD_ALFABETO];
  vector<int> muescas_;

public:
  Rotor(const char* ruta, int posicion_inicial);
  
  int obtenerPosicionActual();

  int obtenerPosicionAnterior();

  void rotar();

  int desplazarArriba(int indice_entrada);
  
  int desplazarAbajo(int indice_entrada);

  int mapearAdelante(int indice_entrada);

  int mapearAtras(int contacto);

  bool estaEnMuescaActual();
};

#endif