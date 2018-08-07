/**
  *   Apricot tests
  *
  *
  *
  **/
#include "apricotMatrix.h"
#include "apricotLine.h"
#include "apricotVector.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
  ApricotLine al = ApricotLine(ApricotVector("[2, 3]"), 6);
  cout << al << "\n\n";
  cout << al.GetBasePointVector();

  ApricotMatrix am = ApricotMatrix("[[1, 0, -2], [-1, -4, 5], [1, 1, 1]]");
  cout << am << "\n\n\n";

  ApricotVector v0 = ApricotVector("[1,2,3]");
  ApricotVector v1 = ApricotVector("[1,2,3]");
  ApricotVector v2 = ApricotVector("[9,8,2]");
  ApricotVector v3 = ApricotVector("[1,2,3,7]");

  cout << "Comparing equality, should return TRUE" << endl;
  if (v0 == v1) {
    cout << "TRUE" << endl;
  }

  cout << "Comparing equality, no return" << endl;
  if (v0 == v2) {
    cout << "FALSE" << endl;
  }

  cout << "Comparing equality with vectors of different sizes, should return size mismatch message" << endl;
  if (v0 == v3) {
    cout << "FALSE" << endl;
  }

  cout << "testing + overload" << endl;
  ApricotVector v4 = v1 + v2;
  cout << v4 << endl;

  return 0;
}
