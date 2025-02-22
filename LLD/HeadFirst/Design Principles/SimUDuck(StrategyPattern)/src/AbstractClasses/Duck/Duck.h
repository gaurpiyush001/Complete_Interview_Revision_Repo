#ifndef DUCK_H
#define DUCK_H
/* code */

#include <iostream>
#include "./../../Interfaces/Behavor/FlyBehavor.h"
#include "./../../Interfaces/Behavor/QuackBehavor.h"
#include "./../../Interfaces/Behavor/SwimBehavor.h"

// Abtract Class
class Duck {
    protected:
    FlyBehavor* flyBehavor;
    QuackBehavor* quackBehavor;
    SwimBehavor* swimBehavor;
    public:
    virtual void display() = 0;
    void performQuack() {
        quackBehavor->quack();
    }
    void performFly() {
        cout << "Performing fly for: " << typeid(*this).name() << endl;
        cout << "Fly behavior type: " << typeid(*flyBehavor).name() << endl;

        // Perform fly action
        // flyBehavor->fly();
        flyBehavor->fly();
    }
    void performSwim() {
        swimBehavor->swim();
    }

    // Below are the dynamic setter of behavors on the go
    void setFlyBehavor(FlyBehavor* flyBehavor) {
        flyBehavor = flyBehavor;
    }
    void setQuackBehavor(QuackBehavor* quackBehavor) {
        quackBehavor = quackBehavor;
    }
};

#endif // DUCK_H

