#include <iostream>
#include <string>
#include "student.h"
#include "faculty.h"
#include "bstTable.h"
//#include "faculty.h"

using namespace std;

int main(int argc, char** argv){
  // int studentID = 7238;
  // string sName = "Nader";
  // string level = "Senior";
  // int advisor = 14039;

  // int facultyID;
  // string fName;
  // string department;

  // student sTest(studentID, sName, level, advisor);
  //student sTest;
  //sTest.print();


  bstTable<student> studentTable;
  bstTable<faculty> facultyTable;
  // student temp(studentID, sName, level, advisor);
  // studentTable.insertNode(temp);
  // studentTable.printEntireTree();
  //bstTable<faculty> facultyTable;

  // studentTable.insertNode(studentID);
  //studentTable.recPrint(sTest);


  //studentTable.printEntireTree();


  // bstTable<int> testInt;
  //
  // testInt.insertNode(12);
  // testInt.printEntireTree();

  cout << "Welcome to the student/faculty databse." << endl;

  while(true){
    string option = "";
    cout << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cin >> option;

    if(option == "1"){
      studentTable.printEntireTree();
    }
    if(option == "2"){
      facultyTable.printEntireTree();
    }
    if(option == "3"){
      int tempID = 0;
      cout << "3. Please enter a student's ID to pull records" << endl;
      cin >> tempID;


    }
    if(option == "4"){

    }
    if(option == "5"){

    }
    if(option == "6"){

    }
    if(option == "7"){
      //enter new student
      int id = 0;
      string name = "";
      string level = "";
      int advisor = 0;
      cout << "3. Please enter a student's ID to begin new entry" << endl;
      cin >> id;
      // cout << "Student ID: " << endl;
      // cin >> tempid;
      cout << "Name: " << endl;
      cin >> name;
      cout << "Level: " << endl;
      cin >> level;
      cout << "Faculty Advisor ID: " << endl;
      cin >> advisor;
      student s(id, name, level, advisor);
      s.print();
      studentTable.insertNode(s);
      cout << studentTable.searchNode(s) << endl;

    }
    if(option == "8"){

    }
    if(option == "9"){
      //enter new faculty
      int fid = 0;
      string fname = "";
      string department = 0;

      cout << "3. Please enter a faculty's ID to begin new entry" << endl;
      cin >> fid;
      cout << "Name: " << endl;
      cin >> fname;
      cout << "Faculty Advisor ID: " << endl;
      cin >> department;

      faculty f(fid, fname, department);
      f.print();
      facultyTable.insertNode(f);
      cout << facultyTable.searchNode(f) << endl;

    }
    if(option == "10"){

    }
    if(option == "11"){

    }
    if(option == "12"){

    }
    if(option == "13"){

    }
    if(option == "14"){
      break;
    }







  }




  return 0;
};
