#ifndef CURRENTCONDITIONDISPLAY_H
#define CURRENTCONDITIONDISPLAY_H
/* code */

#include<iostream>
#include"../../Interfaces/Display.h"
#include"../../Interfaces/Observer.h"
#include"../Subject/WeatherData.h"
using namespace std;

class CurrentConditionDisplay: public Observer, public Display{
    private:
    float temp;
    float humidity;
    float pressure;
    WeatherData* weatherData;

    public:
    CurrentConditionDisplay(WeatherData* weatherData) {
        this->weatherData = weatherData;// This constructor accept the weatherData class, in order to facilitate register and removal request from observer
        (this->weatherData)->registerObserver(this);
    }

    void display() override {
        cout << " In CurrentConditionDisplay " << endl; 
    }

    // this is a push model, notifying every property to each observer
    // void update(float temp, float humidity, float pressure) override {
    // this is a pull model
    void update() override {
        this->temp = (this->weatherData)->getTemperature();
        this->humidity = (this->weatherData)->getHumidity();
        this->pressure = (this->weatherData)->getPressure();
        cout << " CurrentConditionDisplay Observer notified and updated " << endl;
        this->display(); // Is Update method is the BEST WAY TO CALL DISPLAY ?
    }

};

#endif ///*define*/
