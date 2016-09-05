#include "apricotLine.h"
ApricotLine::ApricotLine() {
  
}

ApricotLine::ApricotLine(ApricotVector NaturalVector, double konstant) {
  natVec = NaturalVector;
  konstant_ = konstant;
}

bool ApricotLine::ParallelTo(ApricotLine al) {
  return true;
}

bool ApricotLine::LineEqualTo(ApricotLine al) {
  return true;
}

ApricotVector ApricotLine::ComputeIntersectionTo(ApricotLine al) {
  return ApricotVector("[-1, -1]");
}

ApricotVector ApricotLine::GetNaturalVector() const {
  return natVec;
}

double ApricotLine::GetEquationConstant() const {
  return konstant_;
}

ApricotVector ApricotLine::CalculuateBasePoint() {
  return ApricotVector("[-1, -1]");
}

unsigned int ApricotLine::GetFirstNonZeroIndex(ApricotLine al) {
  unsigned int i = 0;
  double currentcoef = 0;
  ApricotVector av = al.GetNaturalVector();
  std::vector<double> nv = av.GetVector();
  do {
    currentcoef = nv.at(i);
    if (currentcoef == 0)
      i++;
  } while (i != nv.size() || currentcoef == 0);
  return i;
}

std::ostream& operator<<(std::ostream &output, const ApricotLine &A) {
  // Default accuracy is 3 due to fixed && setprecision
  ApricotVector naturalVec = A.GetNaturalVector();
  std::vector<double> nv = naturalVec.GetVector();
  output << std::fixed << std::setprecision(3);
  for (unsigned int i = 0; i < nv.size(); i++) {
    output << nv.at(i) << " X" << i << "  +  ";
  }
  output << " = " << A.GetEquationConstant() << "\n\n";
  return output;
}