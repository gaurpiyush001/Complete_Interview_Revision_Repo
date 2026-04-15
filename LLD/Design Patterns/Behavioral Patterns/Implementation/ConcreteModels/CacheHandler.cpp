#include "./../AbstractClasses/AbstractHandlers.hpp"
#include "./../ConcreteModels"

class AuthHandler: public AbstractHandlers{
    public:
    AuthHandler():AbstractHandlers() {}
    AuthHandler(Ihandler* next): AbstractHandlers(next) {}

    void execute(Request* r) override{
        cout << r->requestDATA << endl;
        cout << "===--===" << endl;
        cout << r->requestMETA << endl;

        //if this request is of my king:
        //else pass it to another next handler in chain: if next exists ? : else next not exists ?


    } 
};