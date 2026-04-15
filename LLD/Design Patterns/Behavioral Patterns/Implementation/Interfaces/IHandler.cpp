#include "./../ConcreteModels/Request.hpp"

class IHandler{
    public:
    virtual void execute(Request &) = 0;
};