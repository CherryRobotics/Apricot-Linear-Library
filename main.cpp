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
  ApricotVector av = ApricotVector("[3.009, -6.172, 3.692, -2.51]");
  ApricotVector projection = av.ProjectedOn(ApricotVector("[6.404, -9.144, 2.759, 8.718]"));
  cout << "\n\n\n" << projection;
  av.sub(projection);
  cout << "\n\n\n" << av;





  return 0;
}
