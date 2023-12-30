#include "menu.h"
#include "funcionar.h"
Menu::Menu(Enigma& enigmaEncriptacion, Enigma& enigmaDesencriptacion, Funcionar& funcionar, 
  std::string texto, std::string textoEncriptado, std::string textoDesencriptado)
  :enigmaEncriptacion(enigmaEncriptacion), enigmaDesencriptacion(enigmaDesencriptacion), 
  work(work), texto(texto), textoEncriptado(textoEncriptado), textoDesencriptado(textoDesencriptado){}

void Menu::menu(){
  int opc;
  while(opc!=3){
      std::cout << "Maquina Enigma\n"
          << "(1) Encriptar\n"
          << "(2) Desencriptar\n"
          << "(3) Mostrar texto\n"
          << "(4) Mostrar texto encriptado\n"
          << "(5) Borrar texto\n"
          << "(6) Cambiar rotores\n";
      std::cin >> opc;
      switch(opc){
          case 1:
              std::cout << "Encriptar:\n";
              work.encriptar(enigmaEncriptacion, texto, textoEncriptado);
              break;
          case 2:
              std::cout << "Desencriptar";
              work.desencriptar(enigmaDesencriptacion);
              break;
          case 3:
              std::cout << "saliendo";
      }
  }
}

