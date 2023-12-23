#include "Enigma.h"
#include "Component.h"
#include "Rotor.h"
#include "alfabeto.h"
#include "errores.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Enigma::Enigma(int argc, char** argv){
  vector<int> contactos_tablero_enchufes;
  verificarConfiguracionTableroEnchufes(argv[1], contactos_tablero_enchufes);
  vector<int> contactos_reflector;
  verificarConfiguracionReflector(argv[2], contactos_reflector);
  vector<vector<int>> contactos_rotores_array;

  vector<int> contactos_rotores;
  for(int i = 3; i < argc-1; i++){
    verificarConfiguracionRotor(argv[i], contactos_rotores);
    contactos_rotores_array.push_back(contactos_rotores);
    contactos_rotores.clear();
  }
  // 3 argc means no rotor is provided
  if(argc == 3){
    num_de_rotores_ = 0;
  }
  else{
    num_de_rotores_ = argc-4;
  }
  verificarConfiguracionPosicionRotor(argv[argc-1]);

  // All the checking is done at this point, so instantiate each component

  tablero_enchufes_ = new Component(argv[1]);
  reflector_ = new Component(argv[2]);
  for(int i = 0; i < num_de_rotores_; i++){
    Rotor rotor(argv[3+i], posiciones_rotores_[i]);
    rotores_.push_back(rotor);
  }
}

Enigma::~Enigma(){
    if(tablero_enchufes_){
        delete tablero_enchufes_;
    }
    if(reflector_){
        delete reflector_;
    }
}

bool Enigma::esEntradaTableroEnchufesValida(const char* ruta, fstream& flujo_entrada, \
  int& numero_indice){
  flujo_entrada >> ws;
  int fin_de_archivo = flujo_entrada.peek();
  if(fin_de_archivo == EOF){
    return false;
  }
  flujo_entrada >> numero_indice;
  if(flujo_entrada.fail()){
    cerr << "Non-numeric character in plugboard file " << ruta << endl;
    flujo_entrada.close();
    throw(CARACTER_NO_NUMERICO);
  }
  if(!esRangoCorrectoNumero(numero_indice)){
    cerr << "The file " << ruta << \
    " contains a number that is not between 0 and 25" << endl;
    flujo_entrada.close();
    throw(INDICE_INVALIDO);
  }
  return true;
}

void Enigma::verificarConfiguracionTableroEnchufes(const char* ruta, vector<int>& contactos){
  int numero_indice_par, numero_indice_impar;
  int contador = 0;
  fstream flujo_entrada;
  flujo_entrada.open(ruta);
  if(flujo_entrada.fail()){
    cerr << "Error opening or reading the configuration file " << ruta << endl;
    flujo_entrada.close();
    throw(ERROR_ABRIR_ARCHIVO_DE_CONFIGURACION);
  }

  while(!flujo_entrada.eof()){
    if(!esEntradaTableroEnchufesValida(ruta, flujo_entrada, numero_indice_par)){
      break;
    }
    if(!esEntradaTableroEnchufesValida(ruta, flujo_entrada, numero_indice_impar)){
      cerr << "Incorrect number of parameters in plugboard file " \
      << ruta << endl;
      flujo_entrada.close();
      throw(NUMERO_INCORRECTO_DE_PARAMETROS_TABLERO_ENCHUFES);
    }
    contactos.push_back(numero_indice_par);
    if(verificarAparecioAntes(contactos, numero_indice_par, contador) != -1){
      flujo_entrada.close();
      throw(CONFIGURACION_IMPOSIBLE_TABLERO_ENCHUFES);
    }
    contador++;

    contactos.push_back(numero_indice_impar);
    if(verificarAparecioAntes(contactos, numero_indice_impar, contador) != -1){
      flujo_entrada.close();
      throw(CONFIGURACION_IMPOSIBLE_TABLERO_ENCHUFES);
    }
    contador++;
  }
  flujo_entrada.close();
}

void Enigma::verificarConfiguracionReflector(const char* ruta, vector<int>& contactos){
  int numero;
  int contador = 0;
  fstream flujo_entrada;
  flujo_entrada.open(ruta);
  if(flujo_entrada.fail()){
    cerr << "Error al abrir o leer la configuración del archivo " << ruta << endl;
    flujo_entrada.close();
    throw(ERROR_ABRIR_ARCHIVO_DE_CONFIGURACION);
  }

  while(!flujo_entrada.eof()){
    flujo_entrada >> ws;
    int fin_de_archivo = flujo_entrada.peek();
    if(fin_de_archivo == EOF){
      break;
    }
    flujo_entrada >> numero;
    if(flujo_entrada.fail()){
      cerr << "Non-numeric character in reflector file" << ruta << endl;
      flujo_entrada.close();
      throw(CARACTER_NO_NUMERICO);
    }
    if(!esRangoCorrectoNumero(numero)){
      cerr << "The file " << ruta << \
      " contains a number that is not between 0 and 25" << endl;
      flujo_entrada.close();
      throw(INDICE_INVALIDO);
    }
    contactos.push_back(numero);
    if(contador < LONGITUD_ALFABETO && \
      verificarAparecioAntes(contactos, numero, contador) != -1){
      flujo_entrada.close();
      throw(MAPEO_REFLECTOR_INVALIDO);
    }
    contador++;
  }
  flujo_entrada.close();

  if(contador%2!=0){
      cerr << "Incorrect (odd) number of parameters in reflector file " \
      << ruta << endl;
      throw(NUMERO_INCORRECTO_DE_PARAMETROS_REFLECTOR);
  }
  if(contador != LONGITUD_ALFABETO){
    cerr << "Insufficient number of mappings in reflector file: " \
    << ruta << endl;
    throw(NUMERO_INCORRECTO_DE_PARAMETROS_REFLECTOR);
  }
}

void Enigma::verificarConfiguracionRotor(const char* ruta, vector<int>& contactos){
  int numero;
  int contador = 0;
  fstream flujo_entrada;
  flujo_entrada.open(ruta);
  if(flujo_entrada.fail()){
    cerr << "Error opening or reading the configuration file " << ruta << endl;
    flujo_entrada.close();
    throw(ERROR_ABRIR_ARCHIVO_DE_CONFIGURACION);
  }

  while(!flujo_entrada.eof()){
    flujo_entrada >> ws;
    int fin_de_archivo = flujo_entrada.peek();
    if(fin_de_archivo == EOF){
      break;
    }
    flujo_entrada >> numero;

    if(flujo_entrada.fail()){
      cerr << "The file " << ruta \
      << " contains a number that is not between 0 and 25" << endl;
      flujo_entrada.close();
      throw(INDICE_INVALIDO);
    }
    contactos.push_back(numero);

    if(contador < LONGITUD_ALFABETO-1 && \
      verificarAparecioAntes(contactos, numero, contador) != -1){
      flujo_entrada.close();
      throw(MAPEO_ROTOR_INVALIDO);
    }
    contador++;
  }
  flujo_entrada.close();

  if(contador < LONGITUD_ALFABETO){
    cerr << "Not all inputs mapped in rotor file: " << ruta << endl;
    throw(MAPEO_ROTOR_INVALIDO);
  }
}

void Enigma::verificarConfiguracionPosicionRotor(const char* ruta){
  int num;
  int contador = 0;
  fstream flujo_entrada;
  flujo_entrada.open(ruta);
  if(flujo_entrada.fail()){
    cerr << "Error opening or reading the configuration file " << ruta << endl;
    flujo_entrada.close();
    throw(ERROR_ABRIR_ARCHIVO_DE_CONFIGURACION);
  }
  while(!flujo_entrada.eof()){
    flujo_entrada >> ws;
    int eof = flujo_entrada.peek();
    if(eof == EOF){
      break;
    }
    flujo_entrada >> num;
    if(flujo_entrada.fail()){
      cerr << "Non-numeric character in rotor positions file " << ruta  << endl;
      flujo_entrada.close();
      throw(CARACTER_NO_NUMERICO);
    }

    if(!esRangoCorrectoNumero(num)){
      cerr << "The file " << ruta \
      << " contains a number that is not between 0 and 25" << endl;
      flujo_entrada.close();
      throw(INDICE_INVALIDO);
    }
    contador++;
    posiciones_rotores_.push_back(num);
  }

  int diferencia = contador - num_de_rotores_;
  if(diferencia < 0){
    cerr << "No starting position for rotor " << num_de_rotores_ + diferencia \
    << " in rotor position file: " << ruta << endl;
    flujo_entrada.close();
    throw(NO_POSICION_INICIAL_ROTOR);
  }
  flujo_entrada.close();
}

bool Enigma::esRangoCorrectoNumero(int num){
  return (num < LONGITUD_ALFABETO && num >= 0);
}

int Enigma::verificarAparecioAntes(vector<int> contactos, int num, int posicion){
  for(int i = 0; i < posicion; i++ ){
    if(contactos[i] == num){
      cerr << "Invalid mapping of input " << posicion << " to output " << num << " (output " << num << " is already mapped to from input " << i << ")" << endl;
      return i;
    }
  }
  return -1;
}

void Enigma::cifrarMensaje(char& letra){
  int indice_actual = letra - 'A';
  indice_actual = tablero_enchufes_->mapear(indice_actual);

  if(num_de_rotores_ > 0){
    rotores_[num_de_rotores_-1].rotar();
  }

  if(num_de_rotores_ > 0){
    for(int i = num_de_rotores_ ; i > 0; i--){
      indice_actual = rotores_[i-1].desplazarAbajo(indice_actual);
      indice_actual = rotores_[i-1].mapearAdelante(indice_actual);
      indice_actual = rotores_[i-1].desplazarArriba(indice_actual);
      if(rotores_[i-1].estaEnMuescaActual() && rotores_[i-1].obtenerPosicionAnterior() != rotores_[i-1].obtenerPosicionActual()){
        if(i-1 > 0){
          rotores_[i-2].rotar();
        }
      }
    }
  }
  indice_actual = reflector_->mapear(indice_actual);
  if(num_de_rotores_ > 0){
    for(int i = 0; i < num_de_rotores_; i++){
      indice_actual = rotores_[i].desplazarAbajo(indice_actual);
      indice_actual = rotores_[i].mapearAtras(indice_actual);
      indice_actual = rotores_[i].desplazarArriba(indice_actual);
    }
  }
  indice_actual = tablero_enchufes_->mapear(indice_actual);
  letra = indice_actual + 'A';
}
