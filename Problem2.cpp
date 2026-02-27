#include <iostream>
#include <string>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    // Change format function
    string changeFormat() {        
        string period;
        int h = hours;

        if (h >= 12) {
            period = "PM";
        } else {
            period = "AM";
        }
    
        if (h == 0) {
            h = 12;  // 12 am to 12 pm
        } else if (h > 12) {
            h = h - 12;   // 1 pm to 11 pm
        }

        // Build the formatted string manually
        string hourStr = (h < 10)       ? "0" + to_string(h)       : to_string(h);
        string minStr  = (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);
        string secStr  = (seconds < 10) ? "0" + to_string(seconds) : to_string(seconds);

        return hourStr + ":" + minStr + ":" + secStr + " " + period;
    }  

    int convertToSeconds() {
        return (hours * 3600) + (minutes * 60) + seconds;
    }
};

int main() {
    Time t;

    cout << "Enter hours (0-23)  : ";
    cin >> t.hours;
    cout << "Enter minutes (0-59): ";
    cin >> t.minutes;
    cout << "Enter seconds (0-59): ";
    cin >> t.seconds;

    // Input validation
    if (t.hours < 0 || t.hours > 23 ||
        t.minutes < 0 || t.minutes > 59 ||
        t.seconds < 0 || t.seconds > 59) {
        cout << "Invalid time entered!" << endl;
        return 1;
    }

    cout << "\n--- Results ---" << endl;
    cout << "12-Hour Format : " << t.changeFormat()     << endl;
    cout << "Total Seconds  : " << t.convertToSeconds() << " seconds" << endl;

    return 0;
}