#ifndef PAPERDUCK_H
#define PAPERDUCK_H
/* code */
#include<iostream>
#include"./../../AbstractClasses/Duck/Duck.h"
#include"./../../Interfaces/Behavor/FlyBehavor.h"
#include"./../../Interfaces/Behavor/QuackBehavor.h"
#include"./../../Interfaces/Behavor/SwimBehavor.h"
using namespace std;

class PaperDuck: public Duck {
    public:
    PaperDuck(FlyBehavor* flyBehavor, QuackBehavor* quackBehavor, SwimBehavor* swimBehavor) {
        // AGAIN HERE WE ARE DEPENDING UPON IMPLEMENTATION OF CONRETE CLASSES, THIS CAN BE MADE MORE FLEXIBLE
        // quackBehavor = new QuackSound();
        // flyBehavor = new FlyWithWing();
        cout << " IN PAPER DUCK CONTRUCTOR " << endl;
        this->flyBehavor = flyBehavor;
        this->quackBehavor = quackBehavor;
        this->swimBehavor = swimBehavor;
    }

    void display() override{
        cout << " I am a paper duck " << endl;
    }
};

#endif // PAPERDUCK_H
