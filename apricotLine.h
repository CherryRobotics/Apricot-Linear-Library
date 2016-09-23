#include "apricotVector.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>


#ifndef APRICOTLINE_H
#define APRICOTLINE_H


class ApricotLine {
  public:
    ApricotLine();
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
    friend std::ostream &operator<<(std::ostream &, const ApricotLine &);
    ApricotVector GetNaturalVector() const;
    ApricotVector GetBasePointVector() const;
    double GetEquationConstant() const;
    static unsigned int GetFirstNonZeroIndex(ApricotLine al);
  private:
    ApricotVector natVec; // Natural Vector
    ApricotVector baseVec; // Basepoint Vector
    double konstant_;
    ApricotVector CalculateBasePoint();
};

#endif
