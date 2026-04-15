#ifndef WEATHER_H
#define WEATHER_H
/* code */
#include <iostream>
#include <bits/stdc++.h>
#include "../../Interfaces/Subject.h"
using namespace std;

class WeatherData: public Subject {
    private:
    unordered_set<Observer*> observers;
    float temp;
    float humidity;
    float pressure;

    public:
    WeatherData() {
        observers = {};
    }

    void registerObserver(Observer* observer) {
        (this->observers).insert(observer);
    }

    void removeObserver(Observer* observer) {
        (this->observers).erase(observer);
    }

    void notifyObserver() override {
        cout << " Notifying Observers via pull method || observers.size() = " << observers.size() << endl;
        for(auto observer: observers){
            // here we let notifies all the dependents of the state change of subject, we believe that all observers have implemeted this update function

            // THIS IS LIKE A PUSH MODEL, NO MATTER WHAT CHANGES ARE REQUIRED TO ACTUALLY NOTIFY TO A PARTICULAR OBSERVER, BUT WE SEND IT ALL, EVEN IF IT NOT REQUIRED TO AN OBSERVER
            // IN OUR CURENT DESIGN WE ARE PUSHING ALL THRE PIECES OF THE CLASS TO THE UPDATE METHOD IN DISPLAYS, EVEN IF DISPLAYS DONT NEED THESE VALUES, AND WHAT IS WE ADD ANOTHER PARAMETER TO UPDATE, THEN WE NEED TO GO CHANGE EVERY CLASS AND BASE INTERFACE TO ACCOMODATE NEW PARAMETER
            // (this->observer)->update(temp, humidity, pressure); 

            // i was thinking, would it generalize the code bit more if we allowed the displays to PULL THEIR DATA FROM THE WEATHER DATA OBJECT AS NEEDED ? 
            // SO WEATHER WE PUSH OR PULL THE DATA TO THE OBSERVER IS AN IMPLEMENTATION DETAIL BUT IN A LOT OF CASES IT MAKE SENSE TO LET OBSERVER RETRIEVE THE DATA THEY NEED RATHER THAN PASSING MORE AND MORE DATA TO THE THROUGH UPDATE
            // FOR THE PULL DESIGN, WE NEED TO MAKE SURE THE SUBJECT HAS GETTER METHODS FOR ITS DATA, THEN CHANGE OUR OBSERVERS TO USE THEM TO PULL THE DATA THEY NEED
            observer->update();

        }
    }

    void measurementChanged() {
        this->notifyObserver();
    }

    // below is dependency of implmentation not interface
    void setMeasurements(float temp, float humidity, float pressure) {
        this->temp = temp;
        this->humidity = humidity;
        this->pressure = pressure;
        cout << "=======Measurement changed ======== " << endl; 
        this->measurementChanged();
    }

    // Below are getters method for PULL Design in Observer Pattern
    float getTemperature() {
        return this->temp;
    }

    float getHumidity() {
        return this->humidity;
    }
     
    float getPressure() {
        return this->pressure;
    }

};
#endif ///*define*/
