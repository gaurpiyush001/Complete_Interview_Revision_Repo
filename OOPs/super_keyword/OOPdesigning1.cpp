#include <iostream>
#include <string>
using namespace std;

class SchoolStudent
{

private:
    string name;
    int age;
    char gender;
    long idNum;
    double cgpa;

public:
    SchoolStudent() {}
    SchoolStudent(string name, int age, char gender, long idNum, double cgpa) : name{name}, age{age}, gender{gender}, idNum{idNum}, cgpa{cgpa} {}

public:
    string getName()
    {
        return this->name;
    }

    int getAge()
    {
        return this->age;
    }

    char getGender()
    {
        return this->gender;
    }

    long getId()
    {
        return this->idNum;
    }

    double getcgpa()
    {
        return this->cgpa;
    }

    // setters
    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setGender(char gen)
    {
        this->gender = gen;
    }

    void setId(long Id)
    {
        this->idNum = Id;
    }

    void setcgpa(long cgpa)
    {
        this->cgpa = cgpa;
    }
};

class CollegeStudent : public SchoolStudent
{

private:
    string major;
    int year;

public:
    CollegeStudent() : SchoolStudent() {}
    CollegeStudent(string name, int age, char gender, long idNum, double cgpa, int year, string major) : SchoolStudent(name, age, gender, idNum, cgpa)
    {
        setYear(year);
        setMajor(major);
    }

    // getterss
    string getMajor()
    {
        return this->major;
    }

    int getYear()
    {
        return this->year;
    }

    // setterss
    void setMajor(string major)
    {
        this->major = major;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    friend ostream &operator<<(ostream &, CollegeStudent &);
};

ostream &
operator<<(ostream &output, CollegeStudent &Obj)
{
    output << "ID: " << Obj.getId() << endl
           << "Name: " << Obj.getName() << endl
           << "Age: " << Obj.getAge() << endl
           << "Gender: " << Obj.getGender() << endl
           << "Major: " << Obj.getMajor() << endl
           << "CGPA: " << Obj.getcgpa() << endl
           << "Year: " << Obj.getYear() << endl;
    return output;
}

int main()
{
    CollegeStudent cg;

    string name;
    int age;
    char gender;
    long idNUm;
    double cgpa;
    int year;
    string major;

    cin >> name >> age >> gender >> idNUm >> major >> cgpa >> year;
    cg.setName(name);
    cg.setAge(age);
    cg.setGender(gender);
    cg.setId(idNUm);
    cg.setMajor(major);
    cg.setYear(year);

    cout << cg;
}