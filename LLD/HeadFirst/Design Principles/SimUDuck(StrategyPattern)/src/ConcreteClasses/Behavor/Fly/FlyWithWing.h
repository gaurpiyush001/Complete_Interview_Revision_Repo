#ifndef FLYWITHWING_H
#define FLYWITHWING_H
/* code */

#include <iostream>
#include "./../../../Interfaces/Behavor/FlyBehavor.h"
using namespace std;

class FlyWithWing: public FlyBehavor {

    public:
    FlyWithWing() {}

    void fly() {
        cout << "Hi, I am flying duck behavor " << endl;
    }

};

#endif // FLYWITHWING_H
