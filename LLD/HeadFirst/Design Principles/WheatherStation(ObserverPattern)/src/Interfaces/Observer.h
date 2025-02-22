#ifndef OBSERVER_H
#define OBSERVER_H
/* code */
#include <iostream>
using namespace std;

class Observer {
    public:
    // virtual void update(float&, float&, float&) = 0;// We are thinking already that passing the measurements directly to the observers was the most straightforward method of updating state. Do you think this is wise ?
    // This can be the area of application that might be changed in future. If it did change, would the change be well encapsulated or it may require changes in many parts of the code ?
    
    
    // PULLL DESIGN
    virtual void update() = 0;
};

#endif ///*define*/
