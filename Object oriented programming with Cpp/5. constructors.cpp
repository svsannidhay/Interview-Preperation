#include<iostream>

using namespace std;

class Complex{
  int a,b;
  public:
    Complex();      // Constructor declaration
    void printData() {
      cout<<a<<" + i"<<b<<"\n";
    }
};

Complex :: Complex() {
  cout<<"Constructor called \n";
  a = 0;
  b = 0;
}

int main () {
  Complex c;
  c.printData();
  return 0;
}