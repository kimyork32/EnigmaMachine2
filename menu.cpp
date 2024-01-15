#include "menu.h"
#include "funcionar.h"
#include <string>
#include <sstream>
void Menu::menu(){
  int opc;
  bool configuracionesIniciadas=false;
  while(opc!=7){
      cout << "Maquina Enigma\n"
        << "(0) Iniciar\n"
        << "(1) Encriptar\n"
        << "(2) Desencriptar\n"
        << "(3) Mostrar texto\n"
        << "(4) Output de maquina emisora\n"
        << "(5) Output de maquina receptora (desencriptado)\n"
        << "(6) Cambiar rotores\n"
        << "(7) Salir\n";
      cin >> opc;

      switch(opc){
        case 0:
            if(!configuracionesIniciadas){
                string arch;
                vector<string> configuraciones;
                cout << "Ingrese configuraciones:\n"
                    << "usar: <enigma> <plugboard-arhivo> <reflector-archivo> <rotorRotor-archivo> <posicionRotor-archivo>\n";
                getline(cin, arch);
                istringstream stream(arch);
                string conf;
                while(stream >> conf){
                    configuraciones.push_back(conf);
                }
                configuracionesIniciadas = false;

                maquinaEncriptar = Enigma(configuraciones.size(), configuraciones);
                maquinaDesencriptar = Enigma(configuraciones.size(), configuraciones);
                break;
            }
            
            cout << "Configuraciones ya insertadas" << endl;
            for(string configuracion : maquinaEncriptar.getConfiguraciones()){
              cout << configuracion << " ";
            }
            cout << endl;
            break;
        case 1:
          cout << "Encriptar:\n";
          work.encriptar(maquinaEncriptar, "texto_encriptado.txt");
          break;
        case 2:
          cout << "Desencriptar";
          work.encriptar(maquinaDesencriptar, "texto_desencriptado.txt");
          break;
        case 3:
          cout << "Mostrar Texto\n";
          cout << work.getOracion() << endl;
          break;
        case 4:
          cout << "Output de maquina emisora\n";
          work.MostrarContenidoText("texto_encriptado.txt");
          break;
        case 5:
          cout << "Output de maquina receptora (desencriptado)\n";
          work.MostrarContenidoText("texto_desencriptado.txt");
          break;
        case 6:
          cout << "Cambiar Rotores\n";
          //INSERTAR LOGICA
          break;
        case 7:
          cout << "saliendo";
          break;
      }
  }
}

