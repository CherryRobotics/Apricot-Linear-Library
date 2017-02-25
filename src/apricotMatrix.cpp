#include "apricotMatrix.h"
ApricotMatrix::ApricotMatrix(std::string s) {
    /*
  "[[1, 5, 20], [1,5,30], [1, 20, 30]]"
  would be equivalent to..
  |1   5   20|
  |1   5   30|
  |1   20  30|
  orsomethinglikethis.
  note: The code below was partially ripped from 
        the vector parser. Since it essentially just passes 
        subsections of this string to the ApricotVector
        constructor to take it from there. 
  */
  int bracketcount = 0;
  int commacount = 0;
  for (unsigned int i = 0; i < s.length(); i++) {
    if (s[i] == '[')
      bracketcount++;
    if (s[i] == ']')
      bracketcount--;
    if (s[i] == ',')
      commacount++;
  }
  if (bracketcount != 0 || commacount == 0) {
    // Syntax incorrect. Fill a vector of -1's and return it.
    mat.push_back(ApricotVector("[-1,-1,-1]"));
    std::cout << "Failed to parse correctly.." << std::endl;
  } else {
    // Syntax properlly inputed. 
    // now look for numbers to parse out using the commas as reference.
    bool allfound = false;
    int startpos = 1; //start at 1 to ignore initial "[".
    while (!allfound) {
      // NOTE: We're adding one here, since S will find the index of ], we need to add one more 
      //       To our end pos so that we can pass that final ] character into the Vector parser.
      int endpos = s.find_first_of(']', startpos) + 1;
      // instead of going String to double, we're passing the subsections
      // "[ #, #, #] into the ApricotVector constructor. 
      // NOTE: Since the constructor also requires proper syntax, we're including
      // the starting and terminating brackets "[" "]"
      mat.push_back(ApricotVector(s.substr(startpos, endpos-startpos)));
      
      // now we set the start position to the position of the next starting bracket '['
      startpos = s.find_first_of('[', endpos);
      // if s.find_first_of('[', endpos) returns -1 (failure to find),
      // We can conclude that there are no more '[', thus we have grabbed
      // all the possible equations.
      if (startpos == -1)
        allfound = true;
    }
  }
}
ApricotMatrix::~ApricotMatrix() {

}
// ostream ApricotMatrix::&operator<<(ostream &output, const ApricotMatrix &A) {

// }
void ApricotMatrix::add(ApricotMatrix additive) {

}
void ApricotMatrix::sub(ApricotMatrix sub) {

}
void ApricotMatrix::scale(double scalar) {

}

std::ostream& operator<<(std::ostream &output, const ApricotMatrix &A) {
    // Default accuracy is 3 due to fixed && setprecision
    unsigned int rows = A.mat.size();  
    output << std::fixed << std::setprecision(3);
    for (unsigned int i = 0; i < rows; i++) {
      output << "| ";
      // This is probably unnecessary..
      ApricotVector av = A.mat.at(i);
      std::vector<double> av_vec = av.GetVector();
      for (unsigned int j = 0; j < av_vec.size(); j++) {
        output << av_vec.at(j) << " ";
      }
      output << " |\n";
    }
    return output;
}
