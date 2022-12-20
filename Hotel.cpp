#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "hotel.h"

using namespace std;

Hotel::Hotel()
{
	id = 0;
	roomnum = 0;
	hour = 0;
	price = 0;
	roomtype = 0;
	phonenum = 0;
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
	cout << "Phone number: ";
	cin >> phonenum;
	cout << "Date: ";
	cin.ignore();
	getline(std::cin, date);
	cout << "List of rooms: " << endl;
	switch (roomtype)
	{
	case 1:
		cout << "single: 1 - 20" << endl;
		break;
	case 2:
		cout << "double: 21 - 40 " << endl;
		break;
	default:
		cout << "4 people: 41 - 60 " << endl;
		break;
	}
	cout << "Room number: ";
	cin >> roomnum;
	cout << "Rent hours: ";
	cin >> hour;
	pricecalc();
	save();
	cout << endl;
	cout << "Press any key to continue" << endl;
	_getch();
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
	cout << "Phone number: " << phonenum << endl;
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
	cout << endl;
	cout << "Press any key to continue" << endl;
	_getch();
	cout << endl;
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
	H.write((char*)this, sizeof(Hotel));
	H.close();
}

void Hotel::display()
{
	ifstream B;
	B.open("Hotel.txt", ios::in);
	
	while (!B.eof()) {
		B.read((char*)this, sizeof(Hotel));
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
	cout << endl;
	cout << "Press any key to continue" << endl;
	_getch();
	cout << endl;
	B.close();
}

void Hotel::rooms()
{
	cout << "List of rooms allocated:" << endl;
	ifstream B;
	B.open("Hotel.txt", ios::in);

	while (!B.eof()) {
		B.read((char*)this, sizeof(Hotel));
		cout << roomnum << " , ";
	}
	cout << endl;
	cout << "Press any key to continue" << endl;
	_getch();
	cout << endl;
	B.close();
}


