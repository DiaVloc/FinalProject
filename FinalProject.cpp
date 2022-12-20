#include <iostream>
#include <fstream>
#include <string>
#include "hotel.h"
using namespace std;

int main()
{
    int options = 0;
    Hotel A;
    while (options != 6) {
        cout << "HOTEL ROOM BOOKING MANAGEMENT SYSTEM" << endl;
        cout << "Menu options:" << endl;
        cout << "1. Check-In" << endl;
        cout << "2. Check-Out" << endl;
        cout << "3. Booking records" << endl;
        cout << "4. Rooms allocated" << endl;
        cout << "5. Delete record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter option: ";
        cin >> options;
        cout << endl;
        switch (options)
        {
        case 1:
        {
            A.checkin();
            A.print();                 
            break;
        }
        case 2:
        {
            A.checkout();
            break;
        }
        case 3:
        {
            A.display();
            break;
        }
        case 4:
        {
            A.rooms();
            break;
        }
        case 5:
            break;
        case 6:
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}