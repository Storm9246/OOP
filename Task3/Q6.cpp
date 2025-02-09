/* Create a class called Smartphone with the following attributes:
  --> Company
  --> Model
  --> Display Resolution
  --> RAM
  --> ROM
  --> Storage
Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
1. Make a phone call
2. Send a message
3. Connect to the wifi
4. Browse the internet
Create different smartphone objects. Set their attributes using the setter functions and display their attributes after
using the getter functions to fetch the attributes. */

#include <iostream>
using namespace std;

class Smartphone
{
    string company;
    string model;
    string displayResolution;
    string RAM;
    string ROM;
    string storage;

public:
    void setCompany(string company)
    {
        this->company = company;
    }

    void setModel(string model)
    {
        this->model = model;
    }

    void setDisplayResolution(string displayResolution)
    {
        this->displayResolution = displayResolution;
    }

    void setRam(string RAM)
    {
        this->RAM = RAM;
    }

    void setRom(string ROM)
    {
        this->ROM = ROM;
    }

    void setStorage(string storage)
    {
        this->storage = storage;
    }

    string getCompany()
    {
        return company;
    }

    string getModel()
    {
        return model;
    }

    string getDisplayResolution()
    {
        return displayResolution;
    }

    string getRam()
    {
        return RAM;
    }

    string getRom()
    {
        return ROM;
    }

    string getStorage()
    {
        return storage;
    }

    void makePhoneCall()
    {
        cout << "Making a phone call..." << endl;
    }

    void sendMessage()
    {
        cout << "Sending a message..." << endl;
    }

    void connectToWifi()
    {
        cout << "Connecting to Wi-Fi..." << endl;
    }

    void browseInternet()
    {
        cout << "Browsing the internet..." << endl;
    }
};

int main()
{

    Smartphone smartphone1;
    smartphone1.setCompany("Apple");
    smartphone1.setModel("iPhone 14");
    smartphone1.setDisplayResolution("2532x1170");
    smartphone1.setRam("6GB");
    smartphone1.setRom("128GB");
    smartphone1.setStorage("128GB");

    Smartphone smartphone2;
    smartphone2.setCompany("Samsung");
    smartphone2.setModel("Galaxy S23");
    smartphone2.setDisplayResolution("2340x1080");
    smartphone2.setRam("8GB");
    smartphone2.setRom("256GB");
    smartphone2.setStorage("256GB");

    cout << "Smartphone 1 details: " << endl;
    cout << "Company: " << smartphone1.getCompany() << endl;
    cout << "Model: " << smartphone1.getModel() << endl;
    cout << "Display Resolution: " << smartphone1.getDisplayResolution() << endl;
    cout << "RAM: " << smartphone1.getRam() << endl;
    cout << "ROM: " << smartphone1.getRom() << endl;
    cout << "Storage: " << smartphone1.getStorage() << endl;

    cout << endl;
    cout << "Smartphone 2 details: " << endl;
    cout << "Company: " << smartphone2.getCompany() << endl;
    cout << "Model: " << smartphone2.getModel() << endl;
    cout << "Display Resolution: " << smartphone2.getDisplayResolution() << endl;
    cout << "RAM: " << smartphone2.getRam() << endl;
    cout << "ROM: " << smartphone2.getRom() << endl;
    cout << "Storage: " << smartphone2.getStorage() << endl;

    cout << endl;
    smartphone1.makePhoneCall();
    smartphone2.sendMessage();
    smartphone1.connectToWifi();
    smartphone2.browseInternet();
    return 0;
}
