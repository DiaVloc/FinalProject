#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
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
	int r, booking;
	ofstream A("Hotel.txt", ios::app);
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
	cin >> r;
	booking = check(r);
	/*while (check(r) == 1)
	{
		cout << "Sorry, room has been booked." << endl;
		cout << "Please choose another room." << endl;
		cout << "Room number: ";
		cin >> r;
	}*/
	if (booking)
	{
		cout << "This room has been booked. Please choose another room." << endl;
	}
	else
	{
	roomnum = r;
	cout << "Rent hours: ";
	cin >> hour;
	pricecalc();
	//save();
	A.write((char*)this, sizeof(Hotel));
	cout << endl;
	cout << "Press any key to continue" << endl;
	_getch();
	A.close();
	}
}


void Hotel::print() 
{
	cout << "Bill of customer: " << endl;
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

/*void Hotel::save()
{
	ofstream H;
	H.open("Hotel.txt", ios::out | ios::app);
	H.write((char*)this, sizeof(Hotel));
	H.close();
}*/

void Hotel::record()
{
	ifstream B("Hotel.txt", ios::in);
	int r, record;
	cout << "CUSTOMER RECORDS" << endl << endl;
	cout << "Enter Room No.";
	cin >> r;
	while (!B.eof()) 
	{
		B.read((char*)this, sizeof(Hotel));
		if (roomnum == r) 
		{
			cout << "Room no.: " << roomnum;
			cout << "Name: " << name << endl;
			cout << "ID number: " << id << endl;
			cout << "Phone number: " << phonenum << endl;
			cout << "Date: " << date << endl;
			cout << "Room type: ";
			record = 1;
			break;
		}
		
		
	}
	if(record == 0)
		cout << "Room not found! Press any key to continue" << endl;
	_getch();
	B.close();
}

void Hotel::allocate()
{
	cout << "List of rooms allocated:" << endl;
	cout << "Room\t\tName\n\n";
	ifstream B;
	B.open("Hotel.txt", ios::in);

	while (!B.eof()) {
		B.read((char*)this, sizeof(Hotel));
		cout << roomnum << "\t\t" << name << "\n\n";

	}
	cout << endl;
	cout << "Press any key to continue" << endl;
	_getch();
	cout << endl;
	B.close();
}

int Hotel::check(int& r)
{
	int flag = 0;
	ifstream fin("Hotel.txt", ios::in);

	while (!fin.eof())
	{
		fin.read((char*)this, sizeof(Hotel));
		if (roomnum == r)
		{
			flag = 1;
			break;
		}
	}
	fin.close();
	return (flag);

}


