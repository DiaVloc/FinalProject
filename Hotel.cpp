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
	system("cls");
	int r, booking;
	ofstream A("Hotel.txt", ios::app);
	/*cout << "Choose type of room: " << endl;
	cout << "1. single" << endl << "2. double" << endl << "3. 4 people" << endl;
	cout << "Enter option: ";
	cin >> roomtype;
	while ((roomtype > 3) || (roomtype < 1))
	{
		cout << "Invalid input" << endl;
		cout << "Enter option: ";
		cin >> roomtype;
	}*/
	cout << "INFORMATION" << endl << endl;
	/*if (roomtype == 1)
	{
		cout << "Room type: Single" << endl;
	}
	else if (roomtype == 2)
	{
		cout << "Room type: Double" << endl;
	}
	else if (roomtype == 3)
	{
		cout << "Room type: 4 people" << endl;
	}
	*/
	cout << "List of rooms: " << endl;
	cout << "Standard rooms: 1 - 20" << endl;
	cout << "Deluxe rooms: 21 - 40" << endl;
	cout << "Royal rooms: 41 - 60" << endl;
	/*switch (roomtype)
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
	}*/
	cout << "\nRoom number: ";
	cin >> r;
	
	while ((r > 60) || (r < 1))
	{
		cout << "The entered room number is not correct, please try again!" << endl;
		cout << "Room number: ";
		cin >> r;
	}
	while (check(r) == 1)
	{
		cout << "Sorry, room has been booked." << endl;
		cout << "Please choose another room." << endl;
		cout << "Room number: ";
		cin >> r;
	}
	
	roomnum = r;
	if (roomnum <= 20)
		roomtype = 1;
	else if (roomnum <= 40)
		roomtype = 2;
	else
		roomtype = 3;
	cout << "Full Name: ";
	cin.ignore();
	getline(std::cin, name);
	cout << "ID number: ";
	cin >> id;
	cout << "Phone number: ";
	cin >> phonenum;
	cout << "Date (dd/mm/yyyy): ";
	cin.ignore();
	getline(std::cin, date);
	cout << "\nChoose your time booking for using rooms: " << endl;
	cout << "1. Less than 10 Hours [1 -> 9 hours]" << endl;
	cout << "2. Half of a day: 12 hours " << endl;
	cout << "3. One day: 24 hours" << endl;
	cout << "4. More than a day" << endl;
	int option;
	cout << "\nEnter your option:"; cin >> option;
	while ((option > 4) || (option < 0)) {
		cout << "The entered hours is not correct, please try again!" << endl;
		cout << "Enter your option: "; cin >> option;
	}
	switch (option) {
	case 1:
		
	there:
		
		cout << "Enter the hours using room: ";
		cin >> hour;
		cout << endl;
		if (hour > 9) {
			cout << "The entered hours is not correct, please try again!" << endl;
			goto there;
		}
		else
			break;

	case 2:
		hour = 12;
		break;

	case 3:
		hour = 24;
		break;

	case 4:
		
		int day;
		char xx;
		cout << "Enter days you want to use the room: ";
		cin >> day;
		cout << "Do you want to stay more in 12 hours!" << endl;
		cout << "Yes[y] or No[n]: "; cin >> xx;
		if (xx == 'y') {
			hour = 24 * day + 12;
			cout << hour << endl;
		}
		else {
			hour = 24 * day;
			cout << hour << endl;
		}
		
		break;
	}
	pricecalc();
	A.write((char*)this, sizeof(Hotel));
	cout << endl;
	cout << "Room is booked" << endl;
	cout << "Press any key to continue" << endl << endl;
	_getch();
	A.close();
	
}


void Hotel::print() 
{
	
	
	cout << "Room number: " << roomnum << endl;
	cout << "Name: " << name << endl;
	cout << "ID number: " << id << endl;
	cout << "Phone number: " << phonenum << endl;
	cout << "Date (dd/mm/yyyy): " << date << endl;
	cout << "Room type: ";
	switch (roomtype)
	{
	case 1:
		cout << "Standard " << endl;
		break;
	case 2:
		cout << "Deluxe " << endl;
		break;
	default:
		cout << "Royal " << endl;
		break;
	}	
	
	cout << "Hours: " << hour << endl;
	cout << "Price: " << price << " VND" << endl << endl;
	
}

