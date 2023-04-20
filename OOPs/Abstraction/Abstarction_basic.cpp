//Abstraction ---> It is simply Implementation hiding, (hiding underlining details)
//---> Only showing Essentials Stuff
//ex-: ATM Machine, house wiring, email
//Advatage--: Security

//Access Modifiers are used to achieve ABSTRACTION

//Difference between Abstraction and Encapsulation??
//Diamond Problem??

// https://stackoverflow.com/questions/15176356/difference-between-encapsulation-and-abstraction


// Why can't abstract class be instantiated?
// Lets assume you are tasked to build houses in a housing community. You have been given a fixed plot size and interior layout are meant to be same for all the houses. Hence you come up with an "abstract" or basic blueprint map which contains all the basic requirements, but it leaves some design elements for each specialize house (based on buyer's preferences), lets say one of then is the choice of roof. If you "instantiate" a house based on abstract blueprint, it will be missing an important functionality - the roof. Hence you need to "inherit" the abstract blueprint and provide missing "roof" design and come up with a new "concrete" map. Only then you will be able to instantiate a complete house based on a complete blueprint of that house.