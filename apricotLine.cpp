#include "apricotLine.h"
ApricotLine::ApricotLine() {
  
}

ApricotLine::ApricotLine(ApricotVector NaturalVector, double konstant) {
  natVec = NaturalVector;
  konstant_ = konstant;
  baseVec = this->CalculateBasePoint();
}

bool ApricotLine::ParallelTo(ApricotLine al) {
  // 2 lines are parallel if their normal vectors are parallel (factors of each other.)
  if (this->GetNaturalVector().ParallelTo(al.GetNaturalVector()))
    return true;
  return false;
}

bool ApricotLine::LineEqualTo(ApricotLine al) {
  // They're not parallel, no reason to check equality if not parallel.
  if (!this->ParallelTo(al))
    return false;
  // Grab the vector between the two points by subtracting them.
//   ApricotVector 
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

ApricotVector ApricotLine::GetBasePointVector() const {
  return baseVec;
}

ApricotVector ApricotLine::CalculateBasePoint() {
  std::vector<double> v;
  std::vector<double> nv = natVec.GetVector();
  // If B!=0
  if (nv.at(1) != 0) {
    v.push_back(0);
    v.push_back(konstant_/nv.at(1));
  }
  // if A!= 0
  else if (nv.at(0) != 0) {
    v.push_back(konstant_/nv.at(0));
    v.push_back(0);
  } else {
    v.push_back(-999);
    v.push_back(-999);
  }
  return ApricotVector(v);
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