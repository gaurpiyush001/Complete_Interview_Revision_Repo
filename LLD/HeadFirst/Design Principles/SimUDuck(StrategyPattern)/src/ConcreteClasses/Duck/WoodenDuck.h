#ifndef WOODENDUCK_H
#define WOODENDUCK_H
/* code */
#include<iostream>
#include"./../../AbstractClasses/Duck/Duck.h"
#include"./../../Interfaces/Behavor/FlyBehavor.h"
#include"./../../Interfaces/Behavor/QuackBehavor.h"
#include"./../../Interfaces/Behavor/SwimBehavor.h"
using namespace std;

class WoodenDuck: public Duck {
    public:
    WoodenDuck(FlyBehavor* flyBehavor, QuackBehavor* quackBehavor, SwimBehavor* swimBehavor){
        // quackBehavor = new QuackSound();
        // flyBehavor = new FlyWithWing();
        this->flyBehavor = flyBehavor;
        this->quackBehavor = quackBehavor;
        this->swimBehavor = swimBehavor;
    }

    void display() override{
        cout << " I am a wooden duck " << endl;
    }

};

#endif // WOODENDUCK_H
