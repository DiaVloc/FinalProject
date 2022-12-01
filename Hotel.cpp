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
	cin >> name;
	cout << "ID number: ";
	cin >> id;
	cout << "Room number: ";
	cin >> roomnum;
	cout << "Hours: ";
	cin >> hour;
}
void Hotel::print()
{
	cout << "Name: " << name << endl;
	cout << "ID number: " << id << endl;
	cout << "Room number: " << roomnum << endl;
	cout << "Hours: " << hour << endl;
	cout << "Price: " << price << endl;
}