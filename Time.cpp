#include "Time.h"
#include <sstream>
#include <cmath>

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(const Time& t)
    : hours(t.hours), minutes(t.minutes), seconds(t.seconds) {
}

Time::Time(int totalSeconds) {
    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;
}

Time::Time(const string& str) {
    char c;
    stringstream ss(str);
    ss >> hours >> c >> minutes >> c >> seconds;
    normalize();
}

void Time::normalize() {
    int total = hours * 3600 + minutes * 60 + seconds;
    if (total < 0) total = 0;
    hours = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
}

void Time::Init(int h, int m, int s) {
    hours = h; minutes = m; seconds = s;
    normalize();
}

void Time::Read() {
    cout << "Введіть год, хв, сек: ";
    cin >> hours >> minutes >> seconds;
    normalize();
}

void Time::Display() const {
    cout << toString() << endl;
}

string Time::toString() const {
    return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}

int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

int Time::toMinutes() const {
    return round(toSeconds() / 60.0);
}

void Time::addSeconds(int sec) {
    *this = *this + sec;
}

void Time::subtractSeconds(int sec) {
    *this = *this - sec;
}

int Time::differenceInSeconds(const Time& t) const {
    return abs(toSeconds() - t.toSeconds());
}

// ---- ПЕРЕВАНТАЖЕННЯ ----

Time Time::operator+(int sec) const {
    return Time(toSeconds() + sec);
}

Time Time::operator-(int sec) const {
    return Time(toSeconds() - sec);
}

int Time::operator-(const Time& t) const {
    return abs(toSeconds() - t.toSeconds());
}

bool Time::operator==(const Time& t) const {
    return toSeconds() == t.toSeconds();
}

bool Time::operator<(const Time& t) const {
    return toSeconds() < t.toSeconds();
}

bool Time::operator>(const Time& t) const {
    return toSeconds() > t.toSeconds();
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.hours << ":" << t.minutes << ":" << t.seconds;
    return out;
}
