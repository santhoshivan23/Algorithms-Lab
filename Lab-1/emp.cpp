#include<iostream>
using namespace std;

class Employee {
  string name;
  int age;
  string dep;
  int sal;
  public :
  Employee() {}
  Employee(string name,int age,string dep,int sal) {
    this -> name = name;
    this -> age = age;
    this -> dep = dep;
    this -> sal = sal;
  }

  void update(int bonus) {
    this -> sal += bonus;
  }

  string getName() {
    return this->name;
  }

  int getSal() {
    return this->sal;
  }

  void sort(Employee emp[]) {

      for(int i=1;i<5;i++) {
        for(int j=0;j<4;j++) {
          if(emp[j].sal < emp[j+1].sal) {
            Employee temp = emp[j+1];
            emp[j+1] = emp[j];
            emp[j] = temp;
          }
        }
      }


  }

};


int main() {

  Employee obj;
  Employee emp[5];
  emp[0] = Employee("Santhosh",19,"SW",50000);
  emp[1] = Employee("Sid",29,"SW",45000);
  emp[2] = Employee("Mary",22,"HW",30000);
  emp[3] = Employee("John",39,"SW",20000);
  emp[4] = Employee("Christopher",25,"HW",10000);

  int i,bonus;
  for(i=0;i<5;i++) {
    cout<<"Input bonus for "<<emp[i].getName()<<"\n";
    cin>>bonus;
    emp[i].update(bonus);
    cout<<"Salary updated!\n Updated salary is "<<emp[i].getSal()<<"\n";
  }

  obj.sort(emp);
  cout<<emp[0].getName()<<" receives the highest salary\n";

}
