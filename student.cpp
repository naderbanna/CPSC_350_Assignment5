#include "student.h"
#include <iostream>
#include <ostream>

using namespace std;

student::student(){
  studentID = 12;
  name = "NULL";
  level = "NULL";
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

int student::getID() const{
  return studentID;
}

string student::getName() const{
  return name;
}

string student::getLevel() const{
  return level;
}

int student::getAdvisor() const{
  return advisor;
}

bool student::operator==(const student& s){
  student s1 = *this;
  student s2 = s;
  return s1.getID() == s2.getID();
}

bool student::operator<(const student& s){
  student s1 = *this;
  student s2 = s;
  return s1.getID() < s2.getID();
}

bool student::operator>(const student& s){
  student s1 = *this;
  student s2 = s;
  return s1.getID() > s2.getID();
}

bool student::operator!=(const student& s){
  student s1 = *this;
  student s2 = s;
  return s1.getID() != s2.getID();
}


std::ostream& operator<<(std::ostream& os, const student& s){
  os << s.getID();
  //os = s.getID();
  return os;
}



void student::print(){

  cout << "ID: " << studentID << endl;
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Advisor: " << advisor << endl;
}
