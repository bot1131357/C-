#include <iostream>
#include <cmath>

class Complex {

  double real;
  double imag;

public:
  Complex (double r, double i):
  real(r),imag(i)
  {

  }

  friend Complex operator+(const Complex &c1, const Complex &c2)
  {
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
  }
  Complex & operator++()//pre increment
  {
  	++real;
    return *this;
  }

  Complex & operator++(int)//post increment
  {
  	real++;
    return *this;
  }

  Complex & operator--()
  {
  	--real;
    return *this;
  }

  Complex & operator--(int)
  {
  	real--;
    return *this;
  }

  friend bool operator==(const Complex &c1, const Complex &c2)
  {
    return (c1.real==c2.real && c1.imag==c2.imag);  	
  }
  friend bool operator!=(const Complex &c1, const Complex &c2)
  {
    return !(c1==c2);  	
  }

  friend std::ostream& operator<<(std::ostream& os, const Complex& c)
  {
        os << "[" << c.real << "," << c.imag << "]";
        return os;
  }

  double mag()
  {
    return std::sqrt(real*real + imag*imag);
  }
  double ang()
  {
    return std::atan(imag/real);
  }
};

const double pi = 3.1415926535897;
int main (int argc, char** argv)
{

  Complex a(0,1);
  Complex b(std::sqrt(3),0);
  // Complex c(1,1);
  Complex c = a+b;

  std::cout<<"a = " << a << "\n";
  std::cout<<"b = " << b << "\n";
  std::cout<<"c = " << c << "\n";
  std::cout<<"|c| = " << c.mag() << "\n";
  std::cout<<"angle c = " << c.ang() << "rad or " << c.ang()*180/pi << "deg" << "\n";

  std::cout<<"a==b : " << (a==b) << "\n";
  std::cout<<"a!=b : " << (a!=b) << "\n";

  ++c;
  std::cout<<"++c = " << c << "\n";
  c++;
  std::cout<<"c++ = " << c << "\n";
  

  return 0;
}