#pragma once
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize(); // допоміжна функція

public:
    Time();
    Time(int h, int m, int s);
    Time(const string& str); // ініціалізація рядком "12:30:59"
    Time(int totalSeconds);  // ініціалізація секундами
    Time(const Time& t);

    void Init(int h, int m, int s);
    void Read();
    void Display() const;
    string toString() const;

    int toSeconds() const;
    int toMinutes() const;

    void addSeconds(int sec);
    void subtractSeconds(int sec);
    int differenceInSeconds(const Time& t) const;

    // ---- ПЕРЕВАНТАЖЕННЯ ----
    Time operator+(int sec) const;          // додавання секунд
    Time operator-(int sec) const;          // віднімання секунд
    int operator-(const Time& t) const;     // різниця між двома часами
    bool operator==(const Time& t) const;
    bool operator<(const Time& t) const;
    bool operator>(const Time& t) const;

    friend ostream& operator<<(ostream& out, const Time& t);
};
