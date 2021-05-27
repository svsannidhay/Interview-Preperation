#include<iostream>

using namespace std;

class Complex{
  int a,b;
  public:
    Complex();
    Complex(int,int);
    Complex(int);
    Complex(Complex &);
    void printData() {
      cout<<a <<" + i"<<b<<"\n";
    }
};

Complex :: Complex() {
  cout<<"Constructor 1 called \n";
  a = 0;
  b = 0;
}

Complex:: Complex(int x,int y) {
  cout<<"Constructor 2 called \n";
  a = x;
  b = y;
}

Complex::Complex(int x){
  cout << "Constructor 3 called \n";
  a = x;
}

Complex :: Complex(Complex & obj) {
  cout<<"Copy  constructor called \n";
  a = obj.a;
  b = obj.b;
}

int main() {
  Complex c1;
  c1.printData();
  Complex c2(10);
  c2.printData();
  Complex c3(1,2);
  c3.printData();
  Complex c4(c3);
  c4.printData();
  return 0;
}