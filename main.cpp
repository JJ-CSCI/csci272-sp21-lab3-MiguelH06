//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

class Quaternion {

private:
double quart1;
double quart2;
double quart3;
double quart4;

public:
Quaternion(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0)
{
  quart1 = a;
  quart2 = b;
  quart3 = c;
  quart4 = d;
};

bool operator== (const Quaternion &e) const
{
  if((e.quart1 == this-> quart1) && (e.quart2 == this-> quart2) && (e.quart3 == this-> quart3) && (e.quart4 == this-> quart4))
  return true;
  
  else
  return false;
}

Quaternion operator+ (const Quaternion &g) const
{
  Quaternion y;
  
  y.quart1 = quart1 + g.quart1;
  y.quart2 = quart2 + g.quart2;
  y.quart3 = quart3 + g.quart3;
  y.quart4 = quart4 + g.quart4;

  return y;
}

Quaternion operator- (const Quaternion &u) const
{
  Quaternion i;

  i.quart1 = quart1 - u.quart1;
  i.quart2 = quart2 - u.quart2;
  i.quart3 = quart3 - u.quart3;
  i.quart4 = quart4 - u.quart4;
  
  return i;
}

Quaternion operator* (double l)const
{
  Quaternion mult(quart1*l, quart2*l, quart3*l, quart4*l);
  
  return mult;
}
friend Quaternion operator* (double l, const Quaternion &s);
};

Quaternion operator* (double l, const Quaternion &s)
{
  Quaternion mult(l*s.quart1, l*s.quart2, l*s.quart3, l*s.quart4);
  
  return mult;
}

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "q1" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        REQUIRE( q == p );
    }
    SECTION( "q2" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q + p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{0.0, 0.0, 0.0, 0.0};
        REQUIRE( (q - p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q * 2.0) == r );
    }
}
//------------------------------  