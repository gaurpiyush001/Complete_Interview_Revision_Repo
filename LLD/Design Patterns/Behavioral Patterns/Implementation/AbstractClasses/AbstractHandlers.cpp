#include "./../Interfaces/IHandler.h"
#include "./../ConcreteModels/Request.hpp"

class AbstractHandlers: public IHandler{
    private: 
    const IHandler* next;

    public: 
    AbstractHandlers() {}
    AbstractHandlers(IHandler* nextt): next{nextt} {}

    virtual void execute(Request &) = 0;

    bool isCheckNext(IHandler* h){
        if(h->next == NULL){
            return false
            
            ;
        }
        return true;
    }
};
