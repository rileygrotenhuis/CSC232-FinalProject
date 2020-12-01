#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include "stringToVector.h"
using namespace std;

string timeAndDate() {
    string timeAndDate;
    auto time = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(time);
    timeAndDate = ctime(&end_time);
    return timeAndDate;
}

string getTime() {
    /* Gets the time and date from the computer and put it into a vector, erases
    useless parts, turns the date into numbers and put into date vector.
    Returns the date vector.

    Contains: use of ctime and chrono, if and if else statements, vectors */

    string timeAndDate, strMonth, date;
    int month, day, year;

    // gets the date and time information from computer
    auto time = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(time);
    timeAndDate = std::ctime(&end_time);

    // puts that info into a vector using stringToVector
    vector <string> vectorTime = stringToVector(timeAndDate);

    // get rid of the useless parts
    vectorTime.erase(vectorTime.begin());
    vectorTime.erase(vectorTime.begin() + 2);

    // turns numbers into ints (except for strMonth)
    strMonth = vectorTime[0];
    day = stoi(vectorTime[1].substr(0, 2));
    year = stoi(vectorTime[2].substr(0, 4));

    // if statements determining the number value correlating to the month name
    string months[] =  { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
        "Aug", "Sep", "Oct", "Nov", "Dec" };

    for (int i = 0; i <= 12; i++) {
        if (strMonth == months[i]) {
            month = i + 1;
        }
    }

    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysPerMonthLeap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0 && year % 100 != 0) {
        while (month-- > 1) {
            day = day + daysPerMonthLeap[month - 1];
        }
    }

    else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
        while (month-- > 1) {
            day = day + daysPerMonthLeap[month - 1];
        }
    }

    else {
        while (month-- > 1) {
            day = day + daysPerMonth[month - 1];
        }
    }

    // puts the final info into date string
    date = to_string(day) + " " + to_string(year);

    return date;
}

vector <string> parseDate(string date){
    vector <string> vecDate;

    if (date.length() == 7){
        vecDate.push_back(date.substr(0, 3));
        vecDate.push_back(date.substr(3));
    }

    else if (date.length() == 6){
        vecDate.push_back(date.substr(0, 2));
        vecDate.push_back(date.substr(2));
    }

    else{
        vecDate.push_back(date.substr(0, 1));
        vecDate.push_back(date.substr(1));
    }
    return vecDate;
}
#endif