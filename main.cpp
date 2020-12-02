#include <iostream>
#include "student.h"
//#include "faculty.h"

using namespace std;

int main(int argc, char** argv){



  int studentID = 7238;
  string sName = "Nader";
  string level = "Senior";
  int advisor = 14039;

  int facultyID;
  string fName;
  string department;

  student sTest (studentID, sName, level, advisor);
  sTest.print();


  return 0;
};
