#include <iostream>
using namespace std;

//NOTE********
//UNTIL AND unless it is realy required you should not go for friend function or classes as it follows against the encpsulation principle

class Base{

    private:
    int x;
    public:
    Base(int a): x(a) {}

    //Compiler don't bother whether your friend exist or not
    //private: ghnta kuch faraq nhi pdega friend ko private krke
    friend class getSet;//declaring class as our friend
};

class getSet{
    public:
    void set(Base& obj, int x) { obj.x = x;}
    int get(Base& obj) { return obj.x; }
};


int main()
{
    Base obj(10);
    getSet gs;

    cout << gs.get(obj) << endl;
    gs.set(obj, 20);
    cout << gs.get(obj) << endl;
    return 0;
}