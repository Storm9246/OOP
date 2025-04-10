/* Envision creating a robust application for a global finance firm that needs to handle and compute multiple currencies with real-time conversion capabilities.
This system is built on a base class called Currency, which contains core data members such as amount, currencyCode, currencySymbol, and an optional exchangeRate.
It provides functions like convertToBase() for converting the amount into a common base currency, convertTo(targetCurrency) for converting between currencies, and
displayCurrency() for showcasing currency details.

Derived classes like Dollar, Euro, and Rupee extend this foundation by introducing currency-specific details and overriding convertToBase() and displayCurrency() to
reflect the exchange rates and regional currency formats dynamically. */

#include <iostream>
using namespace std;

class Currency{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double a, string code, string symbol, double rate = 0.10) : amount(a), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual void convertToBase() = 0;
    virtual double convertTo(Currency &targetCurrency) = 0;
    virtual void displayCurrency() = 0;

    double getExchangeRate() const { return exchangeRate; }
    string getCurrencySymbol() const { return currencySymbol; }
};

class Dollar : public Currency{
public:
    Dollar(double a, double rate = 1.0) : Currency(a, "USD", "$", rate) {}

    void convertToBase() override {
        amount /= exchangeRate;
    }

    double convertTo(Currency &targetCurrency) override {
        double baseAmount = amount / exchangeRate;
        return baseAmount * targetCurrency.getExchangeRate();
    }

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double a, double rate = 0.92) : Currency(a, "EUR", "€", rate) {}

    void convertToBase() override {
        amount /= exchangeRate;
    }

    double convertTo(Currency &targetCurrency) override {
        double baseAmount = amount / exchangeRate;
        return baseAmount * targetCurrency.getExchangeRate();
    }

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double a, double rate = 278.50) : Currency(a, "PKR", "Rs", rate) {}

    void convertToBase() override {
        amount /= exchangeRate;
    }

    double convertTo(Currency &targetCurrency) override {
        double baseAmount = amount / exchangeRate;
        return baseAmount * targetCurrency.getExchangeRate();
    }

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

int main(){
    Currency *currencies[3];
    currencies[0] = new Dollar(200);
    currencies[1] = new Euro(500);
    currencies[2] = new Rupee(1000);

    for (int i = 0; i < 3; i++) {
        double convertedAmount;
        int j;
        if (i < 2) {
            convertedAmount = currencies[i]->convertTo(*currencies[i + 1]);
            j = i + 1;
        } else {
            convertedAmount = currencies[i]->convertTo(*currencies[0]);
            j = 0;
        }

        currencies[i]->displayCurrency();
        cout << "Converted amount: " << currencies[j]->getCurrencySymbol() << convertedAmount << endl;
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete currencies[i];
    }
    return 0;
}
