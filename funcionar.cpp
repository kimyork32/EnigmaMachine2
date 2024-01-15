#include "funcionar.h"
#include "Enigma.h"
#include "sstream"
Funcionar::Funcionar(){}

void Funcionar::encriptar(Enigma& enigma, string ruta){
    string oracionInit;
    vector<string> palabras;
    vector<char> letras;
    getline(cin, oracionInit);

    // Convertir a mayusculas
    for (char &c : oracionInit){
        c = toupper(c);
    }
    // actualizar oracion principal
    oracion += oracionInit;

    for (char letra : oracion){
        letras.push_back(letra);
    }
    ofstream texto("ruta");
    if (!texto.is_open()) {
        std::cerr << "Error al abrir el archivo texto.txt" << std::endl;
        return;
    }

    for(char letra : letras){
        if (letra - 'Z' < 0 || LONGITUD_ALFABETO - 1 < letra - 'A') {
            std::cerr << letra << "Los caracteres de entrada deben ser letras en mayúsculas de la A a la Z" << std::endl;
            return;
        }
        enigma.cifrarMensaje(letra);
        texto << letra;
    }
    texto.close();
}

void Funcionar::borrarOracion(){
    oracion = "";
}
string Funcionar::getOracion(){
    return oracion;
}
void Funcionar::MostrarContenidoText(string ruta){
    ifstream texto("ruta");
    if (!texto.is_open()){
        cerr << "texto no encotrado" <<endl;
    }
    string linea;
    while (getline(texto, linea)) {
        cout << linea << endl;
    }
    texto.close();
}
