#include <string>
#include <ostream>

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

    int getID() const;
    std::string getName() const;
    std::string getLevel() const;
    int getAdvisor() const;
    void setAdvisor(int a);

    bool operator== (const student&);
    bool operator< (const student&);
    bool operator> (const student&);
    bool operator!= (const student&);

    friend std::ostream& operator<<(std::ostream&, const student&);

    void print();
};


// student::student(){
//   studentID = 0;
//   name = "";
//   level = "";
//   advisor = 0;
// }
//
// student::student(int id, string n, string l, int a){
//   studentID = id;
//   name = n;
//   level = l;
//   advisor = a;
//   cout << "overloaded" << endl;
// }

// student::~student(){
//
// }

// int getID(){
//   return studentID;
// }
//
// string getName(){
//   return name;
// }
//
// string getLevel(){
//   return level;
// }
//
// int getAdvisor(){
//   return advisor;
// }
//
// void student::equality(int id){
//
// }
//
// void student::lessThan(int id){
//
// }
//
// void student::greaterThan(int id){
//
// }
//
// void student::print(){
//   cout << "ID: " << getID() << endl;
//   cout << "Name: " << getName() << endl;
//   cout << "Level: " << getLevel() << endl;
//   cout << "Advisor: " << getAdvisor() << endl;
// }
