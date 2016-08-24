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
    ApricotVector CrossProduct(ApricotVector av);
    double GetParallelogramBetween(ApricotVector av);
    double GetTriangleBetween(ApricotVector av);
  private:
    std::vector<double> vec;
    // bool tolEquals(double value, double checknum, double tol=0.0000000001)
};