void Hotel::pricecalc() 
{
	if (roomtype == 1) {
		if (hour <= 9)
			price = hour * 100000;
		else if (hour == 12)
			price = hour * 80000;
		else if (hour == 24)
			price = hour * 60000;
		else if (hour >= 24 && hour % 24 == 12)
			price = (hour - 12) * 60000 + 12 * 80000;
		else
			price = hour * 60000;
		
	}
	else if (roomtype == 2) {
		if (hour <= 9)
			price = hour * 200000;
		else if (hour == 12)
			price = hour * 160000;
		else if (hour == 24)
			price = hour * 145000;
		else if (hour >= 24 && hour % 24 == 12)
			price = (hour - 12) * 145000 + 12 * 160000;
		else
			price = hour * 145000;
		
	}
	else {
		if (hour <= 9)
			price = hour * 300000;
		else if (hour == 12)
			price = hour * 250000;
		else if (hour == 24)
			price = hour * 200000;
		else if (hour >= 24 && hour % 24 == 12)
			price = (hour - 12) * 200000 + 12 * 250000;
		else
			price = hour * 200000;
		
	}
}


void Hotel::record()
{
	system("cls");
	ifstream B("Hotel.txt", ios::in);
	int r, record = 0;
	cout << "CUSTOMER RECORDS" << endl << endl;
	cout << "Enter Room No.";
	cin >> r;
	cout << endl;
	while (!B.eof()) 
	{
		B.read((char*)this, sizeof(Hotel));
		if (roomnum == r) 
		{
			cout << "CUSTOMER DETAIL: " << endl << endl;			
			print();
			cout << "Press any key to continue" << endl << endl;
			record = 1;
			break;
		}
		
		
	}
	if(record == 0)
		cout << "Room not found! Press any key to continue" << endl << endl;
	_getch();
	B.close();
}

void Hotel::allocate()
{
	system("cls");
	ifstream B("Hotel.txt", ios::in);
	cout << "List of rooms allocated:" << endl;
	cout << "Room no.\tName\t\tID number\tPhone number\tDate\t\tRoomtype\tHours\t\tPrice\n\n";
	
	while (!B.eof()) {
		
			B.read((char*)this, sizeof(Hotel));

			cout << roomnum << "\t\t" << name << "\t\t" << id << "\t\t" << phonenum << "\t\t" << date << "\t\t";
			switch (roomtype)
			{
			case 1:
				cout << "Standard\t\t";
				break;
			case 2:
				cout << "Deluxe\t\t";
				break;
			default:
				cout << "Royal\t\t";
				break;
			}
			cout << hour << "\t\t" << price << " VND\n";

			cout << endl;
			B.peek();
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
		fin.peek();
	}
	fin.close();
	return (flag);

}

void Hotel::modify()
{

	long pos, flag = 0;
	int r;
	system("cls");
	fstream file("Hotel.txt", ios::in | ios::out );
	cout << "Enter Room No.";
	cin >> r;
	cout << endl;

	while (!file.eof())
	{

		pos = file.tellg();
		file.read((char*)this, sizeof(Hotel));

		if (roomnum == r)
		{

			cout << "Enter New Details" << endl;
			cout << "-----------------" << endl;
			cout << "Full Name: ";
			cin.ignore();
			getline(std::cin, name);			
			cout << "ID number: ";
			cin >> id;
			cout << "Phone no: ";
			cin >> phonenum;
			cout << "Date: ";
			cin.ignore();
			getline(std::cin, date);			
			cout << "Rent hours: ";
			cin >> hour;
			pricecalc();
			file.seekg(pos);
			file.write((char*)this, sizeof(Hotel));
			cout << "\n Record is modified....!!" << endl << endl;
			cout << "Press any key to continue" << endl << endl;
			flag = 1;
			break;

		}

	}

	if (flag == 0)
		cout << "Room not found! Press any key to continue" << endl << endl;
	_getch();
	file.close();

}

void Hotel::delete_rec()
{

	int r, flag = 0;
	char ch;
	system("cls");
	ifstream fin("Hotel.txt", ios::in);
	ofstream fout("temp.txt", ios::out);

	cout << "Enter Room No.";
	cin >> r;
	cout << endl;

	while (!fin.eof())
	{

		fin.read((char*)this, sizeof(Hotel));
		if (roomnum == r)

		{

			cout << "CUSTOMER DETAIL: " << endl << endl;		
			print();
			
			cout << "Do you want to delete this record(y/n): ";
			cin >> ch;

			if (ch == 'n') {
				fout.write((char*)this, sizeof(Hotel));
				cout << "Room deleted unsuccessfully! Press any key to continue" << endl;
			}
				else if (ch == 'y')
					cout << "Room deleted successfully! Press any key to continue" << endl;
				else {
				fout.write((char*)this, sizeof(Hotel));
				cout << "Invalid input" << endl;
				cout << "Room deleted unsuccessfully! Press any key to continue" << endl;
			}
			flag = 1;

		}

		else
			fout.write((char*)this, sizeof(Hotel));
		fin.peek();
	}

	fin.close();
	fout.close();

	if (flag == 0)
		cout << "Room not found! Press any key to continue" << endl;

	

	remove("Hotel.txt");
	rename("temp.txt", "Hotel.txt");

	_getch();

}


