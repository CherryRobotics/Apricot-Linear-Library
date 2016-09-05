#include "apricotVector.h"

using namespace std;

ApricotVector::ApricotVector(std::vector<double> v) {
  vec = v;
}

ApricotVector::ApricotVector(int n, ...) {
  // TODO: Make this function more safe. currently very dangerous :c
  va_list arguments;
  va_start(arguments, n);
  for (int i = 0; i < n; i++) {
    vec.push_back(va_arg(arguments, double));
  }
  va_end(arguments);
}
ApricotVector::ApricotVector(std::string s) {
  /*
  "[[1, 5, 20], [1,5,30], [1, 20, 30]]"
  would be equivalent to..
  |1   5   20|
  |1   5   30|
  |1   20  30|
  orsomethinglikethis.
  note: the above example is just for
        ApricotMatrix and how I intend for it
        to end up being. the below code is
        just for ApricotVector. and input
        like "[0, 2, 4]"
        |0|
        |2|
        |4|
  */
  // confirm brackets are correct.
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
    vec.push_back(-1.0);
    std::cout << "Failed to parse correctly.." << std::endl;
  } else {
  // now look for numbers to parse out using the commas as reference.
    bool allfound = false;
    int startpos = 1; //start at 1 to ignore initial "[".
    while (!allfound) {
      int endpos = s.find_first_of(',', startpos);
      if (endpos == -1) {
        allfound = true;
        // std::cout << s.substr(startpos, s.length()-1-startpos) << std::endl;
        vec.push_back(std::stod(s.substr(startpos, s.length()-1-startpos)));
      } else {
        vec.push_back(std::stod(s.substr(startpos, endpos-startpos)));
        // std::cout << s.substr(startpos, endpos-startpos) << std::endl;
      }
      // std::cout << "Startpos: " << startpos << "\nEndpos: " << endpos << std::endl;
      startpos = endpos+1;
    }
  }
}
ApricotVector::~ApricotVector() {
  // Nothing special for destructor.
}
void ApricotVector::add(std::vector<double> v) {
  if (v.size() == vec.size()) {
    for (unsigned int i = 0; i < v.size(); i++) {
      vec.at(i) += v.at(i);
    }
  } else {
    std::cout << "Vector size mismatch!";
  }
}
void ApricotVector::add(ApricotVector av) {
  std::vector<double> v = av.GetVector();
  if (v.size() == vec.size()) {
    for (unsigned int i = 0; i < v.size(); i++) {
      vec.at(i) += v.at(i);
    }
  } else {
    std::cout << "Vector size mismatch!";
  }
}
void ApricotVector::sub(std::vector<double> v) {
  if (v.size() == vec.size()) {
    for (unsigned int i = 0; i < v.size(); i++) {
      vec.at(i) -= v.at(i);
    }
  } else {
    std::cout << "Vector size mismatch!";
  }
}

void ApricotVector::sub(ApricotVector av) {
  std::vector<double> v = av.GetVector();
  if (v.size() == vec.size()) {
    for (unsigned int i = 0; i < v.size(); i++) {
      vec.at(i) -= v.at(i);
    }
  } else {
    std::cout << "Vector size mismatch!";
  }
}
void ApricotVector::normalize() {
  double normal = this->GetMagnitude();
  if (normal > 0) {
    normal = 1/normal;
    this->scale(normal);
  } else {
    std::cout << "magnitude of 0, unable to normalize." << std::endl;
  }
}
void ApricotVector::scale(double scalar) {
  for(unsigned int i = 0; i < vec.size(); i++) {
    vec.at(i)*=scalar;
  }
}

bool ApricotVector::ParallelTo(ApricotVector av) {
  double ang = this->getAngleBetween(av, true);
  if ((ang < 0.000000009 && ang > -0.000000009) || (ang < 180.000009 && ang > 179.0000009))
    return true;
  return false;
}
bool ApricotVector::OrthoganalTo(ApricotVector av) {
  double ang = this->DotProduct(av);
  if (ang < 0.000000009 && ang > -0.000000009)
    return true;
  return false;
}
ApricotVector ApricotVector::ProjectedOn(ApricotVector av) {
  // V|| = (V DOT Bnorm)Bnorm
  av.normalize();
  ApricotVector aq = *this;
  av.scale(aq.DotProduct(av));
  return av;
}
std::vector<double> ApricotVector::GetVector() const {
  return vec;
}
double ApricotVector::GetMagnitude() {
  double mag = 0.0;
  for (unsigned int i = 0; i < vec.size(); i++) {
    mag += pow(vec.at(i), 2);
  }
  mag = sqrt(mag);
  return mag;
}
double ApricotVector::DotProduct(ApricotVector av) {
  double dot = 0;
  std::vector<double> v = av.GetVector();
  if (v.size() == vec.size()) {
    for (unsigned int i = 0; i < vec.size(); i++) {
      dot += v.at(i) * vec.at(i);
    }
  } else {
    std::cout << "Vector size mismatch!";
  }
  return dot;
}
double ApricotVector::getAngleBetween(ApricotVector av, bool inDegrees) {
  std::vector<double> v = av.GetVector();
  if (v.size() == vec.size()) {
    double dot = this->DotProduct(av);
    double magav = av.GetMagnitude();
    double mag = this->GetMagnitude();
    if (mag > 0 && magav > 0) {
      double theta = acos(dot/(magav*mag));
      if (inDegrees)
        return theta * 180/3.1415926535897;
      return theta;
    } else {
      if (dot == 0) {
        return 0;
      }
      return -1;
    }
  } else {
    std::cout << "Vector size mismatch!";
    return -1;
  }
}

ApricotVector ApricotVector::CrossProduct(ApricotVector av) {
  std::vector<double> v = av.GetVector();
  if (v.size() == vec.size() && (v.size() == 3 || v.size() == 2)) {
    std::vector<double> cross;
    if (v.size() == 3) {
      cross.push_back(vec.at(1)*v.at(2) - v.at(1)*vec.at(2));
      cross.push_back(-1*(vec.at(0)*v.at(2) - v.at(0)*vec.at(2)));
      cross.push_back(vec.at(0)*v.at(1) - v.at(0)*vec.at(1));
    } else if (v.size() == 2) {
      cross.push_back(vec.at(1)*0 - v.at(1)*0);
      cross.push_back(-1*(vec.at(0)*0 - v.at(0)*0));
      cross.push_back(vec.at(0)*v.at(1) - v.at(0)*vec.at(1));
    }
    return ApricotVector(cross);
  } else {
    std::cout << "Invalid vector sizes, unable to grab cross product. Check your dimensions!";
    return ApricotVector("[-1, -1, -1]");
  }
}
double ApricotVector::GetParallelogramBetween(ApricotVector av) {
  ApricotVector cross = this->CrossProduct(av);
  std::vector<double> v = cross.GetVector();
  double area = 0;
  for (unsigned int i = 0; i < v.size(); i++) {
    area += pow(v.at(i), 2);
  }
  return sqrt(area);
}
double ApricotVector::GetTriangleBetween(ApricotVector av) {
  return this->GetParallelogramBetween(av)/2;
}

ostream& operator<<(std::ostream &output, const ApricotVector &A) {
    // Default accuracy is 3 due to fixed && setprecision
    std::vector<double> v = A.GetVector();
    for (unsigned int i = 0; i < v.size(); i++) {
        output << "|" << std::fixed << std::setprecision(3) <<  v.at(i) << "|" << std::endl;
    }
    return output;
}
