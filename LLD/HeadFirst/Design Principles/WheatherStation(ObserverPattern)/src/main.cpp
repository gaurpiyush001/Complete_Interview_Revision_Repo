#include<iostream>
#include"./ConcreteClasses/Subject/WeatherData.h"
#include"./ConcreteClasses/Observers/CurrentConditionDisplay.h"
#include"./ConcreteClasses/Observers/StatisticsDisplay.h"
#include"./ConcreteClasses/Observers/ForeCastDisplay.h"

using namespace std;

int main() {
    
    WeatherData* weatherData = new WeatherData();
    CurrentConditionDisplay* currentConditionDisplay = new CurrentConditionDisplay(weatherData); // passing subject class, in order to adopt the our system to handle request triggered from observer to subject
    StatisticsDisplay* statisticsDisplay = new StatisticsDisplay(weatherData);
    ForeCastDisplay* foreCastDisplay = new ForeCastDisplay(weatherData);

    weatherData->setMeasurements(60, 65, 30.4);// triggered changes to dependents as wel, via this function for changing measurements



    return 0;
}