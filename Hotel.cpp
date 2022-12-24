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
	cout << "Single rooms: 1 - 20" << endl;
	cout << "Double rooms: 21 - 40" << endl;
	cout << "4 people rooms: 41 - 60" << endl;
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
	cout << "Room number: ";
	cin >> r;
	
	while (check(r) == 1)
	{
		cout << "Sorry, room has been booked." << endl;
		cout << "Please choose another room." << endl;
		cout << "Room number: ";
		cin >> r;
	}
	
	roomnum = r;
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
	cout << "Rent hours: ";
	cin >> hour;
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
	cout << "Date: " << date << endl;
	//cout << "Room type: ";
	/*switch (roomtype)
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
	}	*/
	
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
	cout << "Room no.\tName\t\tID number\tPhone number\tDate\t\tHours\tPrice\n\n";
	
	while (!B.eof()) {
		
			B.read((char*)this, sizeof(Hotel));

			cout << roomnum << "\t\t" << name << "\t\t" << id << "\t\t" << phonenum << "\t\t" << date << "\t\t";
			/*switch (roomtype)
			{
			case 1:
				cout << "single\t\t";
				break;
			case 2:
				cout << "double\t\t";
				break;
			default:
				cout << "4 people\t\t";
				break;
			}*/
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


