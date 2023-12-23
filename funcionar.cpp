#include "funcionar.h"
#include "Enigma.h"
Funcionar::Funcionar(int agrc_, char** agrv_){
    agrc = agrc_;
    agrv = agrv_;
}

void Funcionar::encriptar(){
    
}

void Menu::encriptar(Enigma& enigmaEncriptacion){
    Enigma enigmaEncriptacion = new Enigma(argc, argv);
    char letra;
    while(!cin.eof()){
        cin >> letra;
        if(cin.fail()){
          break;
        }
        if(letra - 'A' < 0 || LONGITUD_ALFABETO -1 < letra - 'A'){
          cerr << letra << "Los caracteres de entrada deben ser letras en mayusculas de la A a la Z" << endl;
          delete enigmaEncriptacion;
          delete enigmaDesencriptacion;
          return CARACTER_DE_ENTRADA_INVALIDO;
        }
        enigmaEncriptacion->cifrarMensaje(letra);
        cout << letra;
    }
    delete enigmaEncriptacion;
    return SIN_ERROR;
}