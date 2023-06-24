#ifndef EXCHANGERATES_H
#define EXCHANGERATES_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class ExchangeRates {
   public:
    long timestamp;
    string baseCode;
    bool success;
    string date;
    map<string, double> rates;

    ExchangeRates() = default;
    ExchangeRates(long timestamp, const string& baseCode, bool success, const string& date, const map<string, double>& rates);

    static ExchangeRates parseExchangeRates(const string& jsonString);

    void printExchangeRates() const;
};

#endif  // EXCHANGERATES_H
