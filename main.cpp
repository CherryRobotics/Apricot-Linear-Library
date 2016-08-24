/**
  *   Apricot tests
  *
  *
  *
  **/
#include "apricotMatrix.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
enum Color {
  NONE = 0,
  BLACK, RED, GREEN,
  YELLOW, BLUE, MAGENTA,
  CYAN, WHITE
};

std::string set_color(Color foreground = NONE, Color background = NONE) {
  std::stringstream s;
  s << "\033[";
  if (!foreground && !background) {
    s << "0";
  }
  if (foreground) {
    s << 29 + foreground;
    if(background) s <<";";
  }
  if (background) {
    s<<39 + background;
  }
  s << "m";
  return s.str();
}
void passed(std::string testname, bool passed) {
  if (passed) {
    cout << set_color(GREEN) <<
    "------------------------------------" << endl<<
    testname << "         OK!" << endl<<
    "------------------------------------" << set_color() << endl;
  } else {
    cout << set_color(RED) <<
    "------------------------------------" << endl <<
    testname << "         FAILED!" << endl<<
    "------------------------------------" << set_color() << endl;
  }
}


int main(int argc, char* argv[]) {
  ApricotVector av = ApricotVector("[8.462, 7.893, -8.187]");
  cout << av.CrossProduct(ApricotVector("[6.984, -5.975, 4.778]")) << "\n\n\n";
  av = ApricotVector("[-8.987, -9.838, 5.031]");
  cout << av.GetParallelogramBetween(ApricotVector("[-4.268, -1.861, -8.866]")) << "\n\n\n";
  av = ApricotVector("[1.5, 9.547, 3.691]");
  cout << av.GetTriangleBetween(ApricotVector("[-6.007, 0.124, 5.772]")) << "\n\n\n";




  return 0;
}
