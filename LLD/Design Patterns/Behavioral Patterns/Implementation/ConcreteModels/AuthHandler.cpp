#include "./../AbstractClasses/AbstractHandlers.hpp"
#include "./../ConcreteModels"

class CacheHandler: public AbstractHandlers{
    public:
    CacheHandler(): AbstractHandlers() {}
    CacheHandler(Ihandler* next): AbstractHandlers(next) {}

    void execute(Request* r) override{
        cout << r->requestDATA << endl;
        cout << "===--===" << endl;
        cout << r->requestMETA << endl;

        if(r.requestDATA == ''){

        }
        else{
            AbstractHandler::next(r);
        }
    }
};