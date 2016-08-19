#include <vector>
#include <iostream>
#include <cstdarg>
#include <string>
#include <cmath>
#include <iomanip>

class ApricotVector {
  public:
    ApricotVector(std::vector<double> v);
    ApricotVector(int n, ...);
    ApricotVector(std::string s);
    ~ApricotVector();
    void add(std::vector<double> v);
    void add(ApricotVector av);
    void sub(std::vector<double> v);
    void sub(ApricotVector av);
    void normalize();
    void scale(double scalar);
    bool ParallelTo(ApricotVector av);
    bool OrthoganalTo(ApricotVector av);
    ApricotVector ProjectedOn(ApricotVector av);
    std::vector<double> GetVector() const;
    friend std::ostream &operator<<(std::ostream &output, const ApricotVector &A) {
      // Default accuracy is 3 due to fixed && setprecision
      std::vector<double> v = A.GetVector();
      for (unsigned int i = 0; i < v.size(); i++) {
        output << "|" << std::fixed << std::setprecision(3) <<  v.at(i) << "|" << std::endl;
      }
      return output;
    }
    double GetMagnitude();
    double DotProduct(ApricotVector av);
    double getAngleBetween(ApricotVector av, bool inDegrees);
  private:
    std::vector<double> vec;
};

/**
 TODO: Overload the operators + - * for easier access to add, sub and scale.
 TODO: make the varargs function safer.
 TODO: overload == .
 ---------------------------------------------------------------------------------
 TODO: Parser so that stdin can grab and create AVectors. !!!!!
 i.e.)
    "[[1, 5, 20], [1,5,30], [1, 20, 30]]"
    would be equivalent to..
    |1   5   20|
    |1   5   30|
    |1   20  30|
    orsomethinglikethis.
   UP1
    The parser has working functionality but needs to be made safer.
    the stod function is pretty dangerous as it is, but the parsing could be
    made better.
    ie)
    "[3.039,]" will crash and die,
    what needs to happen is confirm:
    Initial bracket, number, comma, number, (then only after last number), end bracket.
----------------------------------------------------------------------------------
 TODO: Create function for easy ability to set precision.
 TODO: Use the kahan summation algorithm for low error loss.:
 --------------------------------------------------------------------------------
 function KahanSum(input)
    var sum = 0.0
    var c = 0.0                  // A running compensation for lost low-order bits.
    for i = 1 to input.length do
        var y = input[i] - c         // So far, so good: c is zero.
        var t = sum + y              // Alas, sum is big, y small, so low-order digits of y are lost.
        c = (t - sum) - y        // (t - sum) cancels the high-order part of y; subtracting y recovers negative (low part of y)
        sum = t                  // Algebraically, c should always be zero. Beware overly-aggressive optimizing compilers!
    next i                       // Next time around, the lost low part will be added to y in a fresh attempt.
    return sum
    -------------------------------------------------------------------------------
 TODO: Make a tolerance check function. Something that will help alleviate the ranges.
 you pass in a variable to be checked, and the number it should be, and it will automatically
 check the variable within tolerance range.
 ie)
 function is_Number(varToCheck, number, tolerance=1e-10)
    if (varToCheck > number-tolerance && varToCheck < number+tolerance)
      return true
    return false



---------------------------------------------------------------------------------------
*/
