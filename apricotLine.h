#include "apricotVector.h"
#include "apricotLine.h"


class ApricotLine {
  public:
    ApricotLine(ApricotVector NaturalVector, double konstant);
    bool ParallelTo(ApricotLine al);
    bool LineEqualTo(ApricotLine al);
    // NOTE: This is kind of hard to do, since technically,
    // There could be One point, infinitely many, or none at all. 
    // So there's got to be a away to return an "infinitely many"
    // vector as well as a "none at all" vector.... 
    // my normal method of "-1" error vector won't work since
    // -1, -1 could be a legitimate intersection..  :c sadlyf.
    ApricotVector ComputeIntersectionTo(ApricotLine al); 
  private:
    ApricotVector natVec; // Natural Vector
    ApricotVector baseVec // Basepoint Vector
    ApricotVector CalculuateBasePoint();
}