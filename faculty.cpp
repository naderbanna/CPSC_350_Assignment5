#include "faculty.h"
#include <iostream>

using namespace std;

faculty::faculty(){
  facultyID = 0;
  name = "";
  department = "";
}

faculty::faculty(int facultyID, string name, string department){
  facultyID = facultyID;
  name = name;
  department = department;
}

faculty::~faculty(){

}


void faculty::equality(int id){

}

void faculty::lessThan(int id){

}

void faculty::greaterThan(int id){

}
