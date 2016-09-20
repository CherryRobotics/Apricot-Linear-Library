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

    void normalize();
    void scale(double scalar);

    bool ParallelTo(ApricotVector av);
    bool OrthoganalTo(ApricotVector av);
    ApricotVector ProjectedOn(ApricotVector av);

    std::vector<double> GetVector() const;
    friend std::ostream &operator<<(std::ostream &, const ApricotVector &);
    friend bool operator==(const ApricotVector&, const ApricotVector&);
    friend ApricotVector operator+(ApricotVector&, const ApricotVector&);
    friend ApricotVector operator-(ApricotVector&, const ApricotVector&);
    friend ApricotVector operator*(ApricotVector&, const ApricotVector&);

    double GetMagnitude();
    double DotProduct(ApricotVector av);
    double getAngleBetween(ApricotVector av, bool inDegrees);
    ApricotVector CrossProduct(ApricotVector av);
    double GetParallelogramBetween(ApricotVector av);
    double GetTriangleBetween(ApricotVector av);
    double at(int);
    double size();
  private:
    std::vector<double> vec;
    // bool tolEquals(double value, double checknum, double tol=0.0000000001)
};
