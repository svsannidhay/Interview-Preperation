#include<iostream>

using namespace std;

class Item{
  private:
    int a;
    float b;
  public: 
    void getData(int num,int val);
    void putData();
};

// Member functions declared out of the class definition 

void Item :: getData(int num,int val) {
  a = num;
  b = val;
}

void Item :: putData() {
  cout<<"a : "<<a<<"\n";
  cout<<"b : "<<b<<"\n";
}

int main() {
  Item i;
  i.getData(2,3);
  i.putData();
  return 0;
}