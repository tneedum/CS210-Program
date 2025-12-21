// CS-210 Project One - Chada Tech Clocks
// Developer: Tierra Needum
// Purpose: Display two clocks (12-hour and 24-hour) that update together.
// This program allows a user to add hours, minutes, or seconds to the clocks.

#include <iostream>
#include <string>
using namespace std;

// Clock class holds the current time and provides methods to update it
class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor initializes clock to 00:00:00
    Clock() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Adds one hour, wraps around at 24
    void addHour() {
        hours++;
        if (hours == 24) {
            hours = 0; 
        }
    }

    // Adds one minute, wraps around after 60
    void addMinute() {
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            addHour();
        }
    }

    // Adds one second, wraps after 60
    void addSecond() {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            addMinute();
        }
    }

    // Getters
    int getHour() const { return hours; }
    int getMinute() const { return minutes; }
    int getSecond() const { return seconds; }
};

// Formats numbers as two digits
string formatTime(int value) {
    return (value < 10 ? "0" : "") + to_string(value);
}

// Displays both 12-hour and 24-hour clocks
void displayClocks(const Clock& myClock) {
    int hour12 = myClock.getHour();
    string amPm = "AM";

    if (hour12 >= 12) {
        amPm = "PM";
    }
    if (hour12 == 0) {
        hour12 = 12;
    }
    else if (hour12 > 12) {
        hour12 -= 12;
    }

    cout << "**************************     **************************" << endl;
    cout << "*      12-Hour Clock      *     *      24-Hour Clock     *" << endl;

    cout << "*      "
         << formatTime(hour12) << ":"
         << formatTime(myClock.getMinute()) << ":"
         << formatTime(myClock.getSecond()) << " " << amPm
         << "      *     *        "
         << formatTime(myClock.getHour()) << ":"
         << formatTime(myClock.getMinute()) << ":"
         << formatTime(myClock.getSecond())
         << "        *" << endl;

    cout << "**************************     **************************" << endl << endl;
}

// Prints the user menu
void displayMenu() {
    cout << "**************************" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << "**************************" << endl;
}

// Main function
int main() {
    Clock myClock;
    int choice = 0;
    bool runProgram = true;

    while (runProgram) {
        displayClocks(myClock);
        displayMenu();

        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1) {
            myClock.addHour();
        }
        else if (choice == 2) {
            myClock.addMinute();
        }
        else if (choice == 3) {
           myClock.addSecond();
        }
        else if (choice == 4) {
            runProgram = false;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    cout << "Program exited." << endl;
    return 0;
}

