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
	void record();
	void pricecalc();
	void print();
	void save();
	void allocate();
	void modify();
	void delete_rec();
	int check(int& r);
};

#endif
