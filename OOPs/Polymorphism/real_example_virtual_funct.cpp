// What is the use? 
// Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without even knowing the kind of derived class object. 

// Real-Life Example to Understand the Implementation of Virtual Function
// Consider employee management software for an organization.
// Let the code has a simple base class Employee, the class contains virtual functions like raiseSalary(), transfer(), promote(), etc. Different types of employees like Managers, Engineers, etc., may have their own implementations of the virtual functions present in base class Employee. 

// In our complete software, we just need to pass a list of employees everywhere and call appropriate functions without even knowing the type of employee. For example, we can easily raise the salary of all employees by iterating through the list of employees. Every type of employee may have its own logic in its class, but we don’t need to worry about them because if raiseSalary() is present for a specific employee type, only that function would be called.

// C++ program to demonstrate how a virtual function
// is used in a real life scenario

class Employee {
public:
	virtual void raiseSalary()
	{
		// common raise salary code
	}

	virtual void promote()
	{
		// common promote code
	}
};

class Manager : public Employee {
	virtual void raiseSalary()
	{
		// Manager specific raise salary code, may contain
		// increment of manager specific incentives
	}

	virtual void promote()
	{
		// Manager specific promote
	}
};

// Similarly, there may be other types of employees

// We need a very simple function
// to increment the salary of all employees
// Note that emp[] is an array of pointers
// and actual pointed objects can
// be any type of employees.
// This function should ideally
// be in a class like Organization,
// we have made it global to keep things simple
void globalRaiseSalary(Employee* emp[], int n)
{
	for (int i = 0; i < n; i++) {
		// Polymorphic Call: Calls raiseSalary()
		// according to the actual object, not
		// according to the type of pointer
		emp[i]->raiseSalary();
	}
}


//How does the compiler perform runtime resolution?
// The compiler maintains two things to serve this purpose:

// vtable: A table of function pointers, maintained per class. 
// vptr: A pointer to vtable, maintained per object instance (see this for an example).

// The compiler adds additional code at two places to maintain and use vptr.

// 1. Code in every constructor. This code sets the vptr of the object being created. This code sets vptr to point to the vtable of the class. 

// 2. Code with polymorphic function call (e.g. bp->show() in above code). Wherever a polymorphic call is made, the compiler inserts code to first look for vptr using a base class pointer or reference (In the above example, since the pointed or referred object is of a derived type, vptr of a derived class is accessed). Once vptr is fetched, vtable of derived class can be accessed. Using vtable, the address of the derived class function show() is accessed and called.
