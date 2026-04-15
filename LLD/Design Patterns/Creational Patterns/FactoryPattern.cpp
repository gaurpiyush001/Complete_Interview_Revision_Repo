#include <bits/stdc++.h>
using namespace std;

// Create a tranportation agency ----> chll bhaiii lgadeyy aag, Yaad hai na Societe General GAND TODD DE BHENCHODAA
class Transportation
{
public:

    // pure virtual function
    virtual string doSomeThing() const = 0;

    // Virtual destructor (important for proper cleanup)
    virtual ~Transportation() {}
};

// ConcreteProduct Class1
class SeaProduct : public Transportation
{

public:
    string doSomeThing() const override
    {
        return "Result after Sea Product creation from SeaLogisitics";
    }

};

// ConcreteProduct Class2
class AirProduct : public Transportation
{

public:
    string doSomeThing() const override
    {
        return "Result after Air Product Creation from AirLogisitics";
    }

};

// CreatorClass -: The Creator Class declares the Factory Method that is supposed to return an object of a Product Class. The Creator's Class subclasses usually provide implementation of this method
class Logistics
{
public:
    // Note that creator class may also provide some default implementation of the factory method
    virtual Transportation *FactoryMethod() const = 0;

    // Note, despite its name, product creation is not the primary responsibility of the creator. Usually, the creator class already has some core business logic related to products. The factory method helps to decouple this logic from the concrete product classes.
    string SomeBussinessLogic() const
    {
        // calling factory method to create
        Transportation *product = this->FactoryMethod();

        // now use the Product
        std::string result = "Creator: The same creator's code has just worked with " + product->doSomeThing();
        delete product;
        return result;
    }

    virtual ~Logistics(){};
};

// ConcreteCreator Class1
class SeaLogisitics : public Logistics
{

public:
    Transportation *FactoryMethod() const override
    {
        return new SeaProduct();
    }

};

// ConcreteCreator Class2
class AirLogistics : public Logistics
{
public:
    Transportation *FactoryMethod() const override
    {
        return new AirProduct();
    }
};

/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void
ClientCode(const Logistics &logistics)
{
    // ...
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << logistics.SomeBussinessLogic() << std::endl;
    // ...
}

int main()
{
    // Driver Code
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Logistics *creator1 = new SeaLogisitics();
    ClientCode(*creator1);
    std::cout << std::endl;
    std::cout << "App: Launched with the ConcreteCreator2.\n";
    Logistics *creator2 = new AirLogistics();
    ClientCode(*creator2);

    delete creator1;
    delete creator2;
    return 0;

    return 0;
}