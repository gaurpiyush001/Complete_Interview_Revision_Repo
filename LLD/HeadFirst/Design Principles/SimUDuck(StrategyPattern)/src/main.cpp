#include <iostream>
#include "ConcreteClasses/Duck/PaperDuck.h"
#include "ConcreteClasses/Duck/RubberDuck.h"
#include "ConcreteClasses/Duck/WoodenDuck.h"
#include "ConcreteClasses/Behavor/Fly/FlyWithWing.h"
#include "ConcreteClasses/Behavor/Quack/QuackSound.h"
#include "ConcreteClasses/Behavor/Swim/SwimWing.h"

int main() {
    // Create behavior objects
    FlyBehavor* flyWithWings = new FlyWithWing();
    QuackBehavor* quackSound = new QuackSound();
    SwimBehavor* swimWithWings = new SwimWing();

    // Create duck objects with their respective behaviors
    Duck* paperDuck = new PaperDuck(flyWithWings, quackSound, swimWithWings);
    Duck* rubberDuck = new RubberDuck(flyWithWings, quackSound, swimWithWings);
    Duck* woodenDuck = new WoodenDuck(flyWithWings, quackSound, swimWithWings);

    // Simulate ducks
    std::cout << "Paper Duck:\n";
    paperDuck->performFly();
    paperDuck->performQuack();
    paperDuck->performSwim();

    std::cout << "\nRubber Duck:\n";
    rubberDuck->performFly();
    rubberDuck->performQuack();
    rubberDuck->performSwim();

    std::cout << "\nWooden Duck:\n";
    woodenDuck->performFly();
    woodenDuck->performQuack();
    woodenDuck->performSwim();

    // Cleanup
    delete paperDuck;
    delete rubberDuck;
    delete woodenDuck;
    delete flyWithWings;
    delete quackSound;
    delete swimWithWings;

    return 0;
}
