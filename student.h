#include <string>
#include <iostream>

using namespace std;

class student{

  private:
    int studentID;
    std::string name;
    std::string level;
    int advisor;

  public:
    student();
    student(int studentID, std::string name, std::string level, int advisor);
    //~student();

    int getID();
    std::string getName();
    std::string getLevel();
    int getAdvisor();

    void equality(int id);
    void lessThan(int id);
    void greaterThan(int id);

    void print();




};

student::student(){
  studentID = 0;
  name = "";
  level = "";
  advisor = 0;
}

student::student(int id, std::string n, std::string l, int a){
  studentID = id;
  name = n;
  level = l;
  advisor = a;
  cout << "overloaded" << endl;
}

// student::~student(){
//
// }

int getID(){
  return student.studentID;
}

string getName(){
  return name;
}

string getLevel(){
  return level;
}

int getAdvisor(){
  return advisor;
}

void student::equality(int id){

}

void student::lessThan(int id){

}

void student::greaterThan(int id){

}

void student::print(){
  cout << "ID: " << getID() << endl;
  cout << "Name: " << getName() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Advisor: " << getAdvisor() << endl;
}
