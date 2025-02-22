#ifndef SUBJECT_H
#define SUBJECT_H
/* code */
#include <iostream>
#include "./Observer.h"
using namespace std;

class Subject {
    public:
    virtual void registerObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObserver() = 0;
};

#endif ///*define*/
