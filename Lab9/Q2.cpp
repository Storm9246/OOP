#include <iostream>

using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() const = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;

public:
    LightBulb() : isOn(false), brightness(100) {}

    void turnOn() override {
        isOn = true;
        cout << "LightBulb turned on." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "LightBulb turned off." << endl;
    }

    void getStatus() const override {
        cout << "LightBulb is " << (isOn ? "On" : "Off")
             << " | Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(22.0) {}

    void turnOn() override {
        isOn = true;
        cout << "Thermostat turned on." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "Thermostat turned off." << endl;
    }

    void getStatus() const override {
        cout << "Thermostat is " << (isOn ? "On" : "Off")
             << " | Temperature: " << temperature << "°C" << endl;
    }
};

int main() {
    SmartDevice* devices[2];

    devices[0] = new LightBulb();
    devices[1] = new Thermostat();

    for (int i = 0; i < 2; ++i) {
        devices[i]->turnOn();
        devices[i]->getStatus();
        cout << "-------------------\n";
        devices[i]->turnOff();
        devices[i]->getStatus();
        cout << "===================\n";
    }

    for (int i = 0; i < 2; ++i) {
        delete devices[i];
    }

    return 0;
}
