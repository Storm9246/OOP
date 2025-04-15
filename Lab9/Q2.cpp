#include <iostream>
#include <vector>
#include <memory>

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
    vector<shared_ptr<SmartDevice>> devices;

    devices.push_back(make_shared<LightBulb>());
    devices.push_back(make_shared<Thermostat>());

    for (auto& device : devices) {
        device->turnOn();
        device->getStatus();
        cout << "-------------------\n";
        device->turnOff();
        device->getStatus();
        cout << "===================\n";
    }

    return 0;
}
