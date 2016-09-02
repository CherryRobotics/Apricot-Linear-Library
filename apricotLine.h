#include "apricotVector.h"
#include "apricotLine.h"


class ApricotLine {
  public:
    ApricotLine(ApricotVector av);
    ApricotLine(std::vector<double> v);
    bool ParallelTo(ApricotLine al);
    bool ParallelTo(std::vector<double> v;)
  private:
    ApricotVector natVec; // Natural Vector
}