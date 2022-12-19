#include <iostream>
#include <string>
#include <fstream>
#include "hotel.h"

using namespace std;

Hotel::Hotel()
{
	id = 0;
	roomnum = 0;
	hour = 0;
	price = 0;
	roomtype = 0;
}

void Hotel::checkin() 
{
	cout << "Choose type of room: " << endl;
	cout << "1. single" << endl << "2. double" << endl << "3. 4 people" << endl;
	cout << "Enter option: ";
	cin >> roomtype;
	cout << "INFORMATION" << endl;
	cout << "Full Name: ";
	cin.ignore();
	getline(std::cin, name);
	cout << "ID number: ";
	cin >> id;
	cout << "Date: ";
	cin.ignore();
	getline(std::cin, date);
	cout << "Room number: ";
	cin >> roomnum;
	cout << "Hours: ";
	cin >> hour;
	pricecalc();
	cout << endl;
}

void Hotel::checkout()
{
	cout << "Full Name: ";
	cin.ignore();
	getline(std::cin, name);
	cout << "ID number: ";
	cin >> id;
}

void Hotel::print() const
{
	cout << "Name: " << name << endl;
	cout << "ID number: " << id << endl;
	cout << "Date: " << date << endl;
	cout << "Room type: ";
	switch (roomtype)
	{
	case 1:
		cout << "single " << endl;
		break;
	case 2:
		cout << "double " << endl;
		break;
	default:
		cout << "4 people " << endl;
		break;
	}
	cout << "Room number: " << roomnum << endl;
	cout << "Hours: " << hour << endl;
	cout << "Price: " << price << " VND" << endl << endl;
}

void Hotel::pricecalc() 
{
	if (hour <= 24)
		price = hour * 250000;
	else if (hour <= 48)
		price = 24 * 250000 + (hour - 24) * 200000;
	else
		price = 24 * 250000 + 24 * 200000 + (hour - 48) * 175000;
}

void Hotel::save() const
{
	ofstream H;
	H.open("Hotel.txt", ios::out | ios::app);
	H << "Name: " << name << endl;
	H << "ID number: " << id << endl;
	H << "Date: " << date << endl;
	H << "Room type: ";
	switch (roomtype)
	{
	case 1:
		H << "single " << endl;
		break;
	case 2:
		H << "double " << endl;
		break;
	default:
		H << "4 people " << endl;
		break;
	}
	H << "Room number: " << roomnum << endl;
	H << "Hours: " << hour << endl;
	H << "Price: " << price << " VND" << endl << endl;
	H.close();
}

