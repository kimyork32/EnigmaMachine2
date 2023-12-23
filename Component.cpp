#include "Component.h"
#include <iostream>
#include <fstream>

using namespace std;

Component::Component(const char* ruta) {
  fstream flujo_entrada;
  flujo_entrada.open(ruta);
  int num;
  int contador = 0;
  while (flujo_entrada >> num) {
    if (contador % 2 == 0) {
      par_entrada1_.push_back(num);
    } else {
      par_entrada2_.push_back(num);
    }
    contador++;
  }
  flujo_entrada.close();
}

int Component::mapear(int entrada) {
  int longitud = par_entrada1_.size();
  for (int i = 0; i < longitud; i++) {
    if (entrada == par_entrada1_[i]) {
      return par_entrada2_[i];
    }
    if (entrada == par_entrada2_[i]) {
      return par_entrada1_[i];
    }
  }
  return entrada;
}
