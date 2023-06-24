#include "util.h"

#include <string>
#include <vector>

using namespace std;

std::string createURL(const string& from) {
    std::string url = "https://exchangerate-api.p.rapidapi.com/rapid/latest/" + from;
    return url;
}