#include <vector>
#include <iostream>
#include "apricotVector.h"

class ApricotMatrix {
public:
  ApricotMatrix();
  ~ApricotMatrix();
  friend std::ostream &operator<<(std::ostream &output, const ApricotMatrix &A);
  void add(ApricotMatrix additive);
  void sub(ApricotMatrix sub);
  void scale(double scalar);
private:
  // std::vector< > mat;
  int rows;
  int cols;
};
