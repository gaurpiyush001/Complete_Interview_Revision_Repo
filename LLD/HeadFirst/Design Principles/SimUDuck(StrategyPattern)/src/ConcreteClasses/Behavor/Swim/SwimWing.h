#ifndef SWIMWING_H
#define SWIMWING_H
/* code */

#include <iostream>
#include "./../../../Interfaces/Behavor/SwimBehavor.h"
using namespace std;

class SwimWing: public SwimBehavor {

    public:
    SwimWing() {}

    void swim() {
        cout << "Hi, I am swim duck behavor " << endl;
    }

};

#endif // SWIMWING_H
