Here's your reworked LinkedIn newsletter edition with a fun and interactive tone that keeps the reader engaged:  

---

# **Building a Weather Monitoring App Like a Pro 🌦️ | Low-Level Design | Observer Pattern**

Ever wondered **how weather apps update in real time**? Imagine you have a **weather data object** that fetches temperature, humidity, and pressure from a weather station. But wait—how does it notify multiple displays at once?  

Right now, we have **three types of displays**:  
✔️ **Current Conditions**  
✔️ **Forecast**  
✔️ **Statistics**  

💡 **The Problem?**   
Right now, our `WeatherData` object is **hardwired** to update these displays manually:  

```cpp
void measurementChanged() {
    float temp = getTemperature();
    float humidity = getHumidity();
    float pressure = getPressure();

    currentConditionDisplay.update(temp, humidity, pressure);
    statisticsDisplay.update(temp, humidity, pressure);
    forecastDisplay.update(temp, humidity, pressure);
}
```
🚨 **Major Issue:** What if we want to add **10 more displays** tomorrow? Do we keep updating this function manually? Sounds like a nightmare, right?  

Let’s make it **scalable**! Why not create a **marketplace** for displays where users can **subscribe** and **unsubscribe** anytime? 📢  

---

## **🔹 Inspiration: How Newspapers Work! 📰**
Think about **how newspapers and magazines deliver news**:  
1️⃣ You **subscribe** to a newspaper.  
2️⃣ The publisher **sends you a copy** every time there’s a new edition.  
3️⃣ If you **unsubscribe**, they stop sending you newspapers.  
4️⃣ Meanwhile, **other people** keep subscribing and unsubscribing all the time.  

💡 **This is exactly how the Observer Pattern works!**  
The **Weather Station** is our **publisher (Subject)**, and the **displays** are our **subscribers (Observers)**.

---

## **🔹 The Observer Pattern in Action 🎯**
### **Observer Pattern = Publisher + Subscriber**
> **Definition:** Observer Pattern defines a **one-to-many dependency** between objects.  
> When **one object (the Subject) changes**, **all dependent objects (Observers) are notified automatically**.

Instead of **hardcoding display updates**, we let **displays subscribe dynamically**.  
👉 Want to add **new displays**? Just subscribe!  
👉 Want to remove an **existing display**? Just unsubscribe!  

### **How do we implement this?**
We use **two interfaces**:
- `Subject` (Publisher)
- `Observer` (Subscriber)

#### **🔸 The Power of Loose Coupling 🔥**
Loosely coupled designs make our code **flexible, scalable, and maintainable**. Observer Pattern is a great example of this!  

Here’s why:  
✔️ The **Subject (WeatherData)** **doesn’t care** what kind of Observers exist. It just **notifies them**.  
✔️ Observers can **subscribe/unsubscribe anytime** without affecting other parts of the system.  
✔️ We can **add new types of Observers without modifying** existing code.  
✔️ If we need to **change how the WeatherData works**, we don’t have to touch the Observers.  

---

## **🔹 Push vs. Pull Model 🤔**
When **notifying observers**, we have two approaches:  
1️⃣ **Push Model:** The Subject sends **all** updated data to Observers.  
2️⃣ **Pull Model:** The Subject **only notifies the Observers**, and they fetch the data themselves.  

🧐 Which one to use?  
👉 **Push model** is good for simple updates.  
👉 **Pull model** is great when Observers need **specific** data instead of receiving everything.  

---

## **🔹 Design Principles in Observer Pattern 🎨**
When implementing Observer Pattern, keep these principles in mind:  
✅ **Encapsulate what varies** – Separate parts of code that may change frequently.  
✅ **Program to an interface, not an implementation** – Use interfaces (`Observer` & `Subject`) so you can easily extend functionality.  
✅ **Favor composition over inheritance** – Make objects **work together dynamically** rather than being tightly coupled.  

🚀 **Real-World Example:** Java’s **Swing Library** and **JavaBeans** use the Observer Pattern to handle UI updates dynamically!  

---

