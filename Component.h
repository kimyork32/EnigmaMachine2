#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include <vector>

class Component {
private:
  std::vector<int> par_entrada1_;
  std::vector<int> par_entrada2_;

public:
  Component(const char* ruta);
  int mapear(int entrada);
};

#endif