#include <string>

class faculty{
  public:
    faculty();
    faculty(int facultyID, std::string name, std::string department);
    ~faculty();

    void equality(int id);
    void lessThan(int id);
    void greaterThan(int id);

  private:
    int facultyID;
    std::string name;
    std::string department;

};
