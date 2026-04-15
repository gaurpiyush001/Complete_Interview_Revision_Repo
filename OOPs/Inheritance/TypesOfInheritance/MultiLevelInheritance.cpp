// MultiLevel Inheritance

class Animal
{

public:
    int age;

public:
    void speack()
    {
        cout << "Animal is Speaking" << endl;
    }
};

class Dog : public Animal
{
};

class Lebra : public Dog
{
};