#ifndef _HOTEL_
#define _HOTEL_

#include <string>
#include <iostream>
using namespace std;

class Hotel
{
private:	
	string name, date;
	int id, roomnum, hour, price, roomtype;

public:
	Hotel();
	void input();
	void pricecalc();
	void print() const;
	void save() const;
};

#endif
