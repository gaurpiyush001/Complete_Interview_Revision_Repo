#ifndef QUACKSOUND_H
#define QUACKSOUND_H
/* code */

#include <iostream>
#include "./../../../Interfaces/Behavor/QuackBehavor.h"
using namespace std;

class QuackSound: public QuackBehavor {

    public:
    QuackSound() {}

    void quack() {
        cout << " My Duckmakes quack sound " << endl; 
    }

};

#endif // FLYWITHWING_H
