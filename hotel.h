#ifndef _HOTEL_
#define _HOTEL_

#include <string>
#include <iostream>
using namespace std;

class Hotel
{
private:	
	string name;
	int id, roomnum, hour, price;

public:
	Hotel();
	void input();
	void pricecalc();
	void print();
};


#endif
