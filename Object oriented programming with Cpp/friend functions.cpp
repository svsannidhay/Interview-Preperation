#include<iostream>

using namespace std;

class Employee {
    int eid;
    int salary;
  public:
    void getData(int id,int sal) {  
      eid = id;
      salary = sal;
    }
    friend void putData(Employee);
};

void putData(Employee e) {
  cout<<"Employee id : "<<e.eid<<"\n Salary : "<<e.salary<<"\n";
  return;
}
int main() {
  Employee e;
  e.getData(4,1231);
  putData(e);
  return 0;
}