#include "Rotor.h"
#include "Alfabeto.h"  
#include <iostream>
#include <fstream>


Rotor::Rotor(string ruta, int posicion_inicial){
  fstream flujo_entrada;
  flujo_entrada.open(ruta);
  int num;
  int contador = 0;
  while(flujo_entrada >> num){
    if(contador < LONGITUD_ALFABETO){
      contactos_[contador] = num;
    }
    else{
      muescas_.push_back(num);
    }
    contador++;
  }
  posicion_actual_ = posicion_inicial;
}

int Rotor::obtenerPosicionAnterior(){
  return posicion_anterior_;
}

int Rotor::obtenerPosicionActual(){
  return posicion_actual_;
}

void Rotor::rotar(){
  posicion_anterior_ = posicion_actual_;
  posicion_actual_ = (posicion_actual_ + 1) % LONGITUD_ALFABETO;
}

int Rotor::desplazarArriba(int indice_entrada){
  return (indice_entrada - obtenerPosicionActual() + LONGITUD_ALFABETO) \
  % LONGITUD_ALFABETO;
}

int Rotor::desplazarAbajo(int indice_entrada){
  return (indice_entrada + obtenerPosicionActual()) % LONGITUD_ALFABETO;
}

int Rotor::mapearAdelante(int indice_entrada){
  return contactos_[indice_entrada];
}

int Rotor::mapearAtras(int contacto){
  for(int i = 0; i < LONGITUD_ALFABETO; i++){
      if(contacto == contactos_[i]){
          return i;
      }
  }
  return contacto;
}

bool Rotor::estaEnMuescaActual(){
  int num_de_muescas = muescas_.size();
  for(int i= 0; i< num_de_muescas; i++){
    if(posicion_actual_ == muescas_[i]){
      return true;
    }
  }
  return false;
}
