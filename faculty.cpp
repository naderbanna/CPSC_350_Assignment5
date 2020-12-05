#include "faculty.h"
#include <iostream>

using namespace std;

faculty::faculty(){
  facultyID = 0;
  name = "";
  department = "";
}

faculty::faculty(int id, string n, string d){
  facultyID = id;
  name = n;
  department = d;
}

faculty::~faculty(){

}

int faculty::getID() const{
  return facultyID;
}

string faculty::getName() const{
  return name;
}

string faculty::getDep() const{
  return department;
}

void faculty::addAdvisee(int sID){
  adviseeIDs->insertFront(sID);
  cout  << "advisee added to faculty" << endl;
}

void faculty::removeAdvisee(int sID){
  adviseeIDs->deleteItem(sID);
  cout  << "advisee removed from faculty" << endl;
}

void faculty::printAdvisees(){
  cout  << "List of advisees" << endl;
  adviseeIDs->printList();
}

bool faculty::operator==(const faculty& f){
  faculty f1 = *this;
  faculty f2 = f;

  return f1.getID() == f2.getID();
}

bool faculty::operator<(const faculty& f){
  faculty f1 = *this;
  faculty f2 = f;

  return f1.getID() < f2.getID();
}

bool faculty::operator>(const faculty& f){
  faculty f1 = *this;
  faculty f2 = f;

  return f1.getID() > f2.getID();
}

bool faculty::operator!=(const faculty& s){
  faculty s1 = *this;
  faculty s2 = s;
  return s1.getID() != s2.getID();
}
std::ostream& operator<<(std::ostream& os, const faculty& f){
  os << f;
  //os = s.getID();
  return os;
}

void faculty::print(){
  cout << "ID: " << facultyID << endl;
  cout << "Name: " << name << endl;
  cout << "Department: " << department << endl;
}
