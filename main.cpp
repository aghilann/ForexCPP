#include <curl/curl.h>

#include <future>  // Add this
#include <iostream>
#include <string>
#include <vector>

#include "ExchangeRates.h"
#include "Graph.h"
#include "util.h"

using namespace std;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
    size_t totalSize = size * nmemb;
    out->append((char*)contents, totalSize);
    return totalSize;
}

std::string makeGetRequest(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "");
        headers = curl_slist_append(headers, "");

        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return readBuffer;
}

int main(void) {
    Graph graph;
    vector<string> countries{"USD", "EUR", "JPY"};
    vector<future<string>> futures;  // A vector to hold future objects

    for (const string& source : countries) {
        string url = createURL(source);

        // Spawn a new task to handle this request
        futures.push_back(async(launch::async, makeGetRequest, url));
    }

    // Wait for all requests to complete
    for (auto& future : futures) {
        string exchangeRates = future.get();

        ExchangeRates exchangeRatesObj = ExchangeRates::parseExchangeRates(exchangeRates);
        graph.addData(exchangeRatesObj);
    }

    graph.bellmanFord("USD");
}
