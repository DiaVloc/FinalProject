#ifndef _HOTEL_
#define _HOTEL_

#include <string>
#include <iostream>
using namespace std;

class Hotel
{
private:	
	string name, date;
	int id, roomnum, hour, price, roomtype, phonenum;

public:
	Hotel();
	void checkin();	
	void display();
	void pricecalc();
	void print();
	void save();
	void rooms();
	//void modify();
	//void delete_rec();
	bool check(int& r);
};

#endif
