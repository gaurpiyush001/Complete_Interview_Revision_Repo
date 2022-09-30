#include <bits/stdc++.h>
using namespace std;

//Ye JAVA mein possible nhi hai, Because of Inheritance Ambiguity 
//--IMP--But in C++, it is possible by using Scope Resolution Operator
//obj.Maruti::solve()

//multiple inheritance -: when one child is inheheriting propeties and methods from multiple classes
/*ex-:
Father , Mother
     -
     |
     |
     |
   child
*/

class Maruti{
    public:
    string name;
};

class Suzuki {
    public: 
    int val;
};

//NOTE -: Before every parent class we need to specify the MODE otherwise it will be treated as PRIVATE
class Swift: public Maruti, public Suzuki {

};

int main() {

    Swift *miniCar = new Swift();
    miniCar->name = "RedSWwift";
    miniCar->val = 22;
    cout<< miniCar->name << endl;
    cout<< miniCar->val << endl;

    return 0;
}
