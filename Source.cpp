// Author: Edgar Ramirez Aburto
// Date: 11/11/2023
// This module 3 project displays clocks in 12hr and 24hr format and anlso gives users the ability
// to add an hour, minute, or sec to the clock.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// setting the global varaibles needed throught
int seconds;
int minutes;
int hours;
int choice;


string twoDigitString(unsigned int n) {
	//a function to change a single int to a string with a leading zero if not already a two digit int
	if (n >= 0 && n <= 9) {
		return "0" + to_string(n);
	}
	else if (n >= 10 && n <= 59) {
		return to_string(n);
	}
	else {
		return "NA";
	}
}

string nCharString(size_t n, char c) {
	// a function to return a string of c characters that is n characters long
	return string(n, c);

}

void printMenu(const char* strings[], unsigned int numStrings, unsigned char width) {
	// a function that takes in a array of char*, the number of items in the array and a width
	// with the peramiters the function will out put the items in the array as a list enclosed in a border
	cout << nCharString(width, '*') << endl;

	for (int i = 0; i < numStrings; ++i) {

		size_t spacesNeeded = width - 6 - to_string(i + 1).length() - strlen(strings[i]);
		cout << "* " << i + 1 << " - " << strings[i] << nCharString(spacesNeeded, ' ') << "*" << endl;


		if (i < numStrings - 1) {
			cout << endl;
		}
	}

	cout << nCharString(width, '*') << endl;

}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	// function to format the given time in 24 hour format and return as a string
	string hour = twoDigitString(h);
	string min = twoDigitString(m);
	string sec = twoDigitString(s);

	return hour + ":" + min + ":" + sec;

}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	// function to format the given time in 12 hour format followed by the 
	// respective am or pm 
	string AMPM;
	if (h == 0) {
		h = 12;
		AMPM = "A M";
	}
	else if (h < 12) {
		AMPM = "A M";
	}
	else {
		AMPM = "P M";
		if (h > 12) {
			h -= 12;
		}
	}

	string Hours = twoDigitString(h);
	string Min = twoDigitString(m);
	string Sec = twoDigitString(s);

	return Hours + ":" + Min + ":" + Sec + " " + AMPM;

}

unsigned int getMenuChoice(unsigned int maxChoice) {
	// this function takes the users input and validates it

	while (true) {
		cout << "Select (1-" << maxChoice << "): " << endl;
		cin >> choice;

		if (choice >= 1 && choice <= maxChoice) {
			break;
		}
	}
	return choice;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	// function to visually display the clock to the user
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	cout << "*      12-HOUR CLOCK      *   *      24-HOUR CLOCK      *" << endl;
	cout << endl;
	cout << "*      " << formatTime12(h, m, s) << nCharString(7, ' ') << "*   "
		<< "*        " << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

}

unsigned int getHour() {
	// the getter for hours
	return hours;
}

void setHour(unsigned int h) {
	// the setter for hours
	if (h >= 0 && h <= 23) {
		hours = h;
	}
	else {
		hours = 0;
	}
}


int addOneHour() {
	// function to update the clock by adding one hour
	int currentHour = getHour();

	// Check if the current hour is between 0 and 22 (inclusive)
	if (currentHour >= 0 && currentHour <= 22) {
		// Increment the hour by 1
		setHour(currentHour + 1);
	}
	else {
		// Reset the hour to 0
		setHour(0);
	}

	return hours;
}

unsigned int getMinute() {
	// the getter for minutes
	return minutes;
}

void setMinute(unsigned int m) {
	// the setter for minutes
	if (m >= 0 && m <= 59) {
		minutes = m;
	}
	else {
		minutes = 0;
	}
}

int addOneMinute() {
	// function to update the clock by adding one minute

	int currentMinute = getMinute();

	// Check if the current minute is between 0 and 58 (inclusive)
	if (currentMinute >= 0 && currentMinute <= 58) {
		// Increment the minute by 1
		setMinute(currentMinute + 1);
	}
	else {
		// Reset the minute to 0
		setMinute(0);

		// Call addOneHour to handle the carry-over to hours
		addOneHour();
	}
	return minutes;
}


unsigned int getSecond() {
	// the getter for seconds
	return seconds;
}

void setSecond(unsigned int s) {
	// the setter for seconds
	if (s >= 0 && s <= 59) {
		seconds = s;
	}
	else {
		seconds = 0;
	}
}

int addOneSecond() {
	// function to update the clock by adding one second

	int currentSecond = getSecond();

	// Check if the current second is between 0 and 58 (inclusive)
	if (currentSecond >= 0 && currentSecond <= 58) {
		// Increment the second by 1
		setSecond(currentSecond + 1);
	}
	else {
		// Reset the second to 0
		setSecond(0);

		// Call addOneMinute to handle the carry-over to minutes
		addOneMinute();
	}
	return minutes;
}


void mainMenu() {
	// this function handles the action to be taken according to the users input

	while (true) {
		choice = getMenuChoice(4);

		switch (choice) {

		case 1:
			addOneHour();
			displayClocks(hours, minutes, seconds);
			break;
		case 2:
			addOneMinute();
			displayClocks(hours, minutes, seconds);
			break;
		case 3:
			addOneSecond();
			displayClocks(hours, minutes, seconds);
			break;
		case 4:
			//exit condition
			return;
		default:
			cout << "Invalid" << endl;
			break;
		}

	}

}

void setTime() {
	//function to set the initial time from user input
	cout << "Enter hour: " << endl;
	cin >> hours;
	cout << "Enter minute: " << endl;
	cin >> minutes;
	cout << "Enter second: " << endl;
	cin >> seconds;
}

int main() {

	setTime();
	displayClocks(hours, minutes, seconds);

	do {
	
		const char* menuItem[] = { "Add Hour", "Add Minute", "Add Second", "quit" };
		printMenu(menuItem, 4, 57);
		mainMenu();
	
	} 
	while (choice != 4);
}