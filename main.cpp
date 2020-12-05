#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
#include "faculty.h"
#include "bstTable.h"
//#include "faculty.h"

using namespace std;

int main(int argc, char** argv){

  bstTable<student> studentTable;
  bstTable<faculty> facultyTable;

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
      cout << "1. Printing all Students in Tree..." << endl << endl;
      studentTable.printEntireTree();
    }
    if(option == "2"){
      cout << "1. Printing all Faculty in Tree..." << endl << endl;
      facultyTable.printEntireTree();
    }
    if(option == "3"){
      int tempSID = 0;
      string name = "";
      string level = "";
      int advisor = 0;

      cout << "3. Please enter a student's ID to pull records" << endl;
      cin >> tempSID;

      student s(tempSID, name, level, advisor);
      studentTable.findNode(s)->print();
    }
    if(option == "4"){
      int tempFID = 0;
      string name = "";
      string department = "";

      cout << "4. Please enter a faculty's ID to pull records" << endl;
      cin >> tempFID;

      faculty f(tempFID, name, department);
      facultyTable.findNode(f)->print();
    }
    if(option == "5"){
      int tempSID = 0;
      string name = "";
      string level = "";
      int advisor = 0;
      string fname = "";
      string department = "";
      int tAdvisor = 0;

      cout << "5. Please enter a student's ID to print their Advisor's information" << endl;
      cin >> tempSID;

      student s(tempSID, name, level, advisor);
      tAdvisor = studentTable.findNode(s)->getAdvisor();
      faculty f(tAdvisor, fname, department);
      facultyTable.findNode(f)->print();

    }
    if(option == "6"){
      string fname = "";
      string department = "";
      int tempFID = 0;

      cout << "6. Please enter a faculty's ID to print their advisees" << endl;
      cin >> tempFID;

      faculty f(tempFID, fname, department);
      facultyTable.findNode(f)->printAdvisees();

    }
    if(option == "7"){
      //enter new student
      int id = 0;
      string name = "";
      string level = "";
      int advisor = 0;
      cout << "7. Please enter a student's ID to begin new entry" << endl;
      cin >> id;

      cout << "Name: " << endl;
      cin >> name;
      cout << "Level: " << endl;
      cin >> level;
      cout << "Faculty Advisor ID: " << endl;
      cin >> advisor;
      student s(id, name, level, advisor);

      studentTable.insertNode(s);
      cout << "Student Entered" << endl << endl;


    }
    if(option == "8"){
      int tempSID = 0;
      string name = "";
      string level = "";
      int advisor = 0;

      cout << "8. Please enter a student's ID to delete" << endl;
      cin >> tempSID;

      student s(tempSID, name, level, advisor);
      cout << studentTable.deleteNode(s) << endl;
    }
    if(option == "9"){
      //enter new faculty
      int fid = 0;
      string fname = "";
      string department = "";

      cout << "9. Please enter a faculty's ID to begin new entry" << endl;
      cin >> fid;
      cout << "Name: " << endl;
      cin >> fname;
      cout << "Faculty Advisor ID: " << endl;
      cin >> department;

      faculty f(fid, fname, department);
      facultyTable.insertNode(f);


    }
    if(option == "10"){
      int tempFID = 0;
      string name = "";
      string department = "";

      cout << "10. Please enter a faculty's ID to delete" << endl;
      cin >> tempFID;

      faculty f(tempFID, name, department);
      cout << facultyTable.deleteNode(f) << endl;

    }
    if(option == "11"){
      int tempSID = 0;
      string name = "";
      string level = "";
      int advisor = 0;

      int adID = 0;

      cout << "11. Please enter a student's ID to pull records" << endl;
      cin >> tempSID;
      cout << "Enter the advisor ID to update student advisor field" << endl;
      cin >> adID;

      student s(tempSID, name, level, advisor);
      studentTable.findNode(s)->setAdvisor(adID);

    }
    if(option == "12"){
      int tempFID = 0;
      string name = "";
      string department = "";
      int adID = 0;

      cout << "12. Enter a faculty ID to begin deleting an advisee" << endl;
      cin >> tempFID;
      cout << "Enter an advisee ID to delete" << endl;
      cin >> adID;

      faculty f(tempFID, name, department);
      facultyTable.findNode(f)->removeAdvisee(tempFID);


    }
    if(option == "13"){
      cout << "13. Rollback not functioning" << endl;

    }
    if(option == "14"){

      ofstream studentSave("studentTable.txt");
      studentTable.saveTree(NULL,studentSave);
      cout << "exited saveTree" << endl;
      studentSave.close();

      break;
    }


  }

  return 0;
};
