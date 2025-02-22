#ifndef FORECASTDISPLAY_H
#define FORECASTDISPLAY_H
/* code */

#include<iostream>
#include"../../Interfaces/Display.h"
#include"../../Interfaces/Observer.h"
#include"../Subject/WeatherData.h"
using namespace std;

class ForeCastDisplay: public Observer, public Display{
    private:
    float temp;
    float humidity;
    float pressure;
    WeatherData* weatherData;

    public:
    ForeCastDisplay(WeatherData* weatherData) {
        this->weatherData = weatherData;// This constructor accept the weatherData class, in order to facilitate register and removal request from observer
        (this->weatherData)->registerObserver(this);
    }

    void display() override {
        cout << " In ForeCastDisplay " << endl; 
    }

// this is a push model, notifying every property to each observer
    // void update(float temp, float humidity, float pressure) override {
        //     this->temp = temp;
    //     this->humidity = humidity;
    //     this->pressure = pressure;
    // below is a pull model
    void update() override {
        this->temp = (this->weatherData)->getTemperature();
        this->humidity = (this->weatherData)->getHumidity();
        this->pressure = (this->weatherData)->getPressure();
        cout << " ForeCastDisplay Observer notified and updated " << endl;
        this->display(); // Is Update method is the BEST WAY TO CALL DISPLAY METHOD ?
    }

};

#endif ///*define*/
