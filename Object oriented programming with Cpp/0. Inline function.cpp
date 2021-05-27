#include<iostream>

using namespace std;

inline float mul(float x, float y) {
  return (x * y);
}

inline double div(double a,double b) {
  return  a / b;
}

int main() {
  cout<<mul(1.1,1.1)<<"\n";
  cout<<div(5.0,2.0);
  return 0;
}