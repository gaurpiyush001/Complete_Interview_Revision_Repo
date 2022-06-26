//Polymorphism -: existing in many forms
//Poly means -> many
//morphism means -> forms

//----2 types of Polymorphism
//1.) Compile time or Static ----> further divided into 2 types
///(i) Method/function Overloading
///(ii) Operator Overloading 

//2.) Run time Or Dynamic ---> METHOD Overriding


////////-----METHOD overloading(same name multiple function can exist)----//////
class Math {

    public: 

    int add(int a, int b){
        return a+b; 
    }

/*
    int add(int a, int b){//ye error dega
        return  a+b;
    }
*/

    //Below are example of Method Overloading, by changing Signature_IMP_{But function ka return type change krney se nhi hoga ye achieve }
    //Overloading - number of parameters
    int add(int a, int b, int c){
        return  a+b+c;
    }
    //Overloading - type of parameters 
    int add(int a, float b){
        return a+b;
    }

};