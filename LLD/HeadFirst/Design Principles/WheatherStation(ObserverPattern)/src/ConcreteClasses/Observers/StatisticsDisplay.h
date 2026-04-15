#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H
/* code */

#include<iostream>
#include"../../Interfaces/Display.h"
#include"../../Interfaces/Observer.h"
#include"../Subject/WeatherData.h"
using namespace std;

class StatisticsDisplay: public Observer, public Display{
    private:
    float temp;
    float humidity;
    float pressure;
    WeatherData* weatherData;

    public:
    StatisticsDisplay(WeatherData* weatherData) {
        this->weatherData = weatherData;// This constructor accept the weatherData class, in order to facilitate register and removal request from observer
        (this->weatherData)->registerObserver(this);
    }

    void display() override {
        cout << " In StatisticsDisplay " << endl; 
    }

    // void update(float temp, float humidity, float pressure) override {
                // this->temp = temp;
                // this->humidity = humidity;
                // this->pressure = pressure;

    void update() override {

        this->temp = (this->weatherData)->getTemperature();
        this->humidity = (this->weatherData)->getHumidity();
        this->pressure = (this->weatherData)->getPressure();
        cout << " StatisticsDisplay Observer notified and updated " << endl;
        this->display(); // Is Update method is the BEST WAY TO CALL DISPLAY METHOD ?
    }

};

#endif ///*define*/