## **🔹 Ready to Code? 👨‍💻**
I’ve implemented **Observer Pattern in a Weather Station app** in C++! Check out the full implementation here:  
🔗 **GitHub Repo:** [Weather Station Observer Pattern](https://github.com/gaurpiyush001/Complete_Interview_Revision_Repo/tree/main/LLD/HeadFirst/Design%20Principles/WheatherStation(ObserverPattern)/src)  

---

### **🔹 Final Thoughts**  
By using **Observer Pattern**, we’ve transformed our **rigid weather monitoring app** into a **flexible, scalable, and maintainable system**. Next time you're designing a system that requires real-time updates to multiple components, consider using **this powerful pattern!** 💡  

💬 **Question for you:** Have you ever used the Observer Pattern in your projects? How did it work out? Let’s discuss in the comments! 👇




Coding Weahter Monitoring Application || Low Level Designing || Observer Pattern

We have a weather data object that gets data from a weather station (we only knwo that this object gets the data from weather station for change of any param, dont know how its is done) whenever the paramters of weahter like temp, humidity, pressure etc changes.
We need to adapt the Weather Data Object so that is knows how to update the display, Weather Data object should be capable and flexible enough to update / notify as many display which it wants. curently there are 3 different displays element - currentConditiondisplay , Forecast, Statistics

Key point of change in softaware - we know if the WeatherStation is successfull we will be having queries to integrate multipe, displys.
So why not create a marketplace of displays, allow users to add and remove as many display as they want 


Lets try first appraoch - 

void measuremetChanged () {
float temp = getTemperature(); // grabbing mot recent param changes
float humidity = getHumidity();
float pressure = getPressure();

currentConditionDisplay.update(temp, humidity, pressure); // updating each display by calling respetive update mthod
 statisticsDisplay.update(temp, humidity, pressure);
foreCastDisplay.update(temp, humidity, pressure);

}

Below coding style od updating display like this
[DISPLAY].update(temp, humidity, pressure); -> HERE WE ARE CODING TO CONCRETE IMPLEMENTATION, we have no way to add remove other display elemnts without making changes to code,  This is area of change in ur code, we need to encapsulate this

Stepping into observer pattern - 
BASICS - HOW NEWSPAPAER ANDD MAGAZINE SBSCRIPTION WORKS - 
- iF YOU SUBSCRIVBE TO A PARTICULAR NEWSPAPER publisher and every time there is a new edition it gets delivered to you. as long as there is a new edition , it gets delivered to you. As long as you remain a subscriber, you get a newspaper.
- once you unsubscribe you dont want papers anymore, and they stop being delivered
- while the publisher remains in business, people, hotels , airlines and other business constantly subscribe and unsubscrie to the newpaper

PUBLISHER + SUBSCRIBER = OBSERVER PATTERN (NEWSPAPER PIBLISHER - SUBJECT AND SUBSCRIBERS - OBSERVERS)
Observer Pattern - defines a one to many dependency between objects so that when one object changes state, all of its deoendents are notifiesd and updated automatically

there are few different ways to implement the observer pattern , but most revolve around a class design but includes Subject and Observer Interface

The power of loose coupling - (Strive for looselty coupled design between objects that interact)
When two objects are loosely coupled, they can interact, but they typically have very little knowledge of each other. As we are going to see, loosely coupled designs often gives us a lot of flexibility. Observer pattern is a great exmaple of loose coupling.

- First, the only thing the subject knows about an observer is that is implements a certain interface (the observer interface), no need to know about th concrete class of observer
- second, we can add/remove new observers at any time,  as long as the new observer has implemeted the (Observer Interface class), Infact we can replace any observer at runtime with another observers
- third, We never need to modify the subject to add new types of observers, only we need to make sure that observer interface is implemented by new concrete class.
- fourth, We can reuse subjects or observers independently of each other, bacause the 2 are not titghtly coupled
- fifth, changes to either the subject or an observer will not affet the other, because these 2 are loosely coupled , we are free to make changes to either, as long as the objects still meet their obligations to implement the subject or observer interfaces.

PULL VS PUSH MODEL IN OBSERVER INTERFACE - 
- now when notifying the observers whenever any of the state of subject changes, then there are 2 aprroach - 
1. subject could push all the changes to each observer in the notification
2. subject can just trigger the notification to each observer, and let the observer to itself know the state only required for each observer, (this could be implemented by having subject object in each observer and by that in concrete observer class we can call getters on subject to fetch subject changes)

Your task identify the aspects of your application where you can use below deisgn principles in Obserer pattern implementation
- Identify the aspects of your application that may vary aand separate them from what stays the same
- Program to an interface not implementation
- Favor composition over inheritance

Below is the actual impementation of observer pattern with weather station monitoring application in c++ - https://github.com/gaurpiyush001/Complete_Interview_Revision_Repo/tree/main/LLD/HeadFirst/Design%20Principles/WheatherStation(ObserverPattern)/src

ex - In Java Developement kit, both JavaBeans and Swing Libraries make use of observer pattern


