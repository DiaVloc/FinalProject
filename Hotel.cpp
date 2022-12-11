#include <iostream>
#include <string>
#include "hotel.h"

using namespace std;

Hotel::Hotel()
{
	id = 0;
	roomnum = 0;
	hour = 0;
	price = 0;
}
void Hotel::input()
{
	cout << "Name: ";
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
}
void Hotel::print()
{
	cout << "Name: " << name << endl;
	cout << "ID number: " << id << endl;
	cout << "Date: " << date << endl;
	cout << "Room number: " << roomnum << endl;
	cout << "Hours: " << hour << endl;
	cout << "Price: " << price << endl;
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