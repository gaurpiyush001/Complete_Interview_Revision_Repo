#include <bits/stdc++.h>
using namespace std;
//LLD starts here, using bootom up approach

//there could be different types of parking spot, different types of parking spot, we could have compact parking spot, large parking spot

//two ways to represent different parking spots, (i) ENUM TYPES(this will violate open-closed principle), (ii)we define each different type of parking spot for each parking spot

// ParkingSpot class is an abstract class, we cannot instantiate an object from it
class ParkingSpot{
	protected:
	int id;
	bool availability;

	//getters and setters for above private data members should be there, for poerperly reflecting the encapsulation principle
	protected:
	ParkingSpot(int a, bool b):id{a},availability{b}{}

	friend ostream& operator<<(ostream&, ParkingSpot&);
	virtual void myParkingSpot() = 0;

	virtual ~ ParkingSpot(){}
};

class HandicappedParkingSpot: public ParkingSpot{

	public:
	HandicappedParkingSpot(int id, bool status):ParkingSpot(id, status) {}

	void myParkingSpot() override { 
		cout << "In Handicapped Parking Spot" << endl;
	}

};

//other are the different implemenetation of our abstarct class
// class CompactParkingSpot: public ParkingSpot{
	
// };
// class LargeParkingSpot: public ParkingSpot{
	
// };

ostream& operator<<(ostream& ou, ParkingSpot& obj){
	ou << obj.availability << " " << obj.id << " ";
	return ou; 
}

class ParkingTicket {

	private:
	int id;
	int parkingSpotId;
	ParkingSpot parkingSpot;
	string issueTime;
	string exitTime;
	double totalAmount;

	//getter and setters

}

//abstract class
class Terminal{

	protected:
	int id;

	public:
	virtual myTerminal() = 0;

}

// Abstract class
class EntranceTerminal: public Terminal{
	public:
	void myTerminal(Terminal& t){
		cout << t.id << " Entring Terminal " <<endl;
	}
	ParkingSpot getTicket(ParkingTicket&){};
}

//AbstractClass
class ExitTerminal: public Terminal{
	public:
	void myTerminal(Terminal& t){
		cout << t.id << " Exit Terminal " <<endl;
	}
	PaymentInfo payForParking(ParkingTicket&, Payment& paymentMode){};
}

//abstarct
class Payment{
	public:
	virtual PaymentInfo makePayment(Payment& )
}

class PaymentOnline: public Payment{

}

class CardPayment: public Payment{

}

class PaymentInfo {

	double amount;
	string paymentDate;
	int transactionId;
	ParkingTicket parkingTicket;
	PaymentStatus paymentStatus;

}

//abstract class
class ParkingAssignmentStrategy{
	public:
	virtual ParkingSpot (Terminal& ) = 0;
	virtual void releaseParkingSpot(ParkingSpot&) = 0;
};

//strategy design pattern
//now will extend ParkingSpotNearEntranceStartegy class, which will implement algorithm to figure out the nearest parking spot, and return that to the entering customer
class ParkingSpotNearEntranceStrategy: public ParkingAssignmentStrategy{
	//we will have as number of min-heaps as number of entrances
	set<ParkingSpot,CustomComparator> availableSpots;
	set<ParkingSpot,CustomComparator> reservedSpots;
	unordered_map<int,priority_queue<int,ParkingSpot>>
} 


struct CustomComparator {
    bool operator()(const ParkingSpot& a, const ParkingSpot& b) const {
        return a.id > b.id // Compare in ascending order
    }
};

struct CustomComparatorTerminal {
    bool operator()(const Terminal& a, const Terminal& b) const {
        return a.id > b.id // Compare in ascending order
    }
};

//abstract class
class TarrifCalculator{
	virtual double calculate(ParkingTicket& ticket, ParkingSpot& parkingsSpoType) = 0;
}

class TarrifCalculatorWeekdays: public TarrifCalculator{
	double calculate(ParkingTicket& ticket, ParkingSpot& parkingsSpoType) override{

	}
}


//Monitory system ---> Objserver design pattern
class Logger{
	virtual void logMessage() = 0;
}


class ParkingLot{

	private:
	ParkingLot(){}
	ParkingLot(ParkingLot&);
	ParkingLot operator=(ParkingLot&);

	static ParkingLot* instance;

	public:
	static ParkingLot* getInstance(){
		if(!instance){
			instance = new ParkingLot();
		}
		return instance;
	}

	int totalGates;
	int totalEntrances;
	int totalExits;
	vector<EntranceTerminal> entrancevec;
	vector<ExitTerminal> exitterminalvec;

	vector<ParkingSpot> spotsvec;

    ~ParkingLot() {
        delete instance;
    }

}

int main(){
	// ParkingSpot* obj = new HandicappedParkingSpot(2, true);
	// cout << *obj << endl;
	// obj->myParkingSpot();

	ParkingLot* pk = new ParkingLot();

	int n;
	cout<<"total gates" << endl;
	cin>>n;
	cout << "give numer of entrance gates" << endl;
	cin>> n;
	cout<<"give number of exit gates"<<endl;
	cin >> n;


}
