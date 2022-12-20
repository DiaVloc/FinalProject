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
	void checkout();
	void pricecalc();
	void print() const;
	void save() const;
};

#endif
