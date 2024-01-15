#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Component {
private:
  vector<int> par_entrada1_;
  vector<int> par_entrada2_;

public:
  Component(string ruta);
  int mapear(int entrada);
};

#endif