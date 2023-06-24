#include "ExchangeRates.h"

#include <iostream>

#include "libs/rapidjson/include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

// Constructor
ExchangeRates::ExchangeRates(long timestamp, const string& baseCode, bool success, const string& date,
                             const map<string, double>& rates)
    : timestamp(timestamp), baseCode(baseCode), success(success), date(date), rates(rates) {}

// Parse exchange rates from JSON
ExchangeRates ExchangeRates::parseExchangeRates(const string& jsonString) {
    Document document;
    document.Parse(jsonString.c_str());

    long timestamp = document["time_last_update_unix"].GetInt64();
    string baseCode = document["base_code"].GetString();
    bool success = document["result"] == "success";
    string date = document["time_last_update_utc"].GetString();

    const Value& ratesObj = document["rates"];
    map<string, double> rates;
    for (Value::ConstMemberIterator it = ratesObj.MemberBegin(); it != ratesObj.MemberEnd(); ++it) {
        string currency = it->name.GetString();
        double rate = it->value.GetDouble();
        rates[currency] = rate;
    }

    return ExchangeRates(timestamp, baseCode, success, date, rates);
}

// Print exchange rates
void ExchangeRates::printExchangeRates() const {
    cout << "Timestamp: " << timestamp << endl;
    cout << "Base: " << baseCode << endl;
    cout << "Success: " << boolalpha << success << endl;
    cout << "Date: " << date << endl;
    cout << "Rates:" << endl;
    int i = 0;
    for (const auto& pair : rates) {
        cout << pair.first << ": " << pair.second << endl;
        if (++i == 20)
            break;
    }
}
