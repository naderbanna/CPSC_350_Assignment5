#include <string>
#include "linkedList.h"

class faculty{
  private:
    int facultyID;
    std::string name;
    std::string department;
    NaiveList<int> *adviseeIDs = new NaiveList<int>;


  public:
    faculty();
    faculty(int facultyID, std::string name, std::string department);
    ~faculty();

    int getID() const;
    std::string getName() const;
    std::string getDep() const;
    void addAdvisee(int sID);
    void removeAdvisee(int sID);
    void printAdvisees();

    bool operator== (const faculty&);
    bool operator< (const faculty&);
    bool operator> (const faculty&);
    bool operator!= (const faculty&);

    friend std::ostream& operator<<(std::ostream&, const faculty&);

    void print();

};
