#include<iostream>

using namespace std;

class Complex {
  int a,b;
  public:
    Complex(int,int);
    void printData() {
      cout<<a<<" + i"<<b<<"\n";
    }
};

Complex :: Complex(int x,int y) {
  cout<<"Parameterised constructor\n";
  a = x;
  b = y;
}

int main() {
  Complex c1(1,3); // Implicit call
  Complex c2 = Complex(4,5); // Explicit call
  c1.printData();
  c2.printData();
  return 0;
}