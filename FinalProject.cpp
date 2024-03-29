#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "hotel.h"
using namespace std;

int main()
{
    int options = 0;
    Hotel A;
    while (options != 6) {
        
        system("cls");
        cout << "HOTEL ROOM BOOKING MANAGEMENT SYSTEM" << endl;
        cout << "Menu options:" << endl;
        cout << "1. Book a new room" << endl;
        cout << "2. Customer records" << endl;
        cout << "3. Rooms allocated" << endl;
        cout << "4. Modify record" << endl;
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
            break;
        }
        case 2:
        {
            A.record();
            break;
        }
        case 3:
        {
            A.allocate();
            break;
        }
        case 4:
        {
            A.modify();
            break;
        }
        case 5:
            A.delete_rec();
            break;
        case 6:
            break;
        default:
            cout << "Invalid input! " << endl;
            _getch();
            break;
        }
    }
}