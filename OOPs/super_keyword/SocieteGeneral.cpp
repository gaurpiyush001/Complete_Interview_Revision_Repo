#include<bits/stdc++.h>
usingn namespace std;

class Main {
    
    public:
    string name;
    int age;
    char gender;
    long idNUm;
    double cgpa;
    int year;
    string major;
    
}

class SchoolStudent{
    
    private:
    string name;
    int age;
    char gender;
    long idNum;
    double cgpa;

    public:
    SchoolStudent(string name, int age, char gender, long idNum, double cgpa){
        setName(name);
        setAge(age);
        setGender(gender);
        setId(idNum);
        setcgpa(cgpa);
    }
    
    //getters
    public:
    int getName(){
        return this->name;
    }
    
    int getAge(){
        return this->age;
    }

    char getGender(){
        return this->gender;
    }

    long getId(){
        return this->idNum;
    }

    double getcgpa(){
        return this->cgpa;
    }


    // setters
    void setName(string name){
        this->name = name;
    }

    void setAge(int age){
        this->age = age;
    }

    void setGender(char gen){
        this->gender = gen;
    }

    void setId(long Id){
        this->idNum = id;
    }

    void setcgpa(long cgpa){
        this->cgpa = cgpa;
    }

    
}

class CollegeStudent: public SchoolStudent{
    
    private:
    string major;
    int year;
    
    public:
    CollegeStudent(string name, int age, char gender, long idNum, double cgpa, int year, string major): SchoolStudent(name, age, gender, idNum, cgpa){
        setYear(year);
        setMajor(major):
    }

    //getterss
    string getMajor(){
        return this->major;
    }

    int year(){
        return this->year;
    }
    

    //setterss
    void setMajor(string major){
        this->major = major;
    }
    
    void setYear(int year){
        this->year = year;
    }
    
}


int main(){



}