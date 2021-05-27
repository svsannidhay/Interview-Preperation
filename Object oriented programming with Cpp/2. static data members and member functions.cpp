#include<iostream>

using namespace std;

class Employee{
  private:
    int number;
    static int counter;
  public: 
    void getData(int x) {
      number = x;
      counter++;
    }
    static void putData() {
      cout<<"counter : "<<counter<<"\n";
    }
    

};

// definition of static member 
int Employee :: counter;

// static data member is default initialised to zero as soon as an object is created.

int main() {
  Employee e1,e2,e3;
  Employee ::putData();
  Employee ::putData();
  Employee ::putData();

  e1.getData(1);
  e2.getData(2);
  e3.getData(3);

  Employee :: putData();
  Employee :: putData();
  Employee :: putData();
  
  return 0;
}