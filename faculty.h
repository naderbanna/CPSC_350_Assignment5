#include <string>

class faculty{
  private:
    int facultyID;
    std::string name;
    std::string department;

  public:
    faculty();
    faculty(int facultyID, std::string name, std::string department);
    ~faculty();

    int getID() const;
    std::string getName() const;
    std::string getDep() const;

    bool operator== (const faculty&);
    bool operator< (const faculty&);
    bool operator> (const faculty&);
    bool operator!= (const faculty&);

    friend std::ostream& operator<<(std::ostream&, const faculty&);

    void print();

};
