#include <vector>
#include <iostream>
#include "apricotVector.h"
#include <string>

#ifndef APRICOTMATRIX_H
#define APRICOTMATRIX_H

class ApricotMatrix {
public:
  ApricotMatrix(std::string s);
  ~ApricotMatrix();
  friend std::ostream &operator<<(std::ostream &, const ApricotMatrix &);
  void add(ApricotMatrix additive);
  void sub(ApricotMatrix sub);
  void scale(double scalar);
private:
   std::vector<ApricotVector> mat;
};
#endif